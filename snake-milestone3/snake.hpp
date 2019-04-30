#ifndef SNAKE_H
#define SNAKE_H

class Snake{
        int x;
        int y;

    public:
        Snake(){
            x = 0;
            y = 0;
        }
        int get_x();
        int get_y();
        int set_x(int);
        int set_y(int);

};

#endif