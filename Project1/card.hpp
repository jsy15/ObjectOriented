#ifndef card_h
#define card_h

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
};

#endif