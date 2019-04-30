#include "fruct.hpp"

int Fruct::get_x(){
    return x;
};

int Fruct::get_y(){
    return y;
};

void Fruct::set_x(int newx){
    x = newx;
};

void Fruct::set_y(int newy){
    y = newy;
};

void DeadlyFood::activate(int &x, bool &b){
    for(int i = 0; i < 3; i++){
        if(x > 1){
            x--;
        }
    }
    b = false;
}

void MultiFood::activate(int &x){
    x++;
}

void SuperFood::activate(int &x, bool &b){
    x++;
    x++;
    x++;
    b = false;
}
