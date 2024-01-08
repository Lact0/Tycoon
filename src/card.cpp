#include "card.h"
#include <iostream>

Card::Card() {
    rank = 1;
    suit = 1;
}

Card::Card(int r, int s) {
    rank = r;
    suit = s;
}

void Card::draw(SDL_Surface* screen, Vector p, Vector d) {
    p = Vector(std::vector{
        (p.vect[0] < 0? 0 : (p.vect[0] + d.vect[0] + 1 >= screen->w? screen->w - d.vect[0] - 1: p.vect[0])),
        (p.vect[1] < 0? 0 : (p.vect[1] + d.vect[1] + 1 >= screen->h? screen->h - d.vect[1] - 1: p.vect[1]))
    });

    Graphics::drawRect(screen, p, d);

    if(rank == 14) {
        TextGraphics::drawText(
            screen, "JO",
            p + d / Vector(std::vector{0, 4}),
            d / 2, d / 25
        );
        return;
    }

    char text;

    switch(rank) {
        case  1: text = 'A'; break;
        case 10: text = 'T'; break;
        case 11: text = 'J'; break;
        case 12: text = 'Q'; break;
        case 13: text = 'K'; break;
        default: text = rank + '0';
    }

    TextGraphics::drawChar(
        screen, text,
        p + d / Vector(std::vector{0, 4}),
        d / 2, d / 25
    );

    Vector hp = p + d / Vector(std::vector{2, 4});
    Vector pad = d / 25;

    switch(suit) {
        case 1: TextGraphics::drawHeart(screen, hp + pad, d / 2 - pad * 2); break;
        case 2: TextGraphics::drawDiamond(screen, hp + pad, d / 2 - pad * 2); break;
        case 3: TextGraphics::drawClub(screen, hp + pad, d / 2 - pad * 2); break;
        case 4: TextGraphics::drawSpade(screen, hp + pad, d / 2 - pad * 2); break;
    }
}

bool Card::beats(Card card) {

    //3 of spades overrule joker
    if(card.rank == 14 && rank == 3 && suit == 4) {
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
    return ranks[rank] + " of " + suits[suit];
}