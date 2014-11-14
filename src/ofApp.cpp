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
    
    if (!drawEnable)
        gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 's' :
            drawEnable = !drawEnable;
            break;
    }
}
