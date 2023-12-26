#include "card.h"

Card::Card() {
    rank = 1;
    suite = 1;
}

Card::Card(int r, int s) {
    rank = r;
    suite = s;
}

void Card::draw(SDL_Surface* screen, int x, int y, double w) {
    char* pixels = (char*) screen->pixels;
    x = std::min(std::max(x, 0), screen->w - (int) (w) - 1);
    y = std::min(std::max(y, 0), screen->h - (int) (w * 7 / 5) - 1);

    for(int i = x; i < x + w; i++) {
        Graphics::WHITE.plot(screen, i, y);
        Graphics::WHITE.plot(screen, i, y + w * 7 / 5);
    }
    for(int j = y; j < y + w * 7 / 5; j++) {
        Graphics::WHITE.plot(screen, x, j);
        Graphics::WHITE.plot(screen, x + w, j);
    }
}

bool Card::beats(Card card) {

    //3 of spades overrule joker
    if(card.rank == 14 && rank == 3 && suite == 4) {
        return true;
    }

    //Joker unbeatable
    if(card.rank == 14) {
        return false;
    }

    //Same rank
    if(rank == card.rank) {
        return false;
    }

    //Joker beats everything
    if(rank == 14) {
        return true;
    }

    //2 beats everything
    if(rank == 2) {
        return true;
    }

    //Ace beats everything but 2
    if(rank == 1 && card.rank != 2) {
        return true;
    }

    if(card.rank <= 2) {
        return false;
    }

    return rank > card.rank;
}

std::string Card::getName() {
    if(rank == 14) {
        return "Joker";
    }
    return ranks[rank] + " of " + suites[suite];
}