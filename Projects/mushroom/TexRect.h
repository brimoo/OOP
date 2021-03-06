#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"

class TexRect 
{

    float x;
    float y;
    float w;
    float h;

    GLuint texture_id;
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
    bool isExploded;

public:

    TexRect (const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();

    void explode(const char* filename, int row, int col);
     
    void reset(const char* filename, int row,int col);

    bool contains(float x, float y);

    bool exploded();

};

#endif
