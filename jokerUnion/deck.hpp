#ifndef DECK_H
#define DECK_H

#include "deck.hpp"
#include "card.hpp"
#include <deque>
#include <iosfwd>

struct Deck : std::deque<StandardCard> {
  using std::deque<StandardCard>::deque;
};

std::ostream& operator<<(std::ostream& os, Deck const& d);

#endif