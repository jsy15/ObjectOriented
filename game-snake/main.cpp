#include "game.hpp"
#include <time.h>
#include <iostream>

int main(){
  srand(time(0));
  Game g;
  g.play_game();

  std::cout << "The play game has ended\n";
}