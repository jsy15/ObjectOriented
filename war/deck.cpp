#include "deck.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>

//Return the rank fo a card at a given position
Rank Deck::getRank(int pos){
            return cards[pos+1].rank;
    }

//Return the suit of a card at a given postion
Suit Deck::getSuit(int pos){
        return cards[pos+1].suit;
    }

Deck::Deck(){
        //Fill the deck with all possible card values of a deck
        int index = 0;
        for(int i = 1; i < 5; i++){
            for(int e = 1; e < 14; e++ ){
                int test = 0;
                switch(i) {
                    case 1: cards[index].suit = Hearts; 
                        break;
                    case 2: cards[index].suit = Clubs; 
                        break;
                    case 3: cards[index].suit = Diamonds;
                        break;
                    case 4: cards[index].suit = Spades;
                        break;

                }
                switch(e) {
                    case 1: cards[index].rank = two; 
                        break;
                    case 2: cards[index].rank = three; 
                        break;
                    case 3: cards[index].rank = four;
                        break;
                    case 4: cards[index].rank = five;
                        break;
                    case 5: cards[index].rank = six;
                        break;
                    case 6: cards[index].rank = seven;
                        break;
                    case 7: cards[index].rank = eight;
                        break;
                    case 8: cards[index].rank = nine;
                        break;
                    case 9: cards[index].rank = ten;
                        break;
                    case 10: cards[index].rank = jack;
                        break;
                    case 11: cards[index].rank = queen;
                        break;
                    case 12: cards[index].rank = king;
                        break;
                    case 13: cards[index].rank = ace;
                        break;                                 
                }
                index++;
            }
        }
    }

void Deck::print(){
        for(int i = 0; i < 52; i++){
                std::cout << "The current card at position " << (i+1) << " is : (" << cards[i].suit << "," << cards[i].rank << ")\n";
        }
    }

    void Deck::playWar(){

        //Creates a random seed for the randomization of the deck
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);

        //Creates a vector for teh random deck order. Loads the Vector with values for all possible cards in deck
        std::vector<int> randDeckOrder;
        for(int x = 0; x < 52; x++)
        {
            randDeckOrder.push_back(x);
        }
        std::shuffle(randDeckOrder.begin(), randDeckOrder.end(), e);
        

        Deck deck;

        //Starting player scores
        int player1score = 0;
        int player2score = 0;

        //Main loop splits deck in half and grabs two cards from the deck and checks to see who wins the hand
        for(int x = 0; x < 26; x++)
        {
            //Get two cards
            int card1 = randDeckOrder.at(randDeckOrder.size()-1);
            int card2 = randDeckOrder.at(randDeckOrder.size()-2);
            int card1rank = deck.getRank(card1);
            int card2rank = deck.getRank(card2);

            //Remove the two cards from the vector
            randDeckOrder.pop_back();
            randDeckOrder.pop_back();

            //Output the cards played to the console
            std::cout << "Player 1 has played the card: " << deck.getRank(card1) << " of " << deck.getSuit(card1) << "\n";
            std::cout << "Player 2 has played the card: " << deck.getRank(card2) << " of " << deck.getSuit(card2) << "\n";

            //Logic to determine the winner of the hand
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

        //Final Score output and winner detection
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
    }