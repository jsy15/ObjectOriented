# ObjectOriented
Repository for Object Oriented Class

## Practice 3: 
    bitWar/ is the directory

    To build:
        1. mkdir build
        2. cd build
        3. cmake ..
        4. make
    To run:
        1. ./war


## Practice 4:
    jokerUnion/ is the directory for the tagged union implementation of the joker and standard cards
    jokerBinary/ is the directory for the binary implementation of the joker and standard cards

## Project (milestone 2):
    game-snake/ is the directory
    Updated game-snake/ with header/source pairs.

    To build:
        Make sure you are in the game-snake directory
        1. mkdir build
        2. cd build
        3. cmake ..
        4. make
     To run:
        While in the build directory
        1. ./snake

    To quit the game simple hit the q button 

## Practice 5:
    oopCard/ is the directory

    To build:
        1. mkdir build
        2. cd build
        3. cmake ..
        4. make
    To run:
        1. ./card

## Practice 5:
    json/ is the directory

    Make sure that the test json file is downloaded:
        1. wget www.reddit.com/r/cpp.json
    To build:
        1. mkdir build
        2. cd build
        3. cmake ..
        4. make
    To run:
        1. ./json < cpp.json

## Project (Milestone 2)
    /snake-Milestone2 is the directory

    To build:
        1. mkdir build
        2. cd build
        3. cmake ..
        4. make
    To run:
        1. ./snake

    This extended version of snake has several new foods.
        1. The purple trigger food activates a special food block
        2. The turquoise food is a superfood that gives the player 3 snake lives
        3. The pink food appears in groups of 4 and each give a life
        4. The green food is a deadlyfood which removes 4 lifes and disappears after four regular food is piccked up.

    Each food and trigger is derived from the Fruct class which is the default food. Each special food has its own activate functions. The functions handles manipulating the snake and unlocking the trigger food.