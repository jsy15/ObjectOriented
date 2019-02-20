#include "card.hpp"

bool
operator==(Card a, Card b)
{
  return a.get_rank() == b.get_rank() &&
         a.get_suit() == b.get_suit();
}

bool
operator!=(Card a, Card b)
{
  return !(a == b);
}


bool
operator<(Card a, Card b)
{
  // Product order (this is not a total order).
  // return a.get_rank() < b.get_rank() &&
  //        a.get_suit() < b.get_suit();

  // Lexicographical order
  if (a.get_suit() < b.get_suit())
    return true;
  if (b.get_suit() < a.get_suit())
    return false;
  return a.get_rank() < b.get_rank();
}

bool
operator>(Card a, Card b)
{
  return b < a;
}

bool
operator<=(Card a, Card b)
{
  return !(b < a);
}

bool
operator>=(Card a, Card b)
{
  return !(a < b);
}

