//
//  Created by Mitsuya.WATANABE on 2014/10/19.
//

#include "ofxHilbertCurve.h"

ofxHilbertCurve::ofxHilbertCurve()
{
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofSetLineWidth(0.1);
    ofNoFill();
    ofSetColor(255);
    hilbertXpos = ofGetWidth();
    tweenlinear.setParameters(0, easinglinear, ofxTween::easeOut, 0, 0, duration, delay);
    tweenlinear.update();
}

ofxHilbertCurve::~ofxHilbertCurve() {}

void ofxHilbertCurve::update() {}

void ofxHilbertCurve::draw()
{
    hilbertXpos = startXPos;
    hilbertYpos = startYPos;
    tempX = hilbertXpos;
    tempY = hilbertYpos;
    count = 0;
    
    ldr(stages);    
}


#pragma mark - HilbertCurve Functions
void ofxHilbertCurve::ldr(int n)
{
    if (n > 0) {
        if (isAnimation) {
            dlu(n - 1);
            if (drawingCount < count) return;
            // <-
            drawLineInDirection(VectorDirectionRightToLeft);
            
            ldr(n - 1);
            if (drawingCount < count) return;
            // v|
            drawLineInDirection(VectorDirectionUpToDown);
            
            ldr(n - 1);
            if (drawingCount < count) return;
            // ->
            drawLineInDirection(VectorDirectionLeftToRight);
            
            urd(n - 1);
        } else {
            dlu(n-1);

            hilbertXpos -= delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            
            ldr(n-1);

            hilbertYpos += delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;
            
            ldr(n-1);

            hilbertXpos += delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            urd(n-1);
        }
    }
}
void ofxHilbertCurve::urd(int n)
{
    if (n > 0) {
        if(isAnimation) {
            rul(n - 1);
            if (drawingCount < count) return;
            // ^|
            drawLineInDirection(VectorDirectionDownToUp);
            
            urd(n - 1);
            if (drawingCount < count) return;
            // ->
            drawLineInDirection(VectorDirectionLeftToRight);
            
            urd(n - 1);
            if (drawingCount < count) return;
            // v|
            drawLineInDirection(VectorDirectionUpToDown);
            
            ldr(n - 1);
        } else {
            rul(n-1);
            
            hilbertYpos -= delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;
            
            urd(n-1);
            
            hilbertXpos += delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            
            urd(n-1);

            hilbertYpos += delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;
            
            ldr(n-1);

        }
    }
}
void ofxHilbertCurve::rul(int n)
{
    if (n > 0) {
        if (isAnimation) {
            urd(n - 1);
            if (drawingCount < count) return;
            // ->
            drawLineInDirection(VectorDirectionLeftToRight);
            
            rul(n - 1);
            if (drawingCount < count) return;
            // ^|
            drawLineInDirection(VectorDirectionDownToUp);
            
            rul(n - 1);
            if (drawingCount < count) return;
            // <-
            drawLineInDirection(VectorDirectionRightToLeft);
            
            dlu(n - 1);
        } else {
            urd(n-1);

            hilbertXpos += delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            
            rul(n-1);
            
            hilbertYpos -= delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;

            rul(n-1);

            hilbertXpos -= delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            
            dlu(n-1);

        }
    }
}
void ofxHilbertCurve::dlu(int n)
{
    if (n > 0) {
        if (isAnimation) {
            ldr(n - 1);
            if (drawingCount < count) return;
            // v|
            drawLineInDirection(VectorDirectionUpToDown);
            
            dlu(n - 1);
            if (drawingCount < count) return;
            // <-
            drawLineInDirection(VectorDirectionRightToLeft);
            
            dlu(n - 1);
            if (drawingCount < count) return;
            // ^|
            drawLineInDirection(VectorDirectionDownToUp);
            
            rul(n - 1);
        } else {
            ldr(n-1);
            
            hilbertYpos += delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;

            dlu(n-1);
            
            hilbertXpos -= delta;
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
            tempX = hilbertXpos;
            
            dlu(n-1);
            
            hilbertYpos -= delta;
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
            tempY = hilbertYpos;
            
            rul(n-1);
        }
    }
}


void ofxHilbertCurve::drawLineInDirection(VectorDirection direction) {
    
    switch (direction) {
        case VectorDirectionRightToLeft:
            hilbertXpos -= delta;
            break;
        case VectorDirectionLeftToRight:
            hilbertXpos += delta;
            break;
        case VectorDirectionDownToUp:
            hilbertYpos -= delta;
            break;
        case VectorDirectionUpToDown:
            hilbertYpos += delta;
            break;
            
        default:
            break;
    }
    
    if (direction == VectorDirectionLeftToRight || direction == VectorDirectionRightToLeft) {
        if (drawingCount == count && enableDrawing) {
            tweenlinear.setParameters(count, easinglinear, ofxTween::easeOut, tempX, hilbertXpos, duration, delay);
            ofAddListener(tweenlinear.end_E, this, &ofxHilbertCurve::tweenCallback);
            ofLine(tempX, hilbertYpos, tweenlinear.update(), hilbertYpos);
            enableDrawing = false;
        } else if (drawingCount == count && !enableDrawing) {
            ofLine(tempX, hilbertYpos, tweenlinear.update(), hilbertYpos);
        } else {
            ofLine(tempX, hilbertYpos, hilbertXpos, hilbertYpos);
        }
        tempX = hilbertXpos;
    } else {
        if (drawingCount == count && enableDrawing) {
            tweenlinear.setParameters(count, easinglinear, ofxTween::easeOut, tempY, hilbertYpos, duration, delay);
            ofAddListener(tweenlinear.end_E, this, &ofxHilbertCurve::tweenCallback);
            ofLine(hilbertXpos, tempY, hilbertXpos, tweenlinear.update());
            enableDrawing = false;
        } else if (drawingCount == count && !enableDrawing) {
            ofLine(hilbertXpos, tempY, hilbertXpos, tweenlinear.update());
        } else {
            ofLine(hilbertXpos, tempY, hilbertXpos, hilbertYpos);
        }
        tempY = hilbertYpos;
    }
    
    count++;
}

void ofxHilbertCurve::tweenCallback(int &value) {
    // calclate max drawing lines
    // NOTE: an = 3, an+1 = 15, an+2 = 63, an+3 = 255, an+4 = 1023...
    //       an = 2 ^ (2n - 2) - 1
    double max = pow(2.0, ((2 * (stages + 1)) - 2)) - 1;
    if (max == value + 1) {
        drawingCount = 0;
    } else {
        drawingCount++;
    }
    
    enableDrawing = true;
}