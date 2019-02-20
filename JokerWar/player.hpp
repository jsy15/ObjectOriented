#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include "card.hpp"

struct Player{
    std::deque<Card> hand;
    int score = 0;
};

#endif