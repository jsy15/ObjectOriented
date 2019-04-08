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
    bool triggeractive = false;
    triggerx = 0;
    triggery = 0;
    test1 = rand() % N;
    test2 = rand() % M;
    specx = rand() % N;
    specy = rand() % M;
    supfoodx = rand() % N;
    supfoody = rand() % M;
    multifood0x = rand() % N;   
    multifood0y = rand() % M;
    multifood1x = rand() % N;
    multifood1y = rand() % M;
    multifood2x = rand() % N;
    multifood2y = rand() % M;
    multifood3x = rand() % N;
    multifood3y = rand() % M;
    setspecial = false;
};

void Game::play_game(){

    RenderWindow window(VideoMode(w, h), "Snake Game!");

    Texture t1, t2, t3, t4, t5, t6, t7, t8;

    t1.loadFromFile("../images/white.png");
    t2.loadFromFile("../images/red.png");
    t3.loadFromFile("../images/purple.png");
    t4.loadFromFile("../images/turquoise.png");
    t5.loadFromFile("../images/pink.png");
    t6.loadFromFile("../images/pink.png");
    t7.loadFromFile("../images/pink.png");
    t8.loadFromFile("../images/pink.png");
    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);
    Sprite sprite4(t4);
    Sprite sprite5(t5);
    Sprite sprite6(t6);
    Sprite sprite7(t7);
    Sprite sprite8(t8);

    Clock clock;

    float timer = 0;
    float delay = 0.1;

    f.set_x(10);
    f.set_y(10);
    specf.set_x(-1);
    specf.set_y(-1);
    superfood.set_x(-1);
    superfood.set_y(-1);
    for(int i = 0; i < 4; ++i){
        multifood[i].set_x(-1);
        multifood[i].set_y(-1);
    }

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
        sprite3.setPosition(specf.get_x() * size, specf.get_y() * size);
        sprite4.setPosition(superfood.get_x() * size, superfood.get_y() * size);
        sprite5.setPosition(multifood[0].get_x() * size, multifood[0].get_y() * size);
        sprite6.setPosition(multifood[1].get_x() * size, multifood[1].get_y() * size);
        sprite7.setPosition(multifood[2].get_x() * size, multifood[2].get_y() * size);
        sprite8.setPosition(multifood[3].get_x() * size, multifood[3].get_y() * size);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.draw(sprite5);
        window.draw(sprite6);
        window.draw(sprite7);
        window.draw(sprite8);


        window.display();
    }
    return;
};

void Game::Tick(){
    int specialfood = 1;
    test1 = rand() % N;
    test2 = rand() % M;
    specx = rand() % N;
    specy = rand() % M;
    supfoodx = rand() % N;
    supfoody = rand() % M;
    multifood0x = rand() % N;   
    multifood0y = rand() % M;
    multifood1x = rand() % N;
    multifood1y = rand() % M;
    multifood2x = rand() % N;
    multifood2y = rand() % M;
    multifood3x = rand() % N;
    multifood3y = rand() % M;

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
        while(test1 == specx && test2 == specy || test1 == supfoodx && test2 == supfoody || test1 == multifood0x && test2 == multifood0y || test1 == multifood1x && test2 == multifood1y || test1 == multifood2x && test2 == multifood2y || test1 == multifood3x && test2 == multifood3y){
            test1 == rand() % N;
            test2 == rand() % M;
        }
        f.set_x(test1);
        f.set_y(test2);
        std::cout << "I have set the x to : " << test1 << ", and the y to: " << test2 << std::endl;
        if(specialfood == 1 && triggeractive == false){
            while(f.get_x() == specx && f.get_y() == specy){
                specx = rand() % N;
                specy = rand() % M;
            }
            specf.set_x(specx);
            specf.set_y(specy);
            std::cout << "Specf x: " << specf.get_x() << ", specf y: " << specf.get_y() << std::endl;
            triggeractive = true;
            setspecial = true;
        }
    }

    if((s[0].get_x() == specf.get_x()) && (s[0].get_y() == specf.get_y())){
        specf.set_x(-1);
        specf.set_y(-1);
        specf.trigger();
        std::cout << "The type of the trigger is: " << specf.getType() << std::endl;
        switch(specf.getType()){
            //Multiple food path
            case 0:
            std::cout << "Multifood\n";
                multifood[0].set_x(multifood0x);
                multifood[0].set_y(multifood0x);
                multifood[1].set_x(multifood1x);
                multifood[1].set_y(multifood1y);
                multifood[2].set_x(multifood0x);
                multifood[2].set_y(multifood2y);
                multifood[3].set_x(multifood3x);
                multifood[3].set_y(multifood3y);
                break;
            //Superfood path
            case 1:
                std::cout << "Superfood x: " << supfoodx << ", Superfood y: " << supfoody << std::endl;
                superfood.set_x(supfoodx);
                superfood.set_y(supfoody);          
                break;
            default:
                std::cout << "You should not have run\n";
                break;
        }
    }

    

    if(s[0].get_x() == superfood.get_x() && s[0].get_y() == superfood.get_y()){
        setspecial = false;
        superfood.set_x(-2);
        superfood.set_y(-2);
        specf.setType(-1);
        std::cout << "Snake is growing\n";
        triggeractive = false;
    }


    if(s[0].get_x() == multifood[0].get_x() && s[0].get_y() == multifood[0].get_y()){
        std::cout << "The first multifood eaten\n";
        multifood[0].set_x(-3);
        multifood[0].set_y(-3);
        specf.setType(-1);
    }

    if(s[0].get_x() == multifood[1].get_x() && s[0].get_y() == multifood[1].get_y()){
        std::cout << "The second multifood eaten\n";
        multifood[1].set_x(-3);
        multifood[1].set_y(-3);
        specf.setType(-1);
    }

    if(s[0].get_x() == multifood[2].get_x() && s[0].get_y() == multifood[2].get_y()){
        std::cout << "The third multifood eaten\n";
        multifood[2].set_x(-3);
        multifood[2].set_y(-3);
        specf.setType(-1);
    }

    if(s[0].get_x() == multifood[3].get_x() && s[0].get_y() == multifood[3].get_y()){
        std::cout << "The four multifood eaten\n";
        multifood[3].set_x(-3);
        multifood[3].set_y(-3);
        specf.setType(-1);
    }

    if(multifood[0].get_x() == -3 && multifood[1].get_x() == -3 && multifood[2].get_x() == -3 && multifood[3].get_x() == -3){
        triggeractive = false;
        setspecial = false;
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