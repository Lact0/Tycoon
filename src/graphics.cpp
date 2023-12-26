#include "graphics.h"

using namespace Graphics;

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

bool Color::plot(SDL_Surface* screen, int x, int y) const {
    if(x < 0 || x >= screen->w || y < 0 || y >= screen->h) {return false;}
    int ind = (y * screen->pitch + x * screen->format->BytesPerPixel);
    char* pixels = (char*) screen->pixels;
    pixels[ind] = b;
    pixels[ind + 1] = g;
    pixels[ind + 2] = r;
    return true;
}

void Graphics::drawLine(SDL_Surface* screen, int x1, int x2, int y1, int y2) {

}