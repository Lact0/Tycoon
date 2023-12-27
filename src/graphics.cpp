#include "graphics.h"
#include <iostream>
#include <cmath>

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

QuadBezier::QuadBezier(int x0, int y0, int x1, int y1, int cx, int cy) {
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    this->cx = cx;
    this->cy = cy;
}

int* QuadBezier::getPoint(double t) {
    int* pos = new int[2];
    pos[0] = (x0 + x1 - 2 * cx) * t * t + (2 * cx - 2 * x0) * t + x0;
    pos[1] = (y0 + y1 - 2 * cy) * t * t + (2 * cy - 2 * y0) * t + y0;
    return pos;
}

double QuadBezier::getLength() {
    int p0x = x0 + x1 - 2 * cx;
    int p0y = y0 + y1 - 2 * cy;
    int p1x = cx - x0;
    int p1y = cy - y0;
    return sqrt(p0x * p0x + p0y * p0y) + 2 * sqrt(p1x * p1x + p1y * p1y);
}

void QuadBezier::drawSegmented(SDL_Surface* screen, int s) {
    for(double i = 1; i <= s; i += 1) {
        int *p1 = getPoint((i - 1) / s);
        int *p2 = getPoint(i / s);
        drawLine(screen, p1[0], p1[1], p2[0], p2[1]);
    }
}

void QuadBezier::draw(SDL_Surface* screen) {
    drawSegmented(screen, getLength() / 3.35616);
}