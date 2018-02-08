#include <GL/freeglut.h>

// Global variables for window size and offset(to center my name in the window)
int width = 800, height = 800;
float OS = 0.0725;

void drawName(){

    // Using glRectf since it is identical to using GL_POLYGONS, but is much cleaner

    glClearColor(0.11, 0.12, 0.13, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Begin letter 'B'

    glColor3f(0.93, 0.37, 0.4);
    glRectf(-0.9  + OS, -0.3,  -0.88 + OS,  0.3);
    glRectf(-0.88 + OS,  0.3,  -0.55 + OS,  0.28);
    glRectf(-0.55 + OS,  0.28, -0.57 + OS, -0.3);
    glRectf(-0.57 + OS, -0.3,  -0.9  + OS, -0.28);
    glRectf(-0.9  + OS,  0.01, -0.55 + OS, -0.01);

    // Adding the 'B' curve shape
    
    glBegin(GL_POLYGON);
        glVertex2f(-0.6575 + OS,   0.0);
        glVertex2f(-0.55   + OS,   0.06);
        glVertex2f(-0.55   + OS,  -0.06);
    glEnd();

    glColor3f(0.11, 0.12, 0.13);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6175 + OS,  0.0);
        glVertex2f(-0.55   + OS,  0.04);
        glVertex2f(-0.55   + OS, -0.04);
    glEnd();

    // End letter 'B'
    
    // Begin leter 'r'

    glColor3f(0.6, 0.78, 0.58);
    glRectf(-0.5 + OS, -0.3,  -0.48  + OS,  0.0);
    glRectf(-0.5 + OS,  0.01, -0.275 + OS, -0.01);

    // End letter 'r'
    
    // Begin letter 'i'

    glColor3f(0.98, 0.78, 0.39);
    glRectf(-0.225 + OS, -0.3,  -0.205 + OS, 0.01);
    glRectf(-0.225 + OS,  0.14, -0.205 + OS, 0.16);

    // End letter 'i'
    
    // Start letter 'a'

    glColor3f(0.4, 0.6, 0.8);
    glRectf(-0.145 + OS, -0.3, -0.125 + OS,  0.01);
    glRectf(-0.125 + OS,  0.01, 0.205 + OS, -0.01);
    glRectf( 0.185 + OS, -0.01, 0.205 + OS, -0.3);
    glRectf(-0.145 + OS, -0.3,  0.205 + OS, -0.28);

    // Adding letter 'a' tail

    glBegin(GL_POLYGON);
        glVertex2f(0.185 + OS,  0.0);
        glVertex2f(0.205 + OS,  0.01);
        glVertex2f(0.355 + OS, -0.29);
        glVertex2f(0.338 + OS, -0.3);
    glEnd();

    // End letter 'a'
    
    // Start letter 'n'
    
    glColor3f(0.77, 0.58, 0.77);
    glRectf(0.405 + OS, -0.3,  0.425 + OS,  0.01);
    glRectf(0.425 + OS,  0.01, 0.755 + OS, -0.01);
    glRectf(0.755 + OS, -0.01, 0.735 + OS, -0.3);

    // End letter 'n'

    glFlush();

}

int main(int argc, char** argv){

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);

    // Setup window
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("OpenGL - Rendering my Name");
    glutDisplayFunc(drawName);

    // Start main loop
    glutMainLoop();

    return 0;

}
