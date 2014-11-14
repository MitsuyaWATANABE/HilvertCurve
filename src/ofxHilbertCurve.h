//
//  Created by Mitsuya.WATANABE on 2014/10/19.
//
//

#ifndef __ofxHilbertCurve__ofxHilbertCurve__
#define __ofxHilbertCurve__ofxHilbertCurve__

#include <stdio.h>
#endif /* defined(__HilbertCurve__HilbertCurve__) */

#pragma once
#include "ofMain.h"
#include "ofxTween.h"

/**
 * @note このサンプルは以下のサイトを参考に実装されています
 @see http://www.softist.com/programming/hilbert/hilbert.htm
 */


typedef enum {
    VectorDirectionUpToDown,
    VectorDirectionLeftToRight,
    VectorDirectionRightToLeft,
    VectorDirectionDownToUp
}VectorDirection;

class ofxHilbertCurve : public ofBaseApp {
public:
    virtual ~ofxHilbertCurve();
    ofxHilbertCurve();

    void draw();
    void update();
    void ldr(int n);
    void urd(int n);
    void rul(int n);
    void dlu(int n);
    void tweenCallback(int &value);

    int hilbertXpos = 0;
    int hilbertYpos = 0;
    int startXPos = 0;
    int startYPos = 0;
    int tempX = 0;
    int tempY = 0;
    int delta = 10;
    int stages = 1;
    int count = 0;
    int drawingCount = 0;
    unsigned delay = 0;
    unsigned duration = 100;

    bool enableDrawing = true;
    ofxTween tweenlinear;
    ofxEasingLinear 	easinglinear;
    void drawLineInDirection(VectorDirection direction); // 0: xAxis, 1: yAxis
};