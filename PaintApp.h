#ifndef PAINT_APP_H
#define PAINT_APP_H
#include "ClearBtn.h"
#include "ColorBtn.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Button.h"
#include "Texture.h"
#include <iostream>

enum TOOL {BRUSH, ERASER, SHAPE, SELECTOR};
enum COLOR {OCEAN, SKY, RED, PEACH, KHAKI, TAN, GREEN, MINT, PURPLE, UBE};
enum STROKE {THIN, MEDIUM, THICK};
enum WINDOW {MENU, COLORS, SHAPES, STROKES};
enum SHAPESELECTED {NONE, TRIANGLE, SQUARE, CIRCLE};
enum OBJECTCLICKED {NA, TRI, SQU, CIR};


struct PaintApp {


// Drawing stuff
int maxPoints;
int pointCount;
int eraserCount;
int triangleCount;
int squareCount;
int circleCount;
float pointerSize;
Color pointerColor;
Color lastColorSelected;
Point points[10000];
Point eraser[10000];
Shape triangles[10000];
Shape squares[10000];
Shape circles[10000];



// Bounds for canvas
Rectangle topBound;
Rectangle leftBound;
Rectangle rightBound;
Rectangle bottomBound;
Rectangle selectedArea;
Rectangle canvas;

// Main Menu Buttons
Button colorsBtn;
Texture paintBrushBtn;
Button shapesBtn;
Button strokesBtn;
ColorBtn colorDisplay;
Shape shapeDisplay;
Line strokeDisplay;
Texture selectorBtn;
// Clear button
Texture eraserBtn;
ClearBtn clearBtn;

//showColors function
Button backBtn;
ColorBtn outlineButton;
ColorBtn oceanButton;
ColorBtn skyButton;
ColorBtn redButton;
ColorBtn peachButton;
ColorBtn khakiButton;
ColorBtn tanButton;
ColorBtn greenButton;
ColorBtn mintButton;
ColorBtn purpleButton;
ColorBtn ubeButton;

// Shape section
Shape triangleButton;
Shape squareButton;
Shape circleButton;


// Stroke section
Line thinStroke;
Line medStroke;
Line thickStroke;

//enums
TOOL selectedTool;
COLOR selectedColor;
STROKE selectedStroke;
WINDOW selectedWindow;
SHAPESELECTED selectedShape;
OBJECTCLICKED objectClicked;
//selector stuff
int selectedIndex;
int lastIndexSelected;
Line verticalPlus;
Line horizontalPlus;
Line minusSign;

PaintApp() {
maxPoints = 10000;
eraserCount = 0;
pointCount = 0;
triangleCount = 0;
squareCount = 0;
circleCount = 0;
pointerSize = 8.0f;
pointerColor = Color(22, 114, 136);
lastColorSelected = Color(22,114, 136); 


topBound = Rectangle(-1.0f, 1.0f, 2.0f, 0.15f, 0.615f, 0.737f, 0.596f);
leftBound = Rectangle(-1.0f, 1.0f, 0.15f, 2.0f, 0.615f, 0.737f, 0.596f);
rightBound = Rectangle(0.85f, 1.0f, 0.15f, 2.0f, 0.615f, 0.737f, 0.596f);
bottomBound = Rectangle(-1.0f, -0.3f, 2.0f, 1.0f, 0.615f, 0.737f, 0.596f);
selectedArea = Rectangle(0.25f, -0.65f, 0.75f, 0.35f, 0.715f, 0.836f, 0.696f);
canvas = Rectangle(-0.85f, 0.85f, 1.7f, 1.15f, 1.0f, 1.0f, 1.0f);
colorsBtn = Button("Colors", -0.7f, -0.4f, 0.7f, 0.2f, false);
paintBrushBtn = Texture("assets/pencil.png", -0.75f, -0.7f, 0.2f, 0.2f);
shapesBtn = Button("Shapes", -0.2f, -0.4f, 0.7f, 0.2f, false);
strokesBtn = Button("Strokes", 0.3f, -0.4f, 0.7f, 0.2f, false);
colorDisplay = ColorBtn(0.4f, -0.85f, 0.04f, pointerColor.r*255, pointerColor.g*255, pointerColor.b*255);
eraserBtn = Texture("assets/eraser.png", -0.4f, -0.7f, 0.2f, 0.2f);
selectorBtn = Texture("assets/mouse.png", -0.05f, -0.7f, 0.2f, 0.2f);
clearBtn = ClearBtn("Clear", 0.595f, -0.3f);

backBtn = Button("Back", -0.8f, -0.4f, 0.7f, 0.2f, false, 0.701f, 0.639f, 0.596f);
outlineButton = ColorBtn(-0.35f, -0.5f, 0.125f, 79, 111, 82);
oceanButton = ColorBtn(-0.35f, -0.5f, 0.1f, 22, 114, 136);
skyButton = ColorBtn(-0.075f, -0.5f, 0.1f, 140, 218, 236);
redButton = ColorBtn(0.20f, -0.5f, 0.1f, 180, 82, 72);
peachButton = ColorBtn(0.475f, -0.5f, 0.1f, 212, 140, 132);
khakiButton = ColorBtn(0.75f, -0.5f, 0.1f, 168, 154, 73);
tanButton = ColorBtn(-0.55f, -0.8f, 0.1f, 214, 207, 162);
greenButton = ColorBtn(-0.275f, -0.8f, 0.1f, 60, 180, 100);
mintButton = ColorBtn(0.0f, -0.8f, 0.1f, 155, 221, 177);
purpleButton = ColorBtn(0.275f, -0.8f, 0.1f, 100, 60, 106);
ubeButton = ColorBtn(0.55f, -0.8f, 0.1f, 131, 99, 148);

triangleButton = Shape(-0.2f, - 0.5f, 0.1f, 0.1f, Color());
squareButton = Shape(0.2f, - 0.5f, 0.1f, 0.1f, Color());
circleButton = Shape(0.6f, - 0.5f, 0.1f, 0.1f, Color());


thinStroke = Line(-0.35f, -0.5f, 8.0f, Color());
medStroke = Line(0.0f, -0.5f, 16.0f, Color());
thickStroke = Line(0.35f, -0.5f, 32.0f, Color());


selectedTool = BRUSH;
selectedColor = OCEAN;
selectedStroke = THIN;
selectedWindow = MENU;
selectedShape = NONE;
objectClicked = NA;

//selector stuff
lastIndexSelected = 0;
selectedIndex = 0;
verticalPlus = Line(0.75f, -0.45f);
horizontalPlus = Line(0.7f, -0.50f);
minusSign = Line (0.87f, - 0.5f);
}

void init() {
        paintBrushBtn.loadTexture();
        eraserBtn.loadTexture();
        selectorBtn.loadTexture();
    }

void handleLeftMouseDown(float x, float y) {
// clear button
if(clearBtn.isClicked(x,y)){
    triangleCount = 0;
    squareCount = 0;
    circleCount = 0;
    pointCount = 0;
    eraserCount = 0;

}

if (canvas.isClicked(x, y)) {
    if (selectedTool == BRUSH) {
        points[pointCount] = Point(x, y, pointerColor, pointerSize);
        pointCount++;
    }
    else if(selectedTool == ERASER) {

        eraser[eraserCount] = Point(x, y, Color(255,255,255), pointerSize);
        eraserCount++;
    }
    else if(selectedTool == SHAPE) {
        if(selectedShape == TRIANGLE) {
           triangles[triangleCount] = Shape(x, y, 0.05f, 0.05f, pointerColor);
           triangleCount++; 
        }
        else if (selectedShape == SQUARE) {
            squares[squareCount] = Shape(x, y, 0.05f, 0.05f, pointerColor);
           squareCount++; 
        }
        else {
            circles[circleCount] = Shape(x, y, 0.05f, 0.05f, pointerColor);
           circleCount++;
        }
        
    }
    

}

//menu stuff
if (selectedWindow == MENU) {


if (colorsBtn.isClicked(x,y)) {
    selectedWindow = COLORS;
}
else if (shapesBtn.isClicked(x,y)) {
    selectedWindow = SHAPES;
}
else if (strokesBtn.isClicked(x,y)) {
    selectedWindow = STROKES;
}
else if(paintBrushBtn.isClicked(x,y)) {
    selectedTool = BRUSH;
    selectedColor = OCEAN;
    pointerColor.setColor(oceanButton.r, oceanButton.g, oceanButton.b);

}
else if(eraserBtn.isClicked(x,y)) {
    pointerColor.setColor(1.0f, 1.0f, 1.0f);
    selectedTool = ERASER;
}
else if(selectorBtn.isClicked(x,y)) {
    selectedTool = SELECTOR;
}


}
else if (backBtn.isClicked(x,y)) {
    selectedWindow = MENU;
}


// colors selected
if (selectedWindow == COLORS) {
if (oceanButton.isClicked(x, y)) { // color button is clicked
    selectedColor = OCEAN; //selected color changes
    pointerColor.setColor(oceanButton.r, oceanButton.g, oceanButton.b); //changes pointer Color
if(selectedTool == SELECTOR) { // if i have selector tool equipped
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);} //if the shape that is clicked is a triangle, set the last object clicked into pointer color
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);} //if the shape is squares
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);} // if the shape is circles
       }
}
else if (skyButton.isClicked(x,y)) {
    selectedColor = SKY;
    pointerColor.setColor(skyButton.r, skyButton.g, skyButton.b);
    if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (redButton.isClicked(x,y)) {
    selectedColor = RED;
    pointerColor.setColor(redButton.r, redButton.g, redButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (peachButton.isClicked(x,y)) {
    selectedColor = PEACH;
    pointerColor.setColor(peachButton.r, peachButton.g, peachButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
    
}
else if (khakiButton.isClicked(x,y)) {
    selectedColor = KHAKI;
    pointerColor.setColor(khakiButton.r, khakiButton.g, khakiButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (tanButton.isClicked(x,y)) {
    selectedColor = TAN;
    pointerColor.setColor(tanButton.r, tanButton.g, tanButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (greenButton.isClicked(x,y)) {
    selectedColor = GREEN;
    pointerColor.setColor(greenButton.r, greenButton.g, greenButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (mintButton.isClicked(x,y)) {
    selectedColor = MINT;
    pointerColor.setColor(mintButton.r, mintButton.g, mintButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }

}
else if (purpleButton.isClicked(x,y)) {
    selectedColor = PURPLE;
    pointerColor.setColor(purpleButton.r, purpleButton.g, purpleButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}
else if (ubeButton.isClicked(x,y)) {
    selectedColor = UBE;
    pointerColor.setColor(ubeButton.r, ubeButton.g, ubeButton.b);
if(selectedTool == SELECTOR) {
       if (objectClicked == TRI) { triangles[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == SQU) { squares[lastIndexSelected].setColor(pointerColor);}
       
       if (objectClicked == CIR) { circles[lastIndexSelected].setColor(pointerColor);}
       }
}

}

// shape stuff
if (selectedWindow == SHAPES && selectedTool != ERASER) {
if (triangleButton.isClicked(x,y)) {
    triangleButton.selected = true;
    selectedTool = SHAPE;
    selectedShape = TRIANGLE;
}
else if(squareButton.isClicked(x,y)) {
    squareButton.selected = true;
    selectedTool = SHAPE;
    selectedShape = SQUARE;
}
else if(circleButton.circleIsClicked(x,y)) {
    circleButton.selected = true;
    selectedTool = SHAPE;
    selectedShape = CIRCLE;
}


}

// stroke stuff
if (selectedWindow == STROKES) {
if (thinStroke.isClicked(x,y)) {
    selectedStroke = THIN;
}
else if (medStroke.isClicked(x,y)) {
    selectedStroke = MEDIUM;
}
else if (thickStroke.isClicked(x,y)) {
    selectedStroke = THICK;
}


}



// selecting shapes and stuff
if(selectedTool == SELECTOR) {
for(int i = 0; i <triangleCount; i++ ) {
        triangles[i].selected = false;
}
    for (int i = 0; i < triangleCount; i++) {
            if (triangles[i].isClicked(x, y)) {
                objectClicked = TRI;
                triangles[i].selected = true;
                selectedIndex = i;
                break;
            }
        }
// selecting squares
for(int i = 0; i <squareCount; i++ ) {
        squares[i].selected = false;
}
    for (int i = 0; i < squareCount; i++) {
            if (squares[i].isClicked(x, y)) {
                squares[i].selected = true;
                objectClicked = SQU;
                selectedIndex = i;
                break;
            }
        }
// selecting circles or hexagons
for(int i = 0; i <circleCount; i++ ) {
        circles[i].selected = false;
}
    for (int i = 0; i < circleCount; i++) {
            if (circles[i].isClicked(x, y)) {
                circles[i].selected = true;
                objectClicked = CIR;
                selectedIndex = i;
                break;
            }
        }
if(selectedWindow == MENU) {
if(verticalPlus.isClicked(x,y) || horizontalPlus.isClicked(x,y)) {
   if (objectClicked == TRI) {
        triangles[lastIndexSelected].w += 0.1f;
        triangles[lastIndexSelected].h += 0.1f;
     }
     else if (objectClicked == SQU) {
        squares[lastIndexSelected].w += 0.1f;
        squares[lastIndexSelected].h += 0.1f;
     }
     else if (objectClicked == CIR) {
        circles[lastIndexSelected].w += 0.1f;
        circles[lastIndexSelected].h += 0.1f;
     } 
}
else if(minusSign.isClicked(x,y)) {
    if (objectClicked == TRI) {
        triangles[lastIndexSelected].w -= 0.1f;
        triangles[lastIndexSelected].h -= 0.1f;
     }
     else if (objectClicked == SQU) {
        squares[lastIndexSelected].w -= 0.1f;
        squares[lastIndexSelected].h -= 0.1f;
     }
     else if (objectClicked == CIR) {
        circles[lastIndexSelected].w -= 0.1f;
        circles[lastIndexSelected].h -= 0.1f;
     } 
}

}
}
else {
    for(int i = 0; i <triangleCount; i++ ) {
        triangles[i].selected = false;
}
for(int i = 0; i <squareCount; i++ ) {
        squares[i].selected = false;
}
    for(int i = 0; i <circleCount; i++ ) {
        circles[i].selected = false;
}

}

}

void handleLeftMouseUp(float x, float y) {
    
}

void handleRightMouseDown(float x, float y) {
        //
}

void handleRightMouseUp(float x, float y) {
        //
}

void handleMouseMotion(float x, float y) {
if (canvas.isClicked(x, y)) {
    if (selectedTool == BRUSH) {
    if (pointCount < maxPoints) {
        points[pointCount] = Point(x, y, pointerColor, pointerSize);
        pointCount++;
    }
    }
    else if(selectedTool == ERASER) {
    if (eraserCount < maxPoints) {
        Color tempColor = pointerColor;
        eraser[eraserCount] = Point(x, y, Color(255, 255, 255), pointerSize);
        eraserCount++;
        pointerColor = tempColor;
    }
    }
    else if(selectedTool == SELECTOR) {
     if (objectClicked == TRI) {
        cout << "motion on triangle" << endl;
        triangles[selectedIndex].x = x;
        triangles[selectedIndex].y = y;
     }
     else if (objectClicked == SQU) {
        cout << "motion on square" << endl;
        squares[selectedIndex].x = x;
        squares[selectedIndex].y = y;
     }
     else if (objectClicked == CIR) {
        cout << "motion on CIRCLES" << endl;
        circles[selectedIndex].x = x;
        circles[selectedIndex].y = y;
     }

    }
}
}

void handleKeyboardDown(unsigned char key, float x, float y) {
        //
}

void render() {
// conditionals
lastIndexSelected = selectedIndex;
// tools
if(selectedTool == BRUSH) {
    selectedShape = NONE;
    objectClicked = NA;
    paintBrushBtn.selected = true;
    eraserBtn.selected = false;
    selectorBtn.selected = false;
    shapesBtn.selected = false;
}
else if(selectedTool == ERASER) {
    selectedShape = NONE;
    objectClicked = NA;
    paintBrushBtn.selected = false;
    eraserBtn.selected = true;
    selectorBtn.selected = false;
    shapesBtn.selected = false;
}
else if(selectedTool == SELECTOR) {
    selectedShape = NONE;
    paintBrushBtn.selected = false;
    eraserBtn.selected = false;
    selectorBtn.selected = true;
    shapesBtn.selected = false;
}
else if(selectedTool == SHAPE) {
    objectClicked = NA;
    paintBrushBtn.selected = false;
    eraserBtn.selected = false;
    selectorBtn.selected = false;
    shapesBtn.selected = true;
}




// colors
if (selectedColor == OCEAN) {
oceanButton.selected = true;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if(selectedColor == SKY) {
oceanButton.selected = false;
skyButton.selected = true;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;


}
else if (selectedColor == RED) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = true;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;

}
else if (selectedColor == PEACH) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = true;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if (selectedColor == KHAKI) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = true;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if (selectedColor == TAN) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = true;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if (selectedColor == GREEN) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = true;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if (selectedColor == MINT) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = true;
purpleButton.selected = false;
ubeButton.selected = false;
}
else if (selectedColor == PURPLE) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = true;
ubeButton.selected = false;
}
else if (selectedColor == UBE) {
oceanButton.selected = false;
skyButton.selected = false;
redButton.selected = false;
peachButton.selected = false;
khakiButton.selected = false;
tanButton.selected = false;
greenButton.selected = false;
mintButton.selected = false;
purpleButton.selected = false;
ubeButton.selected = true;
}


// shapes
if (selectedShape == TRIANGLE) {   
triangleButton.selected = true;
squareButton.selected = false;
circleButton.selected = false;
}
else if (selectedShape == SQUARE) {    
triangleButton.selected = false;
squareButton.selected = true;
circleButton.selected = false;
}
else if (selectedShape == CIRCLE) {    
triangleButton.selected = false;
squareButton.selected = false;
circleButton.selected = true;
}
else{
triangleButton.selected = false;
squareButton.selected = false;
circleButton.selected = false;
}


// stroke thickness
if (selectedStroke == THIN) {
pointerSize = thinStroke.size;
thinStroke.selected = true;
medStroke.selected = false;
thickStroke.selected = false;
}
else if (selectedStroke == MEDIUM) {
pointerSize = medStroke.size;
thinStroke.selected = false;
medStroke.selected = true;
thickStroke.selected = false;
}
else if (selectedStroke == THICK) {
pointerSize = thickStroke.size;
thinStroke.selected = false;
medStroke.selected = false;
thickStroke.selected = true;
}



canvas.draw();

// drawing
for(int i = 0; i<pointCount; i++) {
    points[i].draw();
}
for(int i = 0; i<triangleCount; i++) {
    triangles[i].drawTriangle();
}
for(int i = 0; i<squareCount; i++) {
    squares[i].drawSquare();
}
for(int i = 0; i<circleCount; i++) {
    circles[i].drawHexagon();
}
for(int i = 0; i<eraserCount; i++) {
    eraser[i].draw();
}


// canvas bounds
topBound.draw();
leftBound.draw();
rightBound.draw();
bottomBound.draw();
clearBtn.draw();




// WINDOW STATES
if (selectedWindow == MENU) {
colorsBtn.draw();
shapesBtn.draw();
strokesBtn.draw();
eraserBtn.draw();
paintBrushBtn.draw();
selectedArea.draw();
selectorBtn.draw();
//shadow stuff
Line shadowArea(0.255f, -0.655f);
shadowArea.drawLine(0.255f, -1.0f);
shadowArea.drawLine(1.0f, -0.655f);
colorDisplay.r = pointerColor.r;
colorDisplay.g = pointerColor.g;
colorDisplay.b = pointerColor.b;
colorDisplay.draw();

if(selectedShape == TRIANGLE) {
Shape triangleDisplay(0.565f, -0.85f, 0.06f, 0.05f, pointerColor);
triangleDisplay.drawTriangle();
}
else if (selectedShape == SQUARE) {
Shape squareDisplay(0.565f, -0.85f, 0.06f, 0.05f, pointerColor);
squareDisplay.drawSquare();
}
else if (selectedShape == CIRCLE) {
Shape circleDisplay(0.565f, -0.85f, 0.06f, 0.1f, pointerColor);
circleDisplay.drawHexagon();
}

if(selectedStroke == THIN) {
Line strokeDisplay(0.7f, -0.85f, 8.0f, pointerColor);
strokeDisplay.draw();
}
else if(selectedStroke == MEDIUM) {
Line strokeDisplay(0.7f, -0.85f, 16.0f, pointerColor);
strokeDisplay.draw();
}
if(selectedStroke == THICK) {
Line strokeDisplay(0.7f, -0.85f, 32.0f, pointerColor);
strokeDisplay.draw();
}

if(selectedTool == SELECTOR) {
verticalPlus.drawLine(0.75f, -0.55f);
horizontalPlus.drawLine(0.8f, -0.5f);
minusSign.drawLine(0.97f, -0.5f);


}



}
else if(selectedWindow == COLORS) {

backBtn.draw();
oceanButton.draw();
skyButton.draw();
redButton.draw();
peachButton.draw();
khakiButton.draw();    
tanButton.draw();
greenButton.draw();
mintButton.draw();
purpleButton.draw();
ubeButton.draw();



}
else if(selectedWindow == SHAPES) {
backBtn.draw();
triangleButton.setColor(pointerColor); 
squareButton.setColor(pointerColor);
circleButton.setColor(pointerColor);
triangleButton.drawTriangle();
squareButton.drawSquare();
circleButton.drawHexagon();



}
else if(selectedWindow == STROKES) {
backBtn.draw();
thinStroke.draw();
medStroke.draw();
thickStroke.draw();

}






}

};


#endif
