#ifndef FRUCT_H
#define FRUCT_H

#include <time.h>
#include <stdlib.h>
#include <iostream>


class Fruct {
        int x;
        int y;

    public:
        Fruct(){
            x = 0;
            y = 0;
        }
        Fruct(int x2, int y2){
            x = x2;
            y = y2;
        }
        Fruct(const Fruct &f2){
            x = f2.x;
            y = f2.y;
        }
        int get_x();
        int get_y();
        void set_x(int);
        void set_y(int);

};

//This class handles the trigger objects which sends out the special food
class Trigger : public Fruct {
        int type;
    public:
        Trigger(){
            type = -1;
        }
        int trigger(){
            srand(time(0));
            type = rand() % 3;
        }
        int getType(){
            return type;
        }
        void setType(int t){
            type = t;
        }
};

//This class handles the food
class DeadlyFood : public Fruct {
    public:
        void activate(int &x, bool &b);
};

//This class handles the multifoods 
class MultiFood : public Fruct {
    public:
        void activate(int & x);
};

//This class handles the superfood
class SuperFood : public Fruct {
    public:
        void activate(int &x, bool &b);
};



#endif