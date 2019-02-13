#include "game.hpp"
#include <iostream>
#include <random>
#include <algorithm>

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
    std::deque<Card>::iterator it = d.begin();
    while(it != d.end()){
        holding1 = d.front();
        d.pop_front();
        holding2 = d.front();
        d.pop_front();
        player1.hand.push_back(holding1);
        player2.hand.push_back(holding2);
        it++;
    }
}

void Game::play_game(){
    std::cout << d << '\n';
    shuffle();
    print();
    war(0);
    std::cout << "Player 1 score: " << player1.score << std::endl;
    std::cout << "Player 2 score: " << player2.score << std::endl;
}

void Game::war(int score){
    std::cout << "Place is set to: " << place << '\n';
    if(place < 26){
        if(player1.hand.at(place).get_rank() > player2.hand.at(place).get_rank()){
            player1.score = player1.score + score + 1;
            std::cout << "Player 1 won the hand! Player 1 score is now: " << player1.score << ", and updating the score with: " << score + 1 <<"\n";
            place++;
            war(0);
        }
        else if(player1.hand.at(place).get_rank() < player2.hand.at(place).get_rank()){
            player2.score = player2.score + score + 1;
            std::cout << "Player 2 won the hand! Player 2 score is now: " << player2.score << ", and updating the score with: " << score + 1 << "\n";
            place++;
            war(0);
        }
        else{
            std::cout << "Draw: " << player1.hand.at(place) << " and " << player2.hand.at(place) << std::endl;
            //player1.hand.pop_at(place);
            //player2.hand.pop_at(place);
            place++;
            war(1);

        }
    }
}