#ifndef GAME_H
#define GAME_H

#include "deck.hpp"
#include "card.hpp"
#include "player.hpp"
#include <vector>
class Game {
    int place = 0;
    Deck d;
    Player player1;
    Player player2;
    std::vector<Card> draw;
    std::vector<Card> tempPlay1;
    std::vector<Card> tempPlay2;
    public:
    Game();
    void play_game();
    void shuffle();
    void print();
    void war();
};

#endif