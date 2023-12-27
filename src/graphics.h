#pragma once
#include <SDL2/SDL.h>

namespace Graphics {

class Color {
    public:
        int r;
        int g;
        int b;

        Color(int r, int g, int b);
        bool plot(SDL_Surface* screen, int x, int y) const;
};

const Color WHITE(255, 255, 255);
const Color BLACK(0, 0, 0);
const Color RED(255, 0, 0);
const Color Green(0, 255, 0);
const Color BLUE(0, 0, 255);

void drawLine(SDL_Surface* screen, int x0, int y0, int x1, int y1);

class QuadBezier {
    public:
        int x0, y0;
        int x1, y1;
        int cx, cy;

        QuadBezier(int x0, int y0, int x1, int y1, int cx, int cy);
        void drawSegmented(SDL_Surface* screen, int s);
        void draw(SDL_Surface* screen);
        double getLength();
    
    private:
        int* getPoint(double t);
};

}