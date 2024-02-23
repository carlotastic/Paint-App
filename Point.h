#ifndef POINT_H
#define POINT_H

#include <GL/freeglut.h>
#include "Color.h"

struct Point {
    float x;
    float y;
    float size;
    Color color;

    Point() {
        x = 0.0f;
        y = 0.0f;
        size = 8.0f;
    }

    Point(float x, float y, Color color, float size) {
        this->x = x;
        this->y = y;
        this->color = color;
        this-> size = size;
    }

    void draw() {
        glColor3f(color.r, color.g, color.b);
        glPointSize(size);

        glBegin(GL_POINTS);
            glVertex2f(x, y);
        glEnd();
    }
};


#endif
