#ifndef CLEAR_H
#define CLEAR_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>

struct ClearBtn {
    float x;
    float y;
    float w;
    float h;
    std::string text;
    bool pressed;

    ClearBtn() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.1f;
        text = "Button";
        pressed = false;
    }

    ClearBtn(std::string text, float x, float y) {
        this->text = text;
        this->x = x;
        this->y = y;
        w = 0.4f;
        h = 0.075f;
        pressed = false;
    }

    void draw() {
        float textWidth = 0.0f;
        for (int i = 0; i < text.length(); i++) {
            textWidth += glutBitmapWidth(GLUT_BITMAP_9_BY_15, text[i]);
        }

        float padding = 0.03;
        textWidth = 2.0f * (textWidth / 400.0);

        w = textWidth + padding;

        glColor3f(0.776f, 0.776f, 0.776f);

        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        
        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + w, y);

            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);

            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);

            glVertex2f(x, y - h);
            glVertex2f(x, y);
        glEnd();


        if (pressed) {
            glRasterPos2f(x + (padding), y - (h / 2) - 0.02);
        } else {
            glRasterPos2f(x + (padding) + 0.02, y - (h / 2) - 0.015);
        }
        

        for (int i = 0; i < text.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
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
        pressed = true;
    }

    void release() {
        pressed = false;
    }
};

#endif
