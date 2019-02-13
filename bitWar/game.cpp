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
    for(int i = 0; i < 26; ++i){
        std::cout << "Player 1 Card #" << i+1 << "with card: " << player1.hand.at(i) << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < 26; ++i){

        std::cout << "Player 2 Card # " << i+1 << "with card: " <<  player2.hand.at(i) << std::endl;
    }
}

void Game::shuffle(){
    //Generate random value and use to shuffle the deck randomly.
    std::random_device rng;
    std::minstd_rand prng(rng());
    std::shuffle(d.begin(), d.end(), prng);
    std::cout << d << '\n';

    Card holding1;
    Card holding2;


    //Iterate through deck and give cards alternatively to each player
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
    std::cout << "Player 1 score: " << player1.score << std::endl;
    std::cout << "Player 2 score: " << player2.score << std::endl;
    std::cout << "Total score: " << player1.score + player2.score << std::endl;
}

void Game::war(){
    bool tie = false;


    while(!player1.hand.empty() && !player2.hand.empty()){
        tie = false;
        while(player1.hand.front().get_rank() == player2.hand.front().get_rank()){
            draw.push_back(player1.hand.front());
            draw.push_back(player2.hand.front());
            player1.hand.pop_front();
            player2.hand.pop_front();
            tie = true;
        }
        if(player1.hand.front().get_rank() > player2.hand.front().get_rank()){
            player1.hand.push_back(player1.hand.front());
            player1.hand.push_back(player2.hand.front());
            if(tie){
                while(!draw.empty()){
                    player1.hand.push_back(draw.back());
                    draw.pop_back();
                }
            }
        }
        else if(player1.hand.front().get_rank() < player2.hand.front().get_rank()){
            player2.hand.push_back(player1.hand.front());
            player2.hand.push_back(player2.hand.front());
            if(tie){
                while(!draw.empty()){
                    player2.hand.push_back(draw.back());
                    draw.pop_back();
                }
            }
        }
        std::cout << "Player1 handsize: " << player1.hand.size() << ", Player2 handsize: " << player2.hand.size() << std::endl;
        Card player1hold = player1.hand.front();
        Card player2hold = player2.hand.front();
        player1.hand.pop_front();
        player2.hand.pop_front();


    }
    
}