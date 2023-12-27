#pragma once
#include <SDL2/SDL.h>
#include "vector.h"

namespace Graphics {

class Color {
    public:
        int r;
        int g;
        int b;

        Color(int r, int g, int b);
        bool plot(SDL_Surface* screen, int x, int y) const;
        bool plot(SDL_Surface* screen, Vector p) const;
};

const Color WHITE(255, 255, 255);
const Color BLACK(0, 0, 0);
const Color RED(255, 0, 0);
const Color Green(0, 255, 0);
const Color BLUE(0, 0, 255);

void drawLine(SDL_Surface* screen, int x0, int y0, int x1, int y1);
void drawLine(SDL_Surface* screen, Vector p0, Vector p1);

class QuadBezier {
    public:
        int x0, y0;
        int x1, y1;
        int cx, cy;

        QuadBezier(int x0, int y0, int x1, int y1, int cx, int cy);
            
        int* getPoint(double t);
        double getLength();

        void drawSegmented(SDL_Surface* screen, int s);
        void draw(SDL_Surface* screen);
};

class CubicBezier {
    public:
        int x0, y0;
        int x1, y1;
        int x2, y2;
        int x3, y3;

        CubicBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
            
        int* getPoint(double t);
        double getLength();

        void drawSegmented(SDL_Surface* screen, int s);
        void draw(SDL_Surface* screen);
};

}