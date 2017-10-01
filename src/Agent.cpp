//
//  Agent.cpp
//  WormsFlocking
//
//  Created by Roberto Fazio on 29/09/17.
//
//

#include "Agent.h"

Agent::~Agent()
{
    ofRemoveListener(ofEvents().keyPressed, this, &Agent::mykeyPressed);
    ofRemoveListener(ofEvents().keyReleased, this, &Agent::keyReleased);
}

Agent::Agent()
{
    p.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
}

void Agent::setup()
{
    noiseZVelocity = 0.01f;
    noiseZ = 0.01f;
    stepSize = ofRandom(1,5);
    setNoiseZRange(0.4f);
    bTrace = false;
    bOut = false;
    
    ofAddListener(ofEvents().keyPressed, this, &Agent::mykeyPressed);
    ofAddListener(ofEvents().keyReleased, this, &Agent::keyReleased);
}

void Agent::update()
{
    angle = ofNoise(p.x / *noiseScale, p.y / *noiseScale, noiseZ) * *noiseStrength;
    
    p.x += cos(angle) * stepSize;
    p.y += sin(angle) * stepSize;
    
    checkBorder(p);
    
    noiseZ += noiseZVelocity;
}

void Agent::draw()
{
    drawPoints(p);
}

void Agent::drawPoints(ofPoint pp)
{
    ofDrawCircle(pp.x, pp.y, *radius);
}

bool Agent::isOut()
{
    if(bOut)
    {
        p.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        bOut = false;
    }
    
    return bOut;
}
void Agent::checkBorder(ofPoint p)
{
    if (p.x < 0)
    {
        bOut = true;
    }
    
    if (p.x > ofGetWidth() )
    {
        bOut = true;
    }
    
    if (p.y < 0)
    {
        bOut = true;
    }
    
    if (p.y > ofGetHeight())
    {
        bOut = true;
    }
    
    isOut();
}

void Agent::setNoiseZRange(float theNoiseZrange)
{
    noiseZ = ofRandom(theNoiseZrange);
}

void Agent::reset()
{
    p.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
}

void Agent::mykeyPressed(ofKeyEventArgs& eventArgs)
{
    
}

void Agent::keyReleased(ofKeyEventArgs &e)
{
    e.key == 'g' ? cout << e.key << endl : cout << "" << endl;
}

void Agent::exit()
{
    //ofRemoveListener(ofEvents().keyPressed, this, &Agent::mykeyPressed);
}











