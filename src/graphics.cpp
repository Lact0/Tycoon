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

bool Color::plot(SDL_Surface* screen, Vector p) const {
    int x = p.vect[0];
    int y = p.vect[1];
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
            error += dy;
            x0 += sx;
        }
        if(e2 <= dx) {
            if(y0 == y1) {break;}
            error += dx;
            y0 += sy;
        }
    }
}

void Graphics::drawLine(SDL_Surface* screen, Vector p0, Vector p1) {
    int dx = abs(p1.vect[0] - p0.vect[0]);
    Vector sx(std::vector{p0.vect[0] < p1.vect[0] ? 1 : -1, 0});
    int dy = -abs(p1.vect[1] - p0.vect[1]);
    Vector sy(std::vector{0, p0.vect[1] < p1.vect[1] ? 1 : -1});
    int error = dx + dy;
    
    for(;;) {
        WHITE.plot(screen, p0);
        if(p0 == p1) {break;}
        int e2 = 2 * error;
        if(e2 >= dy) {
            if(p0.vect[0] == p1.vect[0]) {break;}
            error += dy;
            p0 += sx;
        }
        if(e2 <= dx) {
            if(p0.vect[1] == p1.vect[1]) {break;}
            error += dx;
            p0 += sy;
        }
    }
}

void Graphics::drawArc(SDL_Surface* screen, Vector p, Vector r, double t0, double t1) {
    double s = 100;
    double f = (t1 - t0) / s;
    for(double i = 1; i <= s; i++) {
        Vector p0 = p + r * Vector(std::vector{sin(f * (i - 1)), -cos(f * (i - 1))});
        Vector p1 = p + r * Vector(std::vector{sin(f * i), -cos(f * i)});

        drawLine(screen, p0, p1);
    }
}

void Graphics::drawArc(SDL_Surface* screen, Vector p, int r, double t0, double t1) {
    drawArc(screen, p, Vector(std::vector{r, r}), t0, t1);
}

void Graphics::drawRect(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d * Vector(std::vector{1, 0});
    Vector bl = p + d * Vector(std::vector{0, 1});
    Vector br = p + d;
    drawLine(screen, p, tr);
    drawLine(screen, tr, br);
    drawLine(screen, p, bl);
    drawLine(screen, bl, br);
}

QuadBezier::QuadBezier(Vector p0, Vector p1, Vector p2) {
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
}

Vector QuadBezier::getPoint(double t) {
    return (p0 + p2 - (p1 * 2)) * t * t + ((p1 * 2) - (p0 * 2)) * t + p0;
}

double QuadBezier::getLength() {
    //TEMPORARY
    return (p0 + p2 - (p1 * 2)).mag + 2 * (p1 - p0).mag;
}

void QuadBezier::drawSegmented(SDL_Surface* screen, int s) {
    for(double i = 1; i <= s; i += 1) {
        Vector p0 = getPoint((i - 1) / s);
        Vector p1 = getPoint(i / s);
        drawLine(screen, p0, p1);
    }
}

void QuadBezier::draw(SDL_Surface* screen) {
    //TEMPORARY
    drawSegmented(screen, getLength() / 3.35616);
}

CubicBezier::CubicBezier(Vector p0, Vector p1, Vector p2, Vector p3) {
    this->p0 = p0;
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Vector CubicBezier::getPoint(double t) {
    return (p1 * 3 + p3 - p0 - p2 * 3) * t * t * t + 
           (p0 * 3 + p2 * 3 - p1 * 6) * t * t +
           (p1 * 3 - p0 * 3) * t +
           (p0);
}

double CubicBezier::getLength() {
    //TEMPORARY
    return (p3 - p0).mag;
}

void CubicBezier::drawSegmented(SDL_Surface* screen, int s) {
    for(double i = 1; i <= s; i += 1) {
        Vector p0 = getPoint((i - 1) / s);
        Vector p1 = getPoint(i / s);
        drawLine(screen, p0, p1);
    }
}

void CubicBezier::draw(SDL_Surface* screen) {
    //TEMPORARY
    drawSegmented(screen, getLength() / 3.35616);
}