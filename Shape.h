#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include "Color.h"
#include  <cmath>

struct Shape {
    float x;
    float y;
    float w;
    float h;
    Color color;
    bool selected;

    Shape() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.2f;
        selected = false;
    }
    

    Shape(float x, float y, float w, float h, Color color) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->color = color;
        selected = false;
    }
    
    
    bool isClicked(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }

    }

    bool circleIsClicked(float mx, float my) {
        if (w >= sqrt((pow((mx - x), 2) + pow((my - y), 2)))) {
            return true;
        } else {
            return false;
        }
    }


    void drawTriangle() {

        if (selected) {
    glColor3f(0.0f, 0.443f, 0.137f);
    }
    else {
        glColor3f(color.r, color.g, color.b);
    }
        glBegin(GL_POLYGON);
            glVertex2f(x, y + h);
            glVertex2f(x + w, y - h);
            glVertex2f(x - w, y - h);
        glEnd();
    }

    void drawSquare() {
        if (selected) {
    glColor3f(0.0f, 0.443f, 0.137f);
    }
    else {
        glColor3f(color.r, color.g, color.b);
    }
        glBegin(GL_POLYGON);
        glVertex2f(x-w, y+h);
        glVertex2f(x+w, y+h);
        glVertex2f(x+w, y-h);
        glVertex2f(x-w, y-h);
        glEnd(); 
    }

    void drawHexagon() {
        float inc = ( 2 * M_PI) / 6;
        if (selected) {
    glColor3f(0.0f, 0.443f, 0.137f);
    }
    else {
        glColor3f(color.r, color.g, color.b);
    }
        glBegin(GL_POLYGON);
            for (float theta = 0; theta < 2*M_PI; theta += inc){
                glVertex2f(w * cos(theta) + x, w * sin(theta) + y);
            }
        glEnd();
    }

    void setColor(Color color) {
        this->color = color;

    }

    void setRGB(float r, float g, float b) {
        color.r = r;
        color.g = g;
        color.b = b;

    }



};


#endif
