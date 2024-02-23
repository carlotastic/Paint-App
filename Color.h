#ifndef COLOR_H
#define COLOR_H
#include <cmath>
#include <GL/freeglut.h>

struct Color {
    float r;
    float g;
    float b;



    Color() {
        r = 0.086f;
        g = 0.447f;
        b = 0.533f;

    }


    Color(float r, float g, float b) {

        this->r = r/255;
        this->g = g/255;
        this->b = b/255;

    }

    void setColor(float r, float g, float b) {
        this->r = r;
        this->g = g;
        this->b = b;

    }

    void setGreen() {
        r = 0.0f;
        g = 1.0f;
        b = 0.0f;
    }

    void setBlue() {
        r = 0.0f;
        g = 0.0f;
        b = 1.0f;
    }






};



#endif
