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

void Graphics::drawLine(SDL_Surface* screen, int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    
    for(;;) {
        WHITE.plot(screen, x0, y0);
        if(x0 == x1 && y0 == y1) {break;}
        int e2 = 2 * error;
        if(e2 >= dy) {
            if(x0 == x1) {break;}
            error = error + dy;
            x0 = x0 + sx;
        }
        if(e2 <= dx) {
            if(y0 == y1) {break;}
            error = error + dx;
            y0 = y0 + sy;
        }
    }
}