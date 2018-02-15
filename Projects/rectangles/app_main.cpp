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


}

void drawScene(){

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < numRectangles; i++){
        glColor3f(rectangles[i]->getR(), rectangles[i]->getG(), rectangles[i]->getB());
        glRectf(rectangles[i]->getX(),  rectangles[i]->getY(), 
                rectangles[i]->getX() + rectangles[i]->getW(), 
                rectangles[i]->getY() - rectangles[i]->getH());
    }

    glFlush();

}

int main(int argc, char** argv){

    // Populate the vector with randomly sized rectangles
    srand (static_cast <unsigned> (time(0)));
    for(int i = 0; i < numRectangles; i++){
        Rect * R = new Rect();
        std::cout << "Postiion: (" << R->getX() << ", " << R->getY() << ")" << std::endl; 
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

    // Start main loop
    glutMainLoop();

    return 0;

}
