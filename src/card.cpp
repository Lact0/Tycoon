#include "card.h"
#include <iostream>

Card::Card() {
    rank = 1;
    suite = 1;
}

Card::Card(int r, int s) {
    rank = r;
    suite = s;
}

void Card::draw(SDL_Surface* screen, Vector p, Vector d) {
    p = Vector(std::vector{
        (p.vect[0] < 0? 0 : (p.vect[0] + d.vect[0] + 1 >= screen->w? screen->w - d.vect[0] - 1: p.vect[0])),
        (p.vect[1] < 0? 0 : (p.vect[1] + d.vect[1] + 1 >= screen->h? screen->h - d.vect[1] - 1: p.vect[1]))
    });

    std::string text;

    switch(rank) {
        case  1: text = "A"; break;
        case 10: text = "T"; break;
        case 11: text = "J"; break;
        case 12: text = "Q"; break;
        case 13: text = "K"; break;
        default: text = std::to_string(rank);
    }
    switch(suite) {
        case 1: text += "H"; break;
        case 2: text += "D"; break;
        case 3: text += "C"; break;
        case 4: text += "S"; break;
    }
    if(rank == 14) {
        text = "JO";
    }

    Graphics::drawRect(screen, p, d);
    TextGraphics::drawText(
        screen, text,
        p + d / Vector(std::vector{0, 4}),
        d / 2, d / 25
    );
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