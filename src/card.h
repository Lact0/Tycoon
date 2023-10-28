#pragma once
#include <string>

//Suites are 1 - Hearts, 2 - Diamonds, 3 - Clubs, 4 - Spades
const std::string suites[] = {"", "Hearts", "Diamonds", "Clubs", "Spades"};
//Joker is rank 14
const std::string ranks[] = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Joker"};

class Card {
    public:
        int rank;
        int suite;

        Card();
        Card(int r, int s);

        void draw(char* pixels, int pitch, int bytesPerPixel, int x, int y, double w);
        bool beats(Card card);
        std::string getName();

};