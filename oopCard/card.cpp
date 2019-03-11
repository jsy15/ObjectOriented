#include "card.hpp"
#include <iostream>

Card::Card() { }

Kind Card::get_kind() const {
    return kind;
}

Suit StandardCard::get_suit() const {
    return suit;
}

Rank StandardCard::get_rank() const {
    return rank;
}

Color JokerCard::get_color() const {
    return color;
}

std::ostream& operator<<(std::ostream& os, StandardCard c){
    os << c.get_rank() << c.get_suit();
    return os;
}

std::ostream& operator<<(std::ostream& os, JokerCard c){
    os << c.get_color();
    return os;
}

std::ostream& operator<<(std::ostream& os, Suit s){
    switch (s){
        case 0: os << "S"; break;
        case 1: os << "C"; break;
        case 2: os << "D"; break;
        case 3: os << "H"; break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, Rank r){
    switch (r){
        case 0: os << "A"; break;
        case 1: os << "2"; break;
        case 2: os << "3"; break;
        case 3: os << "4"; break;
        case 4: os << "5"; break;
        case 5: os << "6"; break;
        case 6: os << "7"; break;
        case 7: os << "8"; break;
        case 8: os << "9"; break;
        case 9: os << "T"; break;
        case 10: os << "J"; break;
        case 11: os << "Q"; break;
        case 12: os << "K"; break;
    }    
    return os;
}

std::ostream& operator<<(std::ostream& os, Color c){
    switch (c){
        case 0: os << "B"; break;
        case 1: os << "R"; break;
    }
    return os; 
}

std::ostream& operator<<(std::ostream& os, Kind k){
    switch (k){
        case 0: os << "S"; break;
        case 1: os << "J"; break;
    }
    return os;
}
