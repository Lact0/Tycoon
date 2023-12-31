#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "textGraphics.h"

//suits are 1 - Hearts, 2 - Diamonds, 3 - Clubs, 4 - Spades
const std::string suits[] = {"", "Hearts", "Diamonds", "Clubs", "Spades"};
//Joker is rank 14
const std::string ranks[] = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Joker"};

class Card {
    public:
        int rank, suit;

        Card();
        Card(int r, int s);

        void draw(SDL_Surface* screen, Vector p, Vector d);
        bool beats(Card card);
        std::string getName();
};