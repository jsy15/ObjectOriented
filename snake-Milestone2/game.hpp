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
    Trigger specf;
    Trigger trig;
    Fruct superfood;
    Fruct multifood[4];
    int N;
    int M;
    int dir;
    int num;
    int size;
    int w;
    int h;
    bool triggeractive;
    int triggerx;
    int triggery;
    int test1;
    int test2;
    int specx;
    int specy;
    int supfoodx;
    int supfoody;
    int multifood0x;   
    int multifood0y;
    int multifood1x;
    int multifood1y;
    int multifood2x;
    int multifood2y;
    int multifood3x;
    int multifood3y;    
    bool multiactive;
    int roundactive;
    Fruct deadlyfood;
    int deadfoodx;
    int deadfoody;

    void Tick();
    
    public:
    Game();
    void play_game();
};

#endif