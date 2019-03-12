#include "card.hpp"
#include <iostream>

int main(){

    //Ability to print a standard card
    std::cout << "Ability to print a standard card\n";
    StandardCard sc1(King, Hearts);
    std::cout << sc1.get_rank() << sc1.get_suit() << std::endl;
    std::cout << sc1 << std::endl;

    //Abiltiy to print a joker card
    std::cout << "Abiltiy to print a joker card\n";
    JokerCard jc1(Red);
    std::cout << jc1 << std::endl;

    //Ability to query color of joker card
    std::cout << "\nAbility to query color of joker card\n";
    JokerCard jc(Red);
    std::cout << jc.get_color() << std::endl;
    std::cout << jc << std::endl;
    JokerCard jc2(Black);
    std::cout << jc2.get_color() << std::endl;
    std::cout << jc2 << std::endl;
}