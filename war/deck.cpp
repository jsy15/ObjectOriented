#include "deck.hpp"

int Deck::getRank(int pos){
            return cards[pos+1].rank;
    }

int Deck::getSuit(int pos){
        return cards[pos+1].suit;
    }

Deck::Deck(){
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

void Deck::print(){
        for(int i = 0; i < 52; i++){
                std::cout << "The current card at position " << (i+1) << " is : (" << cards[i].suit << "," << cards[i].rank << ")\n";
        }
    }