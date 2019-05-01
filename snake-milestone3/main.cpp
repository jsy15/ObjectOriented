#include "game.hpp"
#include "fruct.hpp"
#include <time.h>
#include <iostream>
#include <stdlib.h>

int main(){


  srand(time(0));
  Game g;
  event_source events(g.window);
  events.listen(g);
  std::cout << "deadly pos: " << g.deadlyfood.get_x() << " " << g.deadlyfood.get_y() << std::endl;


  while(g.is_open()){
    events.poll();
    g.play_game();
  }
  

  std::cout << "The play game has ended\n";
}