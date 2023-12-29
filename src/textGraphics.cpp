#include "textGraphics.h"
#include <iostream>
#include <cmath>

using namespace Graphics;

void TextGraphics::drawA(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d;
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector ml = p + d / Vector(std::vector{4, 2});
    Vector mr = p + d / Vector(std::vector{4.0 / 3, 2.0});
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

void TextGraphics::drawC(SDL_Surface* screen, Vector p, Vector d) {
    drawArc(screen, p + d / 2, d / 2, M_PI / 4, M_PI / 4 * 7);
}

void TextGraphics::drawD(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d * Vector(std::vector{0, 1});
    Vector tr = p + d * Vector(std::vector{1, 0});
    Vector br = p + d;
    Vector mr = (tr + br) / 2;

    drawLine(screen, p, bl);
    QuadBezier(p, tr, mr).draw(screen);
    QuadBezier(mr, br, bl).draw(screen);
}

void TextGraphics::drawE(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d * Vector(std::vector{0, 1});
    Vector tr = p + d * Vector(std::vector{1, 0});
    Vector br = p + d;
    Vector mr = (tr + br) / 2;
    Vector ml = (p + bl) / 2;

    drawLine(screen, p, tr);
    drawLine(screen, p, bl);
    drawLine(screen, ml, mr);
    drawLine(screen, bl, br);
}

void TextGraphics::drawF(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d * Vector(std::vector{0, 1});
    Vector tr = p + d * Vector(std::vector{1, 0});
    Vector mr = (tr + p + d) / 2;
    Vector ml = (p + bl) / 2;

    drawLine(screen, p, tr);
    drawLine(screen, p, bl);
    drawLine(screen, ml, mr);
}

void TextGraphics::drawG(SDL_Surface* screen, Vector p, Vector d) {
    Vector mm = p + d / Vector(std::vector{2, 2});
    Vector cb = (p + d / 2) + (d / 2) * Vector(std::vector{cos(-M_PI / 8), -sin(-M_PI / 8)});
    Vector up(std::vector{cb.vect[0], mm.vect[1]});

    drawArc(screen, p + d / 2, d / 2, M_PI / 8, M_PI / 8 * 15);
    drawLine(screen, cb, up);
    drawLine(screen, up, mm);

}

void TextGraphics::drawH(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector mr = p + d / Vector(std::vector{1, 2});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, bl);
    drawLine(screen, ml, mr);
    drawLine(screen, tr, br);
}

void TextGraphics::drawI(SDL_Surface* screen, Vector p, Vector d) {
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector bm = p + d / Vector(std::vector{2, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, tr);
    drawLine(screen, bl, br);
    drawLine(screen, tm, bm);
}

void TextGraphics::drawJ(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector t3 = p + d / Vector(std::vector{5.0 / 4, 0.0});
    double dist = d.vect[0] / 5 * 2;
    Vector rc(std::vector{t3.vect[0], p.vect[1] + d.vect[1] - dist});
    Vector lc(std::vector{p.vect[0] + d.vect[0] / 5 * 2, rc.vect[1]});

    drawLine(screen, p, tr);
    drawLine(screen, t3, rc);
    drawArc(screen, lc, dist, M_PI, M_PI * 2);
}

void TextGraphics::drawK(SDL_Surface* screen, Vector p, Vector d) {\
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, bl);
    drawLine(screen, ml, tr);
    drawLine(screen, ml, br);
}

void TextGraphics::drawL(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, bl);
    drawLine(screen, bl, br);
}

void TextGraphics::drawM(SDL_Surface* screen, Vector p, Vector d) {
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector bm = p + d / Vector(std::vector{2, 1});
    Vector br = p + d / Vector(std::vector{1, 1});
    Vector tl4 = p + d / Vector(std::vector{4, 0});
    Vector tr4 = p + d / Vector(std::vector{4.0 / 3, 0.0});

    drawLine(screen, bl, tl4);
    drawLine(screen, tl4, bm);
    drawLine(screen, bm, tr4);
    drawLine(screen, tr4, br);
}

void TextGraphics::drawN(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, bl, p);
    drawLine(screen, p, br);
    drawLine(screen, br, tr);
}

void TextGraphics::drawO(SDL_Surface* screen, Vector p, Vector d) {
    drawArc(screen, p + d / 2, d / 2, 0, 2 * M_PI);
}

void TextGraphics::drawP(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector mr = p + d / Vector(std::vector{1, 2});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector l4 = (tr + mr) / 2;

    drawLine(screen, p, bl);

    QuadBezier(p, tr, l4).draw(screen);
    QuadBezier(l4, mr, ml).draw(screen);
}

void TextGraphics::drawQ(SDL_Surface* screen, Vector p, Vector d) {
    Vector m = p + d * 0.8;
    Vector o = p + d * 0.95;

    drawLine(screen, m, o);
    drawArc(screen, p + d / 2, d / 2, 0, 2 * M_PI);
}

void TextGraphics::drawR(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector mr = p + d / Vector(std::vector{1, 2});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});
    Vector l4 = (tr + mr) / 2;

    drawLine(screen, p, bl);
    drawLine(screen, ml, br);

    QuadBezier(p, tr, l4).draw(screen);
    QuadBezier(l4, mr, ml).draw(screen);
}
void TextGraphics::drawS(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector mm = p + d / Vector(std::vector{2, 2});
    Vector mr = p + d / Vector(std::vector{1, 2});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});
    Vector l4 = (p + ml) / 2;
    Vector r4 = (mr + br) / 2;

    QuadBezier(tr, p, l4).draw(screen);
    QuadBezier(l4, ml, mm).draw(screen);
    QuadBezier(mm, mr, r4).draw(screen);
    QuadBezier(r4, br, bl).draw(screen);
}

void TextGraphics::drawT(SDL_Surface* screen, Vector p, Vector d) {
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bm = p + d / Vector(std::vector{2, 1});

    drawLine(screen, p, tr);
    drawLine(screen, tm, bm);
}

void TextGraphics::drawU(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector ml = p + d / Vector(std::vector{0, 2});
    Vector mr = p + d / Vector(std::vector{1, 2});
    Vector bm = p + d / Vector(std::vector{2, 1});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, ml);
    drawLine(screen, tr, mr);
    QuadBezier(ml, bl, bm).draw(screen);
    QuadBezier(bm, br, mr).draw(screen);
}

void TextGraphics::drawV(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bm = p + d / Vector(std::vector{2, 1});

    drawLine(screen, p, bm);
    drawLine(screen, bm, tr);
}

void TextGraphics::drawW(SDL_Surface* screen, Vector p, Vector d) {
    Vector tm = p + d / Vector(std::vector{2, 0});
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bl4 = p + d / Vector(std::vector{4, 1});
    Vector br4 = p + d / Vector(std::vector{4.0 / 3, 1.0});

    drawLine(screen, p, bl4);
    drawLine(screen, bl4, tm);
    drawLine(screen, tm, br4);
    drawLine(screen, br4, tr);
}

void TextGraphics::drawX(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, br);
    drawLine(screen, bl, tr);
}

void TextGraphics::drawY(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector mm = p + d / Vector(std::vector{2, 2});
    Vector bm = p + d / Vector(std::vector{2, 1});

    drawLine(screen, p, mm);
    drawLine(screen, mm, tr);
    drawLine(screen, mm, bm);
}

void TextGraphics::drawZ(SDL_Surface* screen, Vector p, Vector d) {
    Vector tr = p + d / Vector(std::vector{1, 0});
    Vector bl = p + d / Vector(std::vector{0, 1});
    Vector br = p + d / Vector(std::vector{1, 1});

    drawLine(screen, p, tr);
    drawLine(screen, tr, bl);
    drawLine(screen, bl, br);
}

void TextGraphics::drawChar(SDL_Surface* screen, char c, Vector p, Vector d) {
    switch(toupper(c)) {
        case 'A': TextGraphics::drawA(screen, p, d); break;
        case 'B': TextGraphics::drawB(screen, p, d); break;
        case 'C': TextGraphics::drawC(screen, p, d); break;
        case 'D': TextGraphics::drawD(screen, p, d); break;
        case 'E': TextGraphics::drawE(screen, p, d); break;
        case 'F': TextGraphics::drawF(screen, p, d); break;
        case 'G': TextGraphics::drawG(screen, p, d); break;
        case 'H': TextGraphics::drawH(screen, p, d); break;
        case 'I': TextGraphics::drawI(screen, p, d); break;
        case 'J': TextGraphics::drawJ(screen, p, d); break;
        case 'K': TextGraphics::drawK(screen, p, d); break;
        case 'L': TextGraphics::drawL(screen, p, d); break;
        case 'M': TextGraphics::drawM(screen, p, d); break;
        case 'N': TextGraphics::drawN(screen, p, d); break;
        case 'O': TextGraphics::drawO(screen, p, d); break;
        case 'P': TextGraphics::drawP(screen, p, d); break;
        case 'Q': TextGraphics::drawQ(screen, p, d); break;
        case 'R': TextGraphics::drawR(screen, p, d); break;
        case 'S': TextGraphics::drawS(screen, p, d); break;
        case 'T': TextGraphics::drawT(screen, p, d); break;
        case 'U': TextGraphics::drawU(screen, p, d); break;
        case 'V': TextGraphics::drawV(screen, p, d); break;
        case 'W': TextGraphics::drawW(screen, p, d); break;
        case 'X': TextGraphics::drawX(screen, p, d); break;
        case 'Y': TextGraphics::drawY(screen, p, d); break;
        case 'Z': TextGraphics::drawZ(screen, p, d); break;
    }
}

void TextGraphics::drawText(SDL_Surface* screen, std::string text, Vector p, Vector d) {
    for(int i = 0; i < text.length(); i++) {
        TextGraphics::drawChar(screen, text[i], p + d * Vector(std::vector{i, 0}), d);
    }
}