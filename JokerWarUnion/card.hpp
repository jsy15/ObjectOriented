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
   Black,
   Red
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

class JokerCard {
   public:
   JokerCard(Color c)
      : color(c)
      { }

   Color get_color() const { return color; }

   private:
      Color color;
};

union PlayingCardData {
   PlayingCardData(Rank r, Suit s)
      : sc(r, s)
      { }

   PlayingCardData(Color c)
      : jc(c)
      { }

      StandardCard sc;
      JokerCard jc;
};

enum PlayingCardKind {
   Standard,
   Joker
};

class PlayingCard {
   public:
      PlayingCard(Rank r, Suit s)
         : tag(Standard), data(r,s)
         { }

      PlayingCard(Color c)
         : tag(Joker), data(c)
         { }

      bool is_joker() const {
         if(tag == Joker){
            return true;
         }
         else{
            return false;
         }         
      };

      bool is_standard() const{
         if(tag == Standard){
            return true;
         }
         else{
            return false;
         }
         
      };

      StandardCard getStandardCard() const {
         assert(is_standard());
         return data.sc;
      };

      JokerCard getJokerCard() const {
         assert(is_joker());
         return data.jc;
      }

      Rank get_rank() const{
         assert(is_standard());
         return data.sc.get_rank();
      }

      Suit get_suit() const {
         assert(is_standard());
         return data.sc.get_suit();
      };

      Color get_color() const{
         assert(is_joker());
         return data.jc.get_color();
      }

   private:
      PlayingCardKind tag;
      PlayingCardData data;
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