#ifndef FRUCT_H
#define FRUCT_H

class Fruct{
        int x;
        int y;

    public:
        Fruct(){
            x = 0;
            y = 0;
        }
        int get_x();
        int get_y();
        int set_x(int);
        int set_y(int);

};

#endif