#include "game.hpp"
#include <iostream>

int main(){

    std::cout << "This will simulate the game of war to completion,\nhowever, the game can take a very long time to run.\nIf it takes a long time, simply cancel the program and restart it.\n";
    std::cout << "Press enter to start the game\n";
    std::cin.get();
    
    //Creates the Deck object and starts the game of war
    Game game;
    game.play_game();  
    
}
