#ifndef COLORBTN_H
#define COLORBTN_H
#include <GL/freeglut_std.h>
#include <cmath>
using namespace std;

struct ColorBtn {
    // member variables
    float radius;
    float x;
    float y;
    float r;
    float g;
    float b;
    bool selected;


    // default constructor
    ColorBtn() {
        radius = 0.1f;
        x = 0.0f;
        y = 0.0f;
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
        selected = false;
        
    }

    // parametrized constructor
    ColorBtn(float _x, float _y, float _radius, float _r, float _g, float _b) {
        x = _x;
        y = _y;
        radius = _radius;
        r = _r / 255;
        g = _g / 255;
        b = _b / 255;
        selected = false;
    }

    void draw() {
        float inc = ( 2 * M_PI) / 60;
        float _radius = radius;
        glColor3f(r, g, b);
        
        glBegin(GL_POLYGON);
            for (float theta = 0; theta < 2*M_PI; theta += inc){
                glVertex2f(radius * cos(theta) + x, radius * sin(theta) + y);
            }
        glEnd();
        if (selected) {
            ColorBtn innerWhite = ColorBtn(x, y, 0.085f, 0.615f*255, 0.737f*255, 0.596f*255);
            ColorBtn innerSameColor = ColorBtn(x, y, 0.075f, r*255, g*255, b*255);
            innerWhite.draw();
            innerSameColor.draw();

        }

        
    }

    bool isClicked(float mx, float my) {
        if (radius >= sqrt((pow((mx - x), 2) + pow((my - y), 2)))) {
            return true;
        } else {
            return false;
        }
    }


    
};


#endif
