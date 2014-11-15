#include "ofApp.h"
#include<math.h>

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0);
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofSetLineWidth(0.1);
    ofNoFill();
    
    gui.setup(); // most of the time you don't need a name
    gui.add(stageSlider.setup("stage", 4, 1, 30));
    gui.add(deltaSlider.setup("delta", 27, 1, 30));
    gui.add(xSlider.setup("xPos", 716, 0, ofGetWidth()));
    gui.add(ySlider.setup("yPos", 44, 0, ofGetHeight()));
    hilbertCurve = new ofxHilbertCurve;
    font.loadFont("futura_book.otf", 11);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(255);
    hilbertCurve->delta = deltaSlider;
    hilbertCurve->startXPos = xSlider;
    hilbertCurve->startYPos = ySlider;
    hilbertCurve->duration = 200;
    hilbertCurve->stages = stageSlider;
    if (drawEnable)
        hilbertCurve->draw();
    
    if (!drawEnable) {
        font.drawString("This is a sample for Hilvert Curve.\n\nTyping \"s\" key displays it.\nthen if you type \"a\", you can watch the drawing process as an animation", 20, 200);
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's' :
            drawEnable = !drawEnable;
            break;
            
        case 'a':
            hilbertCurve->isAnimation = !hilbertCurve->isAnimation;
            break;
    }
}
