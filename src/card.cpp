#include "card.h"

Card::Card() {
    rank = 1;
    suite = 1;
}

Card::Card(int r, int s) {
    rank = r;
    suite = s;
}

void Card::draw(char* pixels, int pitch, int bytesPerPixel, int x, int y, double w) {
    for(int i = x; i < x + w; i++) {
        int ind = y * pitch + i * bytesPerPixel;
        pixels[ind] = 255;
        pixels[ind + 1] = 255;
        pixels[ind + 2] = 255;
        ind = (y + w * 7 / 5) * pitch + i * bytesPerPixel;
        pixels[ind] = 255;
        pixels[ind + 1] = 255;
        pixels[ind + 2] = 255;
    }
    for(int j = y; j < y + w * 7 / 5; j++) {
        int ind = j * pitch + x * bytesPerPixel;
        pixels[ind] = 255;
        pixels[ind + 1] = 255;
        pixels[ind + 2] = 255;
        ind = j * pitch + (x + w) * bytesPerPixel;
        pixels[ind] = 255;
        pixels[ind + 1] = 255;
        pixels[ind + 2] = 255;
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