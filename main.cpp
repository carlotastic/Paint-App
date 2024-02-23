#include <iostream>
#include <GL/freeglut.h>
#include "PaintApp.h"

using namespace std;

PaintApp paintApp;
// Window width and height
int width = 600;
int height = 600;

// Convert window coordinates to Cartesian coordinates
void windowToScene(float& x, float& y) {
    x = (2.0f * (x / float(width))) - 1.0f;
    y = 1.0f - (2.0f * (y / float(height)));
}

void drawScene(){
    // Clear the screen and set it to current color (black)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_POINT_SMOOTH);

    // enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Objects to be drawn go here
    paintApp.render();

    glutPostRedisplay();
    // We have been drawing to the back buffer, put it in the front
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    /*
        button: 0 -> left mouse button
                2 -> right mouse button
        
        state:  0 -> mouse click
                1 -> mouse release
        
        x, y:   mouse location in window relative coordinates
    */
    float mx = x;
    float my = y;
    windowToScene(mx, my);

    if (button == 0 && state == 0) {
        paintApp.handleLeftMouseDown(mx, my);
    }
    else if(button == 0 && state == 1) {
        paintApp.handleLeftMouseUp(mx, my);
    } 
    else if(button == 1 && state == 0) {
        paintApp.handleRightMouseDown(mx, my);
    }
    else if(button == 1 && state == 1) {
        paintApp.handleRightMouseUp(mx, my);
    }
}

void motion(int x, int y) {
    /*
        x, y:   mouse location in window relative coordinates
    */
    float mx = x;
    float my = y;
    windowToScene(mx, my);

    paintApp.handleMouseMotion(mx, my);
}

void keyboard(unsigned char key, int x, int y) {
    /*
        key:    ASCII character of the keyboard key that was pressed
        x, y:   mouse location in window relative coordinates
    */
    float mx = x;
    float my = y;
    windowToScene(mx, my);
    paintApp.handleKeyboardDown(key, mx, my);
}

int main(int argc,char** argv) {
    // Perform some initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT App");

    // Set the Display Function
    glutDisplayFunc(drawScene);

    // Set the Mouse Function
    glutMouseFunc(mouse);

    // Set the Motion Function
    glutMotionFunc(motion);

    // Set the Keyboard Funcion
    glutKeyboardFunc(keyboard);

    // initialize paintApp
    paintApp.init();
    // Run the program
    glutMainLoop();

    return 0;
}
