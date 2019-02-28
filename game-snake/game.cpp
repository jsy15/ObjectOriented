#include "game.hpp"

#include <iostream>

Game::Game(){
    N = 30;
    M = 20;
    dir = 4;
    num = 4;
    size = 16;
    w = size * N;
    h = size * M;
};

void Game::play_game(){

    RenderWindow window(VideoMode(w, h), "Snake Game!");

    Texture t1, t2;

    t1.loadFromFile("../images/white.png");
    t2.loadFromFile("../images/red.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);

    Clock clock;

    float timer = 0;
    float delay = 0.1;

    f.set_x(10);
    f.set_y(10);

    while(window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left))
            dir = 1;
        if(Keyboard::isKeyPressed(Keyboard::Right))
            dir = 2;
        if(Keyboard::isKeyPressed(Keyboard::Up))
            dir = 3;
        if(Keyboard::isKeyPressed(Keyboard::Down))
            dir = 0;
        if(Keyboard::isKeyPressed(Keyboard::Q))
            return;

        if (timer > delay){
            timer = 0;
            Tick();
        }

        window.clear();

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++){
                sprite1.setPosition(i * size, j * size);
                window.draw(sprite1);
            }
        

        for(int i = 0; i < num; i++){
            sprite2.setPosition(s[i].get_x() * size, s[i].get_y() * size);
            window.draw(sprite2);
        }

        sprite2.setPosition(f.get_x() * size, f.get_y() * size);
        window.draw(sprite2);

        window.display();
    }
    return;
};

void Game::Tick(){
    for(int i = num; i > 0; --i){
        s[i].set_x(s[i - 1].get_x());
        s[i].set_y(s[i - 1].get_y());
    }

    if (dir == 0)
        s[0].set_y(s[0].get_y() + 1);
    if (dir == 1)
        s[0].set_x(s[0].get_x() - 1);
    if (dir == 2)
        s[0].set_x(s[0].get_x() + 1);
    if (dir == 3)
        s[0].set_y(s[0].get_y() - 1);

    if((s[0].get_x() == f.get_x()) && (s[0].get_y() == f.get_y())){
        num++;
        f.set_x(rand() % N);
        f.set_y(rand() % M);
    }

    if(s[0].get_x() > N)
        s[0].set_x(0);
    if(s[0].get_x() < 0)
        s[0].set_x(N);
    if(s[0].get_y() > M)
        s[0].set_y(0);
    if(s[0].get_y() < 0)
        s[0].set_y(M);

    for(int i = 1; i < num; i++)
        if(s[0].get_x() == s[i].get_x() && s[0].get_y() == s[i].get_y())
            num = i;
};