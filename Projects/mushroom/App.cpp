#include "App.h"

static App* singleton;

void explode(int value)
{
    if(!singleton->myMushroom->done()){
        singleton->myMushroom->advance();
        singleton->redraw();
        glutTimerFunc(32, explode, value);
    }
}

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h)
{
    // Initialize state variables
    singleton = this;
    mx = 0.0;
    my = 0.0;

    myMushroom = new TexRect("bitmaps/mushroom.bmp", 1, 1, 0, 0.67, 0.5, 0.5);

}

void App::draw() 
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(1.0, 1.0, 1.0);

    myMushroom->draw();

    glDisable(GL_TEXTURE_2D);

    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y)
{
    // Update app state
    mx = x;
    my = y;

    if(!myMushroom->exploded() && myMushroom->contains(mx, my)){
        myMushroom->explode();
        explode(0);
    } 
}

void App::keyPress(unsigned char key) 
{
    if (key == 27){
        delete myMushroom;
        exit(0);
    }else if(key == ' '){
        myMushroom->reset();
        redraw();
    }
}
