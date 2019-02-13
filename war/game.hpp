#ifndef GAME_H
#define GAME_H

#include "deck.hpp"
#include "card.hpp"
#include "player.hpp"
class Game {
    int place = 0;
    Deck d;
    Player player1;
    Player player2;
    public:
    Game();
    void play_game();
    void shuffle();
    void print();
    void war(int);
};

#endif