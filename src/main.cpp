#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "card.h"
#include "vector.h"

using namespace std;

SDL_Window *window = nullptr;
SDL_Surface *screen = nullptr;

const int targetFPS = 60;
const int frameDelay = 1000 / targetFPS;

const int miniWindowWidth = 860;
const int miniWindowHeight = 520;
int windowWidth = 860;
int windowHeight = 540;
bool fullscreen = true;

void setFullscreen() {
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    screen = SDL_GetWindowSurface(window);
    fullscreen = true;
}

void setWindowed() {
    SDL_SetWindowFullscreen(window, 0);
    SDL_SetWindowSize(window, miniWindowWidth, miniWindowHeight);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
    screen = SDL_GetWindowSurface(window);
    fullscreen = false;
}

bool startup() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        return false;
    }

    window = SDL_CreateWindow("Test", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
            windowWidth, 
            windowHeight, 
            SDL_WINDOW_SHOWN);
    setFullscreen();
    return true;
}

void quit() {
    SDL_DestroyWindowSurface(window);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void clearScreen() {
    char* pixels = (char*) screen->pixels;
    for(int i = 0; i < windowWidth; i++) {
        for(int j = 0; j < windowHeight; j++) {
            int ind = (j * screen->pitch + i * screen->format->BytesPerPixel);
            pixels[ind] = 0;
            pixels[ind + 1] = 0;
            pixels[ind + 2] = 0;
        }
    }
}

int main(int argv, char** args) {

    if(!startup()) {
        return 1;
    }
    
    SDL_Event e;
    bool running = true;
    int frameStart, frameTime;

    vector<Vector*> ponts;
    Vector* hand = nullptr;

    while(running) {
        frameStart = SDL_GetTicks();

        int x, y;
        SDL_GetMouseState(&x, &y);
        Vector pm(vector{x, y});

        Card cards[14];
        for(int i = 0; i < 14; i++) {
            cards[i] = Card(i + 1, i % 4 + 1);
        }

        while(SDL_PollEvent(&e) != 0) {
            switch(e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(hand == nullptr) {
                        for(Vector* ptr : ponts) {
                            if((pm - *ptr).mag < 10) {
                                hand = ptr;
                            }
                        }
                    } else {
                        hand = nullptr;
                    }
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym) {
                        case SDLK_SPACE:
                            break;
                        case SDLK_F11:
                            if(fullscreen) {
                                setWindowed();
                            } else {
                                setFullscreen();
                            }
                    }
                    break;
            }
        }

        //Update
        if(hand != nullptr) {
            *hand = pm;
        }
        Vector windowSize(std::vector{windowWidth, windowHeight});

        //Draw
        SDL_LockSurface(screen);
        clearScreen();

        for(Vector* ptr: ponts) {
            Graphics::drawArc(screen, *ptr, 10, 0, 2 * 3.14159);
        }

        Vector d(vector{250, 500});
        Vector p(vector{windowWidth - d.vect[0], windowHeight - d.vect[1]});
        p /= 2;

        Vector cardSize(std::vector{windowWidth / 15, windowWidth / 15 / 5 * 7});
        for(int i = 0; i < 14; i++) {
            Card card = cards[i];
            Vector cardPos(std::vector{(double) (windowWidth * (i + 1) / 15 / 15 + windowWidth / 15 * i), windowHeight - cardSize.vect[1]});
            card.draw(
                screen,
                cardPos,
                cardSize
            );
        }

        Vector ld(std::vector{250, 250 / 5 * 7});
        Vector lp = (windowSize - ld) / 2;
        Graphics::drawRect(screen, lp, ld);
        TextGraphics::drawSpade(screen, lp, ld);

        SDL_UnlockSurface(screen);
        SDL_UpdateWindowSurface(window);
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    quit();
    return 0;
}