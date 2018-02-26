#ifndef SQUARE_H
#define SQUARE_H

class Square{

    float centerX;
    float centerY;
    float length;
    bool  occupied;
    char  occupier;

    public:

        Square(float x, float y, float l){
            centerX = x;
            centerY = y;
            length  = l;
            occupier = '\0';
            occupied = false;
        }

        bool contains(float x, float y){

            if(x >= centerX - (0.5 * length) && x <= centerX + (0.5 * length))
                if(y >= centerY - (0.5 * length) && y <= centerY + (0.5 * length))
                    return true;

            return false;

        }

        float getX(){return centerX;}
        float getY(){return centerY;}
        float getL(){return length;}
        char  getO(){return occupier;}
        bool  isOccupied(){return occupied;}

        void setO(char c){
            occupier = c;
            occupied = true;
        }

};

#endif
