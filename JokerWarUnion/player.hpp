#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include "card.hpp"

struct Player{
    std::deque<StandardCard> hand;
    int score = 0;
};

#endif