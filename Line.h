#ifndef LINE_H
#define LINE_H

#include "Color.h"
#include <GL/freeglut.h>

struct Line {

float size;
float x;
float y;
Color color;
bool selected;



Line () {
    size = 0.1f;
    x = 0.0f;
    y = 0.0f;
    color = Color();
    selected = false;
}

Line(float x, float y) {
    this-> x = x;
    this-> y = y;
    selected = false;
}

Line (float x, float y, float size, Color color) {
    this-> x = x;
    this-> y = y;
    this-> size = size;
    this-> color = color;
    selected = false;

}

void drawLine(float endX, float endY) {
    glColor3f(0.4f, 0.4f, 0.4f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(endX, endY);

    glEnd();
    glLineWidth(1.0f);
}


void draw() {
    if (selected) {
    glColor3f(0.0f, 0.443f, 0.137f);
    }
    else {
    glColor3f(color.r, color.g, color.b);   
    }
    
    glLineWidth(size);

    glBegin(GL_LINES);

    glVertex2f(x, y);
    glVertex2f(x + 0.2f, y);



    glEnd();

    glLineWidth(1.0f);


}


bool isClicked(float mx, float my) {


    if(mx >= x && mx <= x + 0.2f && my <= y + 0.05f && my >= y - 0.05f) {
        return true;

    }
    else {
        return false;
    }



}



};




#endif
