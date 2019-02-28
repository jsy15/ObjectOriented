#ifndef GAME_H
#define GAME_H
#include "snake.hpp"
#include "fruct.hpp"
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Game{
    Snake s[100];
    Fruct f;
    int N;
    int M;
    int dir;
    int num;
    int size;
    int w;
    int h;

    void Tick();
    
    public:
    Game();
    void play_game();
};

#endif