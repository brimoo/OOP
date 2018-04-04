#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Sortable.h"
using namespace std;

class Circle : public Sortable{

    int radius;

    public:

        Circle(): radius(0){}

        Circle(int r): radius(r){}

        void print(){cout << "Circle with radius: " << radius << endl;}

        bool compare(const Sortable * s){

            const Circle * other = dynamic_cast<const Circle *> (s);

            if(other->radius > radius)
                return true;
            else
                return false;
        }

};




#endif
