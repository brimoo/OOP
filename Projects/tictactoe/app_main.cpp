#include <GL/freeglut.h>
#include <vector>
#include "Square.h"

#define PLAYER_SELECT 0
#define PLAYING       1 
#define GAME_OVER     2

// Global variables for game board, number of players, window size, and state
int width = 800, height = 800, players, gameState;
Square oneP(-0.5, 0.0, 0.5), twoP(0.5, 0.0, 0.5);
std::vector<Square> board;

void onClick(int button, int state, int x, int y){

    float tx = x;
    float ty = y;
    float mx =  (tx / 400 - 1.0);
    float my = -(ty / 400 - 1.0);

}

void onPress(unsigned char key, int x, int y){

    if(key == 27){
        exit(0);
    }

}

void drawSquare(Square s){

    glRectf(s.getX() - (0.5 * s.getL()), s.getY() - (0.5 * s.getL()), 
            s.getX() + (0.5 * s.getL()), s.getY() + (0.5 * s.getL()));

}

void drawBoard(){


}

void drawPlayerSelect(){

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the squares
    glColor3f(0.0, 1.0, 0.0);
    drawSquare(oneP);
    drawSquare(twoP);

    glColor3f(0.0, 0.0, 0.0);

    // Draw 1
    glRectf(-0.51, 0.2, -0.49, -0.2);

    // Draw 2
    glRectf(0.3, 0.01, 0.7, -0.01);
    glRectf(0.3, -0.01, 0.32, -0.2);
    glRectf(0.32, -0.18, 0.7, -0.2);
    glRectf(0.7, 0.01, 0.68, 0.2);
    glRectf(0.68, 0.2, 0.3, 0.18);

    glutSwapBuffers();

}

int main(int argc, char** argv){

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);

    // Setup window
    glutInitWindowPosition(20, 60);
    glutInitWindowSize(width, height);
    glutCreateWindow("OpenGL - Tic-Tac-Toe");
    gameState = PLAYER_SELECT;
    glutDisplayFunc(drawPlayerSelect);

    // Handle mouse input
    glutMouseFunc(onClick);

    // Handle keyboard input (for closing cleanly)
    glutKeyboardFunc(onPress);

    // Start main loop
    glutMainLoop();

    return 0;

}
