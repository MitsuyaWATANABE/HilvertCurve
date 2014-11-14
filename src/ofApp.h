#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <stdlib.h>
#include "ofxGui.h"
#include "ofxHilbertCurve.h"
#include "ofxTween.h"

/**
 * @note このサンプルは以下のサイトを参考に実装されています
   @see http://www.softist.com/programming/hilbert/hilbert.htm
 */

class ofApp : public ofBaseApp {

typedef enum {
    VectorDirectionUpToDown,
    VectorDirectionLeftToRight,
    VectorDirectionRightToLeft,
    VectorDirectionDownToUp
}VectorDirection;
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    ofxPanel gui;
    ofxIntSlider stageSlider;
    ofxIntSlider deltaSlider;
    ofxIntSlider xSlider;
    ofxIntSlider ySlider;
    ofxFloatSlider pPhaseSlider;
    ofxFloatSlider qPhaseSlider;
    ofxFloatSlider rPhaseSlider;
    ofxHilbertCurve *hilbertCurve;
    bool drawEnable = false;
};
