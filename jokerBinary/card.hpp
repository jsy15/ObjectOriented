#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iosfwd>
#include <cassert>

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

enum Color {
   Red,
   Black
};

class Card {
   public:

      //Default contstructor needs to be declared
      Card() = default;

      Card(Rank r, Suit s)
         : bits((unsigned)s << 4 | (unsigned)r)
      {}

      Card(Color c)
         : bits((unsigned)(1) << 6 | (unsigned)c << 7)
      {}

      Rank get_rank() const {
         return (Rank) (0b001111 & bits);
      }

      Suit get_suit() const {
         std::cout << ((bits >> 0) & 0x1) << std::endl;
         std::cout << ((bits >> 1) & 0x1) << std::endl;
         std::cout << ((bits >> 2) & 0x1) << std::endl;
         std::cout << ((bits >> 3) & 0x1) << std::endl;
         std::cout << ((bits >> 4) & 0x1) << std::endl;
         std::cout << ((bits >> 5) & 0x1) << std::endl;
         std::cout << ((bits >> 6) & 0x1) << std::endl;
         std::cout << ((bits >> 7) & 0x1) << std::endl;
         return (Suit)((0b110000 & bits) >> 4);
      } 

      Color get_color() const {
         if (((bits >> 6) & 0x1) == 1){
            return (Color)((bits >> 7) & 0x1);
         }
         else{
            return (Color)-1;
         }
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

inline std::ostream& operator<<( std::ostream& os, const Color& color )
{
   switch( color )
   {
      case Red: os << "R"; break;
      case Black: os << "B"; break;
   }
   return os;
};

inline std::ostream& operator<<( std::ostream& os, const Card& c )
{
   return os << c.get_rank() << c.get_suit();
};

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);






#endif