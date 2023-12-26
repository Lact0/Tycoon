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


void drawLine(SDL_Surface* screen, int x1, int x2, int y1, int y2);

}