//
//  Agent.h
//  WormsFlocking
//
//  Created by Roberto Fazio on 29/09/17.
//
//

#pragma once

#include "ofMain.h"

class Agent
{
public:
    
    Agent();
    ~Agent();
    void setup();
    void update();
    void draw();
    void drawPoints(ofPoint pp);
    void setNoiseZRange(float theNoiseZrange);
    void checkBorder(ofPoint p);
    void reset();
    void exit();
    
    void mykeyPressed(ofKeyEventArgs& eventArgs);
    void keyReleased(ofKeyEventArgs &e);

    ofPoint p;
    float noiseZ;
    float stepSize;
    float noiseZVelocity;
    float angle;
    
    float *noiseScale;
    float *noiseStrength;
    float *noiseZRange;
    float *agentsAlpha;
    unsigned char *radius;
    bool bTrace;
    bool bOut;
    bool isOut();

    

    
};
