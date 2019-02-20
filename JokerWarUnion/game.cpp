#include "game.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <deque>

Game::Game(){
    d = {
        {Ace, Spades},
        {Two, Spades},
        {Three, Spades},
        {Four, Spades},
        {Five, Spades},
        {Six, Spades},
        {Seven, Spades},
        {Eight, Spades},
        {Nine, Spades},
        {Ten, Spades},
        {Jack, Spades},
        {Queen, Spades},
        {King, Spades},
        {Ace, Clubs},
        {Two, Clubs},
        {Three, Clubs},
        {Four, Clubs},
        {Five, Clubs},
        {Six, Clubs},
        {Seven, Clubs},
        {Eight, Clubs},
        {Nine, Clubs},
        {Ten, Clubs},
        {Jack, Clubs},
        {Queen, Clubs},
        {King, Clubs},
        {Ace, Diamonds},
        {Two, Diamonds},
        {Three, Diamonds},
        {Four, Diamonds},
        {Five, Diamonds},
        {Six, Diamonds},
        {Seven, Diamonds},
        {Eight, Diamonds},
        {Nine, Diamonds},
        {Ten, Diamonds},
        {Jack, Diamonds},
        {Queen, Diamonds},
        {King, Diamonds},
        {Ace, Hearts},
        {Two, Hearts},
        {Three, Hearts},
        {Four, Hearts},
        {Five, Hearts},
        {Six, Hearts},
        {Seven, Hearts},
        {Eight, Hearts},
        {Nine, Hearts},
        {Ten, Hearts},
        {Jack, Hearts},
        {Queen, Hearts},
        {King, Hearts}
    };
}

void Game::print(){
    for(int i = 0; i < player1.hand.size(); ++i){
        std::cout << "Player 1 StandardCard #" << i+1 << "with StandardCard: " << player1.hand.at(i) << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < player2.hand.size(); ++i){

        std::cout << "Player 2 StandardCard # " << i+1 << "with StandardCard: " <<  player2.hand.at(i) << std::endl;
    }
}

void Game::shuffle(){
    //Generate random value and use to shuffle the deck randomly.
    std::random_device rng;
    std::minstd_rand prng(rng());
    std::shuffle(d.begin(), d.end(), prng);
    std::cout << d << '\n';

    StandardCard holding1;
    StandardCard holding2;


    //Iterate through deck and give StandardCards alternatively to each player
    while(!d.empty()){
        holding1 = d.front();
        d.pop_front();
        holding2 = d.front();
        d.pop_front();
        player1.hand.push_back(holding1);
        player2.hand.push_back(holding2);
    }
}

void Game::play_game(){
    std::cout << d << '\n';
    shuffle();
    print();
    war();
}

void Game::war(){
    bool isGameOver = false;
    bool isSameRank = false;
    int steps = 0;

    while(!isGameOver){
        steps++;
        isSameRank = false;

        std::cout << player1.hand.front() << " vs " << player2.hand.front() << std::endl;
        if(player1.hand.front().get_rank() == player2.hand.front().get_rank()){
            std::cout << "MATCH\n";
            isSameRank = true;            
        }

        if(isSameRank && player1.hand.size() <= 3){
            std::cout << "Player 1 does not have enough StandardCards to war, Player 2 wins! \n";
            std::cout << "The game has run for " << steps << " steps.\n";
            return;
        }
        else if(isSameRank && player2.hand.size() <= 3){
            std::cout << "Player 2 does not have enough StandardCards to war, Player 1 wins!\n";
            std::cout << "The game has run for " << steps << " steps.\n";
            return;
        }

        while((player1.hand.front().get_rank() == player2.hand.front().get_rank()) && (player1.hand.size() > 3 && player2.hand.size() > 3)){ 
            for(int x = 0; x < 3; ++x){           
            draw.push_back(player1.hand.front());
            player1.hand.pop_front();
            draw.push_back(player2.hand.front());
            player2.hand.pop_front();        
            }
        }

        if(isSameRank){
            if(player1.hand.front().get_rank() > player2.hand.front().get_rank()){
                std::cout << "Player 1 won the war\n";
                for(std::vector<StandardCard>::iterator it = draw.begin(); it != draw.end(); ++it){
                    player1.hand.push_back((*it));
                }
                player1.hand.push_back(player1.hand.front());
                player1.hand.pop_front();
                player1.hand.push_back(player2.hand.front());
                player2.hand.pop_front();
            }
            else if(player1.hand.front().get_rank() < player2.hand.front().get_rank()){
                std::cout << "Player 2 won the war\n";
                for(std::vector<StandardCard>::iterator it = draw.begin(); it != draw.end(); ++it){
                    player2.hand.push_back((*it));
                }
                player2.hand.push_back(player2.hand.front());
                player2.hand.pop_front();
                player2.hand.push_back(player1.hand.front());
                player1.hand.pop_front();
            }
        }
        else{
            if(player1.hand.front().get_rank() > player2.hand.front().get_rank()){
                std::cout << "Player 1 has won the hand!\n";
                player1.hand.push_back(player1.hand.front());
                player1.hand.push_back(player2.hand.front());
                player1.hand.erase(player1.hand.begin());
                player2.hand.erase(player2.hand.begin());
            }
            else{
                std::cout << "Player 2 has won the hand!\n";
                player2.hand.push_back(player1.hand.front());
                player2.hand.push_back(player2.hand.front());
                player2.hand.erase(player2.hand.begin());
                player1.hand.erase(player1.hand.begin());
            }
        }
        draw.clear();
        ;

        if((player1.hand.size() <= 0 || player2.hand.size() <= 0)|| (player1.hand.size() == 52 || player2.hand.size() == 52)){
            isGameOver = true;
        }
    }
    if(player1.hand.size() == 52){
        std::cout << "Player 1 has won the game!\n";
        std::cout << "The game has run for " << steps << " steps.\n";
    }
    else{
        std::cout << "Player 2 has won the game\n";
        std::cout << "The game has run for " << steps << " steps.\n";
    }
}