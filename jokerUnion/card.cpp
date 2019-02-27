#include "card.hpp"

bool
operator==(StandardCard a, StandardCard b)
{
  return a.get_rank() == b.get_rank() &&
         a.get_suit() == b.get_suit();
}

bool
operator!=(StandardCard a, StandardCard b)
{
  return !(a == b);
}


bool
operator<(StandardCard a, StandardCard b)
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
operator>(StandardCard a, StandardCard b)
{
  return b < a;
}

bool
operator<=(StandardCard a, StandardCard b)
{
  return !(b < a);
}

bool
operator>=(StandardCard a, StandardCard b)
{
  return !(a < b);
}

