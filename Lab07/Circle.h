#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

class Circle{

    double x, y, r;

    public:

        double area;

        Circle(): x(0.0), y(0.0), r(1.0){area = M_PI * r * r;}

        Circle(double x, double y, double r){
            this->x = x;
            this->y = y;
            this->r = r;
            area = M_PI * r * r;
        }

        void setX(double x){this->x = x;}
        void setY(double y){this->y = y;}
        void setR(double r){
            this->r = r;
            area = M_PI * r * r;
        }

        double getX(){return x;}
        double getY(){return y;}
        double getR(){return r;}

};

#endif
