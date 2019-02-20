#ifndef DECK_H
#define DECK_H

#include "deck.hpp"
#include "card.hpp"
#include <deque>
#include <iosfwd>

struct Deck : std::deque<Card> {
  using std::deque<Card>::deque;
};

std::ostream& operator<<(std::ostream& os, Deck const& d);

#endif