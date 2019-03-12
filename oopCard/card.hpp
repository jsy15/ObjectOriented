#ifndef CARD_H
#define CARD_H

#include <iostream>

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
  public:
    Kind kind;
    Card();
    Card(Kind k)
      : kind(k)
    { }
    Kind get_kind() const;
    virtual void print(std::ostream& os) const = 0;
    virtual Color get_color() const = 0;
};

class StandardCard : Card {
  public:
    Rank rank;
    Suit suit;
    StandardCard(Rank r, Suit s)
      : Card(SCard), rank(r), suit(s)
    { }
    Rank get_rank() const;
    Suit get_suit() const;
    void print(std::ostream& os) const override;
    Color get_color() const override;
};

class JokerCard : Card {
  public:
    Color color;
    JokerCard(Color c)
      : Card(JCard), color(c)
    { }
    Color get_color() const override;
    void print(std::ostream& os) const override;
};

std::ostream& operator<<(std::ostream& os, StandardCard& c);
std::ostream& operator<<(std::ostream& os, JokerCard& c);
std::ostream& operator<<(std::ostream& os, Card& c);
std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, Kind k);

#endif