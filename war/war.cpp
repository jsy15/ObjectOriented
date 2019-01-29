#include "card.hpp"
#include "deck.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>




int main(){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::vector<int> randDeckOrder;
    for(int x = 0; x < 52; x++)
    {
        randDeckOrder.push_back(x);
    }
    std::shuffle(randDeckOrder.begin(), randDeckOrder.end(), e);
       

    Deck deck;

    int player1score = 0;
    int player2score = 0;

    for(int x = 0; x < 26; x++)
    {
        int card1 = randDeckOrder.at(randDeckOrder.size()-1);
        int card2 = randDeckOrder.at(randDeckOrder.size()-2);
        int card1rank = deck.getRank(card1);
        int card2rank = deck.getRank(card2);

        randDeckOrder.pop_back();
        randDeckOrder.pop_back();

        std::cout << "Player 1 has played the card: " << card1rank << "\n";
        std::cout << "Player 2 has played the card: " << card2rank << "\n";
        if(card1rank > card2rank){
            std::cout << "Player 1 has won the hand\n";
            player1score++;
        }
        else if(card1rank < card2rank){
            std::cout << "Player 2 has won the hand\n";
            player2score++;
        }
        else{
            std::cout << "The hand ended in a draw\n";
        }

    }

    std::cout << "----------------\n";

    std::cout << "Player 1 score: " << player1score << " || Player 2 score: " << player2score << "\n";

    if(player1score > player2score){
        std::cout << "Player 1 has won the game!\n";
    }
    else if(player1score < player2score){
        std::cout << "Player 2 has won the game!\n";
    }
    else{
        std::cout << "The game has ended in a draw!\n";
    }
    

    return 0;
}
