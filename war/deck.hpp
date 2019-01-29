#ifndef DECK_H
#define DECK_H

#include "card.hpp"

class Deck {
    struct Card cards[52];
  public:
    int getRank(int pos);
    int getSuit(int pos);
    Deck();

    void print();
};

#endif