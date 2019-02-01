#ifndef DECK_H
#define DECK_H

#include "card.hpp"

class Deck {
    struct Card cards[52];
  public:
    Rank getRank(int pos);
    Suit getSuit(int pos);
    Deck();

    void print();
};

#endif