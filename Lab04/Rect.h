#include "Vec.h"

class Rect{

    float upLeftX;
    float upLeftY;
    float width;
    float height;

    public:

        Rect(float upLeftX, float upLeftY, float width, float height){

            this->upLeftX = upLeftX;
            this->upLeftY = upLeftY;
            this->width   = width;
            this->height  = height;

        }

        bool contains(Vec v){

            if(v.getX() >= upLeftX && v.getX() <= upLeftX + width)
                if(v.getY() <= upLeftY && v.getY() >= upLeftY - height)
                    return true;

            return false;

        }

};
