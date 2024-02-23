#ifndef BUTTON_H
#define BUTTON_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>
#include "Color.h"

struct Button {
    float x;
    float y;
    float w;
    float h;
    float r;
    float g;
    float b;
    std::string text;
    bool selected;
    bool stroke;

    Button() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.2f;
        text = "Button";
        selected = false;
        stroke = true;
        r = 0.388f;
        g = 0.533f;
        b = 0.537f;
    }

    Button(std::string text, float x, float y, float w, float h, bool stroke) {
        this->text = text;
        this->x = x;
        this->y = y;
        this-> w = w;
        this-> h = h;
        selected = false;
        this->stroke = stroke;
        r = 0.388f;
        g = 0.533f;
        b = 0.537f;

    }

    Button(std::string text, float x, float y, float w, float h, bool stroke, float r, float g, float b) {
        this->text = text;
        this->x = x;
        this->y = y;
        this-> w = w;
        this-> h = h;
        this-> r = r;
        this-> g = g;
        this-> b = b;
        selected = false;
        this->stroke = stroke;
    }

    void draw() {
        float textWidth = 0.0f;
        for (int i = 0; i < text.length(); i++) {
            textWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, text[i]);
        }

        float padding = 0.03;
        textWidth = 2.0f * (textWidth / 400.0);

        w = textWidth + padding;
        if (selected == true) {
            glColor3f(0.188f, 0.333f, 0.337f);
        }
        else {
        glColor3f(r, g, b);
        }
        glBegin(GL_POLYGON);
            glVertex2f(x, y); // ->
            glVertex2f(x + w, y); // V
            glVertex2f(x + w, y - h); // <-
            glVertex2f(x, y - h); 
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2f(x, y - h);
            glVertex2f(x, y);

            glVertex2f(x, y);
            glVertex2f(x + w, y);

            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);

            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();
        


            glRasterPos2f(x + (padding*2), y - (h / 2) - 0.025);
        
        

        for (int i = 0; i < text.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        }
    }

    bool isClicked(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }

    void press() {
        selected = true;
    }

    void release() {
        selected = false;
    }
};

#endif
