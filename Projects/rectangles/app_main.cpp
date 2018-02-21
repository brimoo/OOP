#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Rect.h"

// Global variables for rectangle vector and window size
int width = 800, height = 800, numRectangles = 8;
std::vector<Rect *> rectangles;

void onClick(int button, int state, int x, int y){

    float tx = x;
    float ty = y;
    float mx =  (tx / 400 - 1.0);
    float my = -(ty / 400 - 1.0);

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        // Randomize the color of any rectangle containing the point
        for(int i = numRectangles - 1; i >= 0; i--){
            if(rectangles[i]->contains(mx, my)){
               rectangles[i]->randomize();
               break;
            }
        }

        // Tell OpenGL to call the display func again
        glutPostRedisplay();

    }

}

void onPress(unsigned char key, int x, int y){

    if(key == 27){
        rectangles.clear();
        exit(0);
    }

}

void drawScene(){

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < numRectangles; i++){
        glColor3f(rectangles[i]->getR(), rectangles[i]->getG(), rectangles[i]->getB());
        glRectf(rectangles[i]->getX(),  rectangles[i]->getY(), 
                rectangles[i]->getX() + rectangles[i]->getW(), 
                rectangles[i]->getY() - rectangles[i]->getH());
    }

    glutSwapBuffers();

}

int main(int argc, char** argv){

    // Populate the vector with randomly sized and colored rectangles
    srand (static_cast <unsigned> (time(0)));
    for(int i = 0; i < numRectangles; i++){
        Rect * R = new Rect();
        rectangles.push_back(R);
    }

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    // Setup window
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("OpenGL - Rectangles");
    glutDisplayFunc(drawScene);

    // Handle mouse input
    glutMouseFunc(onClick);

    // Handle keyboard input (for closing cleanly)
    glutKeyboardFunc(onPress);

    // Start main loop
    glutMainLoop();

    return 0;

}
