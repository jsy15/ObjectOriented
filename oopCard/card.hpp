#ifndef CARD_H
#define CARD_H

#include <iosfwd>

enum Suit {
  Spades,
  Clubs,
  Diamonds,
  Hearts,
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
  King,
};

enum Color {
  Black,
  Red,
};

enum Kind {
    SCard,
    JCard,
};

class Card {
    Kind kind;
  public:
    Card();
    Card(Kind k)
      : kind(k)
    { }
    Kind get_kind() const;
};

class StandardCard : Card {
    Rank rank;
    Suit suit;
  public:
    StandardCard(Rank r, Suit s)
      : rank(r), suit(s)
    { }
    Rank get_rank() const;
    Suit get_suit() const;
};

class JokerCard : Card {
    Color color;
  public:
    JokerCard(Color c)
      : color(c)
    { }
    Color get_color() const;
};

std::ostream& operator<<(std::ostream& os, StandardCard c);
std::ostream& operator<<(std::ostream& os, JokerCard c);
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, Kind k);

#endif