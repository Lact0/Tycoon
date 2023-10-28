#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <cmath>
#include "card.h"

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

    Card card(8, 4);

    while(running) {
        frameStart = SDL_GetTicks();

        while(SDL_PollEvent(&e) != 0) {
            switch(e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:

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

        SDL_LockSurface(screen);
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Update

        //Draw
        clearScreen();

        char* pixels = (char*) screen->pixels;

        card.draw(pixels, screen->pitch, screen->format->BytesPerPixel, x, y, 100);
        
        for(int i = 0; i < windowWidth; i++) {
            for(int j = 0; j < windowHeight; j++) {
                int ind = (j * screen->pitch + i * screen->format->BytesPerPixel);
            }
        }

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