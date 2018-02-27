#include <GL/freeglut.h>
#include <vector>
#include <cmath>
#include "Square.h"

#define PLAYER_SELECT 0
#define PLAYING       1 
#define GAME_OVER     2

// Global variables for game board, number of players, window size, and state
int width = 800, height = 800, players, gameState;
Square oneP(-0.5, 0.0, 0.5), twoP(0.5, 0.0, 0.5);
std::vector<Square> board;
char currentPlayer;

void drawSquare(Square s){

    glColor3f(0.0, 1.0, 0.0);
    glRectf(s.getX() - (0.5 * s.getL()), s.getY() - (0.5 * s.getL()), 
            s.getX() + (0.5 * s.getL()), s.getY() + (0.5 * s.getL()));

    if(s.getO() == 'x'){

        // Draw an X in the square
        glColor3f(0.0, 0.0, 0.0);
        glLineWidth(5.0);

        glBegin(GL_LINES);
            glVertex2f(s.getX() - 0.2, s.getY() + 0.2);
            glVertex2f(s.getX() + 0.2, s.getY() - 0.2);
        glEnd();

        glBegin(GL_LINES);
            glVertex2f(s.getX() + 0.2, s.getY() + 0.2);
            glVertex2f(s.getX() - 0.2, s.getY() - 0.2);
        glEnd();

    }else if(s.getO() == 'o'){

        // Draw an O in the square
        glColor3f(0.0, 0.0, 0.0);
        GLfloat twicePi = 2.0f * M_PI;
        glLineWidth(5.0);

        glBegin(GL_LINE_LOOP);
            for(int i = 0; i <= 200; i++){
                glVertex2f(s.getX() + (0.2 * cos(i * twicePi / 200)), 
                           s.getY() + (0.2 * sin(i * twicePi / 200)));
            }
    
        glEnd();

    }


}

void drawBoard(){

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    for(int i = 0; i < board.size(); i++){
        drawSquare(board[i]);
    }

    glutSwapBuffers();

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

void onClick(int button, int state, int x, int y){

    float tx = x;
    float ty = y;
    float mx =  (tx / 400 - 1.0);
    float my = -(ty / 400 - 1.0);

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

        switch(gameState){

            case PLAYER_SELECT:

                if(oneP.contains(mx, my)){
                    players = 1;
                    gameState = PLAYING;
                    drawBoard();
                }else if(twoP.contains(mx, my)){
                    players = 2;
                    gameState = PLAYING;
                    drawBoard();
                }

                break;

            case PLAYING:

                // To Do: Check if someone has won
                
                bool moved = false;

                for(int i = 0; i < board.size(); i++){

                    if(board[i].contains(mx, my) && !board[i].isOccupied()){
                        
                        board[i].setO(currentPlayer);

                        if(currentPlayer == 'x')
                            currentPlayer = 'o';
                        else
                            currentPlayer = 'x';

                        moved = true;

                    }

                }

                // Decide AI move if necessary
                if(players == 1 && moved){
                
                    for(int i = 0; i < board.size(); i++){

                        if(!board[i].isOccupied()){

                            board[i].setO(currentPlayer);

                            if(currentPlayer == 'x')
                                currentPlayer = 'o';
                            else
                                currentPlayer = 'x';

                            break;

                        }

                    }

                }

                drawBoard();

                break;

           // case GAME_OVER:

           //   break;

        }

    }

}

void onPress(unsigned char key, int x, int y){

    if(key == 27){
        exit(0);
    }

}

int main(int argc, char** argv){

    // Populate board with squares
    float lastX = -1.32, lastY = 0.66;
    for(int i = 0; i < 9; i++){

        if(i == 3 || i == 6){
            board.emplace_back(-0.66, lastY - 0.66, 0.64);
            lastX = -0.66;
            lastY = lastY - 0.66;
        }else{
            board.emplace_back(lastX + 0.66, lastY, 0.64);
            lastX = lastX + 0.66;
            lastY = lastY;
        }
 
    }

    currentPlayer = 'x';

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