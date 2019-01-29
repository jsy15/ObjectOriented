#include "card.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>

std::ostream& operator<<( std::ostream& os, const Suit& suit )
{
   switch( suit )
   {
      case Heart: os << "heart"; break;
      case Club: os << "club"; break;
      case Diamond: os << "diamond"; break;
      case Spade: os << "spade"; break;
   }
}

std::ostream& operator<<( std::ostream& os, const Rank& rank )
{
   switch( rank )
   {
      case two: os << "2"; break;
      case three: os << "3"; break;
      case four: os << "4"; break;
      case five: os << "5"; break;
      case six: os << "6"; break;
      case seven: os << "7"; break;
      case eight: os << "8"; break;
      case nine: os << "9"; break;
      case ten: os << "10"; break;
      case jack: os << "J"; break;
      case queen: os << "Q"; break;
      case king: os << "K"; break;
      case ace: os << "A"; break;
   }
}

class Deck {
    struct Card cards[52];
  public:
    int getRank(int pos){
            return cards[pos+1].rank;
    }
    int getSuit(int pos){
        return cards[pos+1].suit;
    }
    Deck(){
        int index = 0;
        for(int i = 1; i < 5; i++){
            for(int e = 1; e < 14; e++ ){
                int test = 0;
                switch(i) {
                    case 1: cards[index].suit = Heart; 
                        break;
                    case 2: cards[index].suit = Club; 
                        break;
                    case 3: cards[index].suit = Diamond;
                        break;
                    case 4: cards[index].suit = Spade;
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

    void print(){
        for(int i = 0; i < 52; i++){
                std::cout << "The current card at position " << (i+1) << " is : (" << cards[i].suit << "," << cards[i].rank << ")\n";
        }
    }
};


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

}
