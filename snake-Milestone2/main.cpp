#include "game.hpp"
#include "fruct.hpp"
#include <time.h>
#include <iostream>
#include <stdlib.h>

int main(){
  srand(time(0));
  Game g;
  g.play_game();
  

  std::cout << "The play game has ended\n";
}