#ifndef GAME_H
#define GAME_H
#include "snake.hpp"
#include "fruct.hpp"
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace sf;

struct event_listener{
    virtual void on_close() { }
    virtual void on_gain_focus() { }
    virtual void on_resize(sf::Event::SizeEvent) { }

    virtual void on_key_press(sf::Event::KeyEvent) { }

};

struct event_source{
    event_source(sf::Window& w)
        : window(&w)
    { }

    void listen(event_listener& l){
        listeners.push_back(&l);
    }

    void poll(){
        sf::Event e;

        while(window->pollEvent(e))
            process(e);
    }
    
    void process(sf::Event const& e){
        switch(e.type) {
            case Event::Closed:
                return notify([e](event_listener* l) {l->on_close(); });

            case Event::Resized:
                return notify([e](event_listener* l) {l->on_resize(e.size); });

            case Event::KeyPressed:
                return notify([e](event_listener* l) {l->on_key_press(e.key); });

            default:
                break;
        }
    }

    template<typename F>
    void notify(F fn){
        for (event_listener* l : listeners)
            fn(l);
    }

    sf::Window* window;

    std::vector<event_listener*> listeners;
};

class Game : event_listener{
    Snake s[100];
    Fruct f;
    Trigger specf;
    Trigger trig;
    SuperFood superfood;
    MultiFood multifood[4];
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
    DeadlyFood deadlyfood;
    int deadfoodx;
    int deadfoody;
    int deadlyfoodround;
    bool deadlyactive;
    RenderWindow window;

    void Tick();
    
    public:
    Game()
        : 
    window(VideoMode(480, 320), "Snake Game!")
    {
        N = 30;
        M = 20;
        dir = 4;
        num = 4;
        size = 16;
        w = size * N;
        h = size * M;
        bool triggeractive = false;
        triggerx = 0;
        triggery = 0;
        test1 = (rand() % N);
        test2 = (rand() % M);
        specx = (rand() % N);
        specy = (rand() % M);
        supfoodx = (rand() % N);
        supfoody = (rand() % M);
        multifood0x = (rand() % N);   
        multifood0y = (rand() % M);
        multifood1x = (rand() % N);
        multifood1y = (rand() % M);
        multifood2x = (rand() % N);
        multifood2y = (rand() % M);
        multifood3x = (rand() % N);
        multifood3y = (rand() % M);
        multiactive = false;
        roundactive = 0;
        deadfoodx = (rand() % N);
        deadfoody = (rand() % M);
        deadlyfoodround = 0;
        deadlyactive = false;
     };
    void play_game();
    void on_close() override;
    void on_key_press(sf::Event::KeyEvent) override;

};

#endif