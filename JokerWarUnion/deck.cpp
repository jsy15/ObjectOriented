#include "deck.hpp"
#include "card.hpp"
#include <iostream>

std::ostream& 
operator<<(std::ostream& os, Deck const& d)
{
  int n = 0;
  for (Card c : d) {
    os << c << ' ';
    if (n == 12) {
      os << '\n';
      n = 0;
    }
    else {
      ++n;
    }
  }
  return os;
}
