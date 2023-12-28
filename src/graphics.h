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
        Vector p0, p1, p2;

        QuadBezier(Vector p0, Vector p1, Vector p2);
        
        Vector getPoint(double t);
        double getLength();

        void drawSegmented(SDL_Surface* screen, int s);
        void draw(SDL_Surface* screen);
};

class CubicBezier {
    public:
        Vector p0, p1, p2, p3;

        CubicBezier(Vector p0, Vector p1, Vector p2, Vector p3);
            
        Vector getPoint(double t);
        double getLength();

        void drawSegmented(SDL_Surface* screen, int s);
        void draw(SDL_Surface* screen);
};

}