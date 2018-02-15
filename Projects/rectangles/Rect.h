#include <cstdlib>

class Rect{

    float upLeftX, upLeftY, r, g, b, width, height;

    public:

        Rect(){

            upLeftX = ((2.0) * ((float)rand() / RAND_MAX)) + (-1.0);
            upLeftY = ((2.0) * ((float)rand() / RAND_MAX)) + (-1.0);
            width   = 0.2 + (rand() / ( RAND_MAX / (upLeftX - 1.0 - 0.2)));  
            height  = 0.2 + (rand() / ( RAND_MAX / (upLeftY + 1.0 - 0.2)));
            r       = rand() / (RAND_MAX + 1.);
            b       = rand() / (RAND_MAX + 1.);
            g       = rand() / (RAND_MAX + 1.); 

        }

        bool contains(float x, float y){

            if(x >= upLeftX && x <= upLeftX + width)
                if(y <= upLeftY && y >= upLeftY - height)
                    return true;

            return false;

        }

        float getR(){return r;}
        float getG(){return g;}
        float getB(){return b;}
        float getX(){return upLeftX;}
        float getY(){return upLeftY;}
        float getW(){return width;}
        float getH(){return height;}

};
