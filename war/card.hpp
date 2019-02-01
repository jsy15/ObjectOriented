#ifndef CARD_H
#define CARD_H

#include <iostream>

//Enums for the suit and ranks
enum Suit {
  Hearts,
  Clubs,
  Diamonds,
  Spades
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

};

//Overloading the ostream operator to fix the enums for output
inline std::ostream& operator<<( std::ostream& os, const Suit& suit )
{
   switch( suit )
   {
      case Hearts: os << "Hearts"; break;
      case Clubs: os << "Clubs"; break;
      case Diamonds: os << "Diamonds"; break;
      case Spades: os << "Spades"; break;
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
      case ten: os << "T"; break;
      case jack: os << "J"; break;
      case queen: os << "Q"; break;
      case king: os << "K"; break;
      case ace: os << "A"; break;
   }
   return os;
};

#endif