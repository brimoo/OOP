#include <cstdlib>

class Rect{

    float upLeftX, upLeftY, r, g, b, width, height;

    public:

        float randomNum(float a, float b){

            return ((b - a) * ((float)rand() / RAND_MAX)) + a;

        }

        Rect(){

            // Generate random values for all rectangle attributes
            upLeftX = randomNum(-0.8, 0.8);
            upLeftY = randomNum(-0.8, 0.8);
            width   = randomNum(0.1, 1.0 - upLeftX);
            height  = randomNum(0.1, 1.0 + upLeftY);
            r       = randomNum(0.0, 1.0);
            g       = randomNum(0.0, 1.0);
            b       = randomNum(0.0, 1.0); 

        }

        bool contains(float x, float y){

            // Check if rectangle contains point (x, y)
            if(x >= upLeftX && x <= upLeftX + width)
                if(y <= upLeftY && y >= upLeftY - height)
                    return true;

            return false;

        }

        void randomize(){

            // Randomize the color of the rectangle
            r       = randomNum(0.0, 1.0);
            g       = randomNum(0.0, 1.0);
            b       = randomNum(0.0, 1.0); 

        }

        float getR(){return r;}
        float getG(){return g;}
        float getB(){return b;}
        float getX(){return upLeftX;}
        float getY(){return upLeftY;}
        float getW(){return width;}
        float getH(){return height;}

};
