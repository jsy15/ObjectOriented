#ifndef CARD_H
#define CARD_H

#include <iostream>

enum Suit {
  Heart,
  Club,
  Diamond,
  Spade
};

enum Rank {
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack,
  queen,
  king, 
  ace
};

struct Card {
    Suit suit;
    Rank rank;

  public:
    void testFunc();
};

inline std::ostream& operator<<( std::ostream& os, const Suit& suit )
{
   switch( suit )
   {
      case Heart: os << "heart"; break;
      case Club: os << "club"; break;
      case Diamond: os << "diamond"; break;
      case Spade: os << "spade"; break;
   }
   return os;
};

inline std::ostream& operator<<( std::ostream& os, const Rank& rank )
{
   switch( rank )
   {
      case two: os << "2"; break;
      case three: os << "3"; break;
      case four: os << "4"; break;
      case five: os << "5"; break;
      case six: os << "6"; break;
      case seven: os << "7"; break;
      case eight: os << "8"; break;
      case nine: os << "9"; break;
      case ten: os << "10"; break;
      case jack: os << "J"; break;
      case queen: os << "Q"; break;
      case king: os << "K"; break;
      case ace: os << "A"; break;
   }
   return os;
};

#endif