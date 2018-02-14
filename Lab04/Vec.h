#include <iostream>

class Vec{

    float x;
    float y;

    public:

        Vec(float x, float y){
            this->x = x;
            this->y = y;
        }

        Vec(){
            x = 0.0;
            y = 0.0;
        }

        float getX() const {return x;}
        float getY() const {return y;}
        void setX(float x){this->x = x;}
        void setY(float y){this->y = y;}

        void add(Vec u){    
            x += u.x;
            y += u.y;
        }

        void print(){std::cout << "(" << x << ", " << y << ")" << std::endl;}
    
};
