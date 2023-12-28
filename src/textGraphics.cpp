#include "textGraphics.h"

using namespace Graphics;

void TextGraphics::drawA(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d;
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector ml = p + d / Vector(std::vector{4, 2});
    Vector mr = p + d / Vector(std::vector{4, 2}) * Vector{std::vector{3, 1}};
    drawLine(screen, bl, tm);
    drawLine(screen, tm, br);
    drawLine(screen, ml, mr);
}

void TextGraphics::drawB(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector mm = p + d / 2;
    Vector bm = p + d / Vector(std::vector{2, 1});

    drawLine(screen, p, bl);
    drawLine(screen, p, tm);
    drawLine(screen, ml, mm);
    drawLine(screen, bl, bm);
    drawArc(screen, (tm + mm) / 2, (tm - mm).mag / 2, -M_PI / 2, M_PI / 2);
    drawArc(screen, (bm + mm) / 2, (tm - mm).mag / 2, -M_PI / 2, M_PI / 2);

}

void TextGraphics::drawC(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawD(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawE(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawF(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawG(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawH(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawI(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawJ(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawK(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawL(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawM(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawN(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawO(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawP(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawQ(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawR(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawS(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawT(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawU(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawV(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawW(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawX(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawY(SDL_Surface* screen, Vector p, Vector d);
void TextGraphics::drawZ(SDL_Surface* screen, Vector p, Vector d);