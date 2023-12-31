#pragma once
#include "graphics.h"
#include <string>

namespace TextGraphics {

void drawA(SDL_Surface* screen, Vector p, Vector d);
void drawB(SDL_Surface* screen, Vector p, Vector d);
void drawC(SDL_Surface* screen, Vector p, Vector d);
void drawD(SDL_Surface* screen, Vector p, Vector d);
void drawE(SDL_Surface* screen, Vector p, Vector d);
void drawF(SDL_Surface* screen, Vector p, Vector d);
void drawG(SDL_Surface* screen, Vector p, Vector d);
void drawH(SDL_Surface* screen, Vector p, Vector d);
void drawI(SDL_Surface* screen, Vector p, Vector d);
void drawJ(SDL_Surface* screen, Vector p, Vector d);
void drawK(SDL_Surface* screen, Vector p, Vector d);
void drawL(SDL_Surface* screen, Vector p, Vector d);
void drawM(SDL_Surface* screen, Vector p, Vector d);
void drawN(SDL_Surface* screen, Vector p, Vector d);
void drawO(SDL_Surface* screen, Vector p, Vector d);
void drawP(SDL_Surface* screen, Vector p, Vector d);
void drawQ(SDL_Surface* screen, Vector p, Vector d);
void drawR(SDL_Surface* screen, Vector p, Vector d);
void drawS(SDL_Surface* screen, Vector p, Vector d);
void drawT(SDL_Surface* screen, Vector p, Vector d);
void drawU(SDL_Surface* screen, Vector p, Vector d);
void drawV(SDL_Surface* screen, Vector p, Vector d);
void drawW(SDL_Surface* screen, Vector p, Vector d);
void drawX(SDL_Surface* screen, Vector p, Vector d);
void drawY(SDL_Surface* screen, Vector p, Vector d);
void drawZ(SDL_Surface* screen, Vector p, Vector d);

void draw0(SDL_Surface* screen, Vector p, Vector d);
void draw1(SDL_Surface* screen, Vector p, Vector d);
void draw2(SDL_Surface* screen, Vector p, Vector d);
void draw3(SDL_Surface* screen, Vector p, Vector d);
void draw4(SDL_Surface* screen, Vector p, Vector d);
void draw5(SDL_Surface* screen, Vector p, Vector d);
void draw6(SDL_Surface* screen, Vector p, Vector d);
void draw7(SDL_Surface* screen, Vector p, Vector d);
void draw8(SDL_Surface* screen, Vector p, Vector d);
void draw9(SDL_Surface* screen, Vector p, Vector d);

void drawChar(SDL_Surface* screen, char c, Vector p, Vector d);
void drawChar(SDL_Surface* screen, char c, Vector p, Vector d, Vector pad);
void drawText(SDL_Surface* screen, std::string text, Vector p, Vector d);
void drawText(SDL_Surface* screen, std::string text, Vector p, Vector d, Vector pad);

void drawHeart(SDL_Surface* screen, Vector p, Vector d);
void drawDiamond(SDL_Surface* screen, Vector p, Vector d);
void drawClub(SDL_Surface* screen, Vector p, Vector d);
void drawSpade(SDL_Surface* screen, Vector p, Vector d);

}