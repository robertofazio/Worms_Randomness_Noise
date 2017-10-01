#pragma once

#include "ofMain.h"
#include "ofxUI.h"

#include "Agent.h"


class ofApp : public ofBaseApp
{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void initGui();
    bool bGui;
    
    float noiseScale;
    float noiseStrength;
    float noiseZRange;
    float noiseZVelocity;
    float agentsAlpha;
    unsigned char radius;
    
    Agent _agent;
    vector<Agent> agents;
    int nMax;
    
    ofxUISuperCanvas *gui;
    ofFbo fboTrail;
    ofFbo fboTracing;
    bool bReset;
    bool bSave;
    bool bSaveFrame;
    

};
