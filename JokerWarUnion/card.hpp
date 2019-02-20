#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iosfwd>

//Enums for the suit and ranks
enum Suit {
  Hearts,
  Diamonds,
  Clubs,
  Spades
};

enum Rank {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King
};

class StandardCard {
   public:

      //Default contstructor needs to be declared
      StandardCard() = default;

      StandardCard(Rank r, Suit s)
         : bits((unsigned)s << 4 | (unsigned)r)
      {}

      Rank get_rank() const {
         return (Rank) (0b001111 & bits);
      }

      Suit get_suit() const {
         return (Suit)((0b110000 & bits) >> 4);
      } 

   private:
      unsigned char bits;

};

//Overloading the ostream operator to fix the enums for output
inline std::ostream& operator<<( std::ostream& os, const Suit& suit )
{
   switch( suit )
   {
      case Hearts: os << "H"; break;
      case Clubs: os << "C"; break;
      case Diamonds: os << "D"; break;
      case Spades: os << "S"; break;
   }
   return os;
};

inline std::ostream& operator<<( std::ostream& os, const Rank& rank )
{
   switch( rank )
   {
      case Two: os << "2"; break;
      case Three: os << "3"; break;
      case Four: os << "4"; break;
      case Five: os << "5"; break;
      case Six: os << "6"; break;
      case Seven: os << "7"; break;
      case Eight: os << "8"; break;
      case Nine: os << "9"; break;
      case Ten: os << "T"; break;
      case Jack: os << "J"; break;
      case Queen: os << "Q"; break;
      case King: os << "K"; break;
      case Ace: os << "A"; break;
   }
   return os;
};

inline std::ostream& operator<<( std::ostream& os, const StandardCard& c )
{
   return os << c.get_rank() << c.get_suit();
};

bool operator==(StandardCard a, StandardCard b);
bool operator!=(StandardCard a, StandardCard b);

bool operator<(StandardCard a, StandardCard b);
bool operator>(StandardCard a, StandardCard b);
bool operator<=(StandardCard a, StandardCard b);
bool operator>=(StandardCard a, StandardCard b);






#endif