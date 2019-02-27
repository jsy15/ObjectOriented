#include "card.hpp"
#include <iostream>

int main(){
    // Card c{Ace, Spades};
    // std::cout << c.get_suit() << std::endl;
    // std::cout << c.get_rank() << std::endl; 
    // Card c1{Two, Spades};
    // std::cout << c1.get_suit() << std::endl;
    // std::cout << c1.get_rank() << std::endl;
    // Card c2{Three, Spades};
    // std::cout << c2.get_suit() << std::endl;
    // std::cout << c2.get_rank() << std::endl;
    // std::cout << c2.get_color() << std::endl;

    Card c3{Black};
    std::cout << c3.get_color() << std::endl;

    Card c4{Red};
    std::cout << c4.get_color() << std::endl;
}
