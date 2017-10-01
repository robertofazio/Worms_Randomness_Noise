#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofBackground(80,70,65);
    
    nMax = 10000;

    initGui();
    bGui = true;
    bReset = false;
    bSave = false;
    bSaveFrame = false;
    gui->setVisible(bGui);

    fboTrail.allocate(ofGetWidth(), ofGetHeight());
    fboTracing.allocate(ofGetWidth(), ofGetHeight());

    _agent.noiseScale = &noiseScale;
    _agent.noiseStrength = &noiseStrength;
    _agent.noiseZRange = &noiseZRange;
    _agent.noiseZVelocity = noiseZVelocity;
    _agent.agentsAlpha = &agentsAlpha;
    _agent.radius = &radius;
    
    for(int i = 0; i < nMax; i++)
    {
        agents.push_back(_agent);
        agents[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle(ofToString((int)ofGetFrameRate()));
    
    for(int i = 0; i < nMax; i++)
    {
        agents[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    fboTrail.begin();
    {
        ofPushStyle();
        ofSetColor(0, 0, 0, 20);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255,255,255, agentsAlpha);
        for(int i = 0; i < nMax; i++)
            agents[i].draw();
        ofPopStyle();
    }
    fboTrail.end();
    
    fboTrail.draw(0,0);
}

void ofApp::exit()
{
    gui->saveSettings("settings.xml");
    delete gui;
    
    _agent.exit();
}

void ofApp::initGui()
{
    gui = new ofxUISuperCanvas("WORMS");

    gui->addIntSlider("NUM MAX", 1, nMax, nMax);
    gui->addSlider("NOISE SCALE", 1.0f, 1000.0f, noiseScale);
    gui->addSlider("NOISE STRENGTH", 0.0f, 100.0f, noiseStrength);
    gui->addSlider("NOISE ZRANGE", 0, 5, noiseZRange);
    gui->addSlider("AGENT ALPHA",0.0,255.0, agentsAlpha);
    gui->addSlider("RADIUS", 1, 10, radius);
    gui->addLabelButton("RESET", bReset);
    gui->addLabelButton("SAVE SETTING", bSave);
    gui->addLabelButton("EXPORT FRAME", bSaveFrame);
    gui->addSpacer();
    gui->addLabel("'g' toggle UI");

    gui->autoSizeToFitWidgets();
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui->loadSettings("settings.xml");
    
}

void ofApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.getName() == "NOISE SCALE")
    {
        ofxUISlider *slider = e.getSlider();
        noiseScale = slider->getScaledValue();
    }
    else if(e.getName() == "NOISE STRENGTH")
    {
        ofxUISlider *slider = e.getSlider();
        noiseStrength = slider->getScaledValue();
    }
    else if(e.getName() == "NOISE ZRANGE")
    {
        ofxUISlider *slider = e.getSlider();
        noiseZRange = slider->getScaledValue();
    }
    else if(e.getName() == "AGENT ALPHA")
    {
        ofxUISlider *slider = e.getSlider();
        agentsAlpha = slider->getScaledValue();
    }
    else if(e.getName() == "RADIUS")
    {
        ofxUISlider *slider = e.getSlider();
        radius = (int)slider->getScaledValue();
    }
    else if(e.getName() == "NUM MAX")
    {
        ofxUIIntSlider *slider = (ofxUIIntSlider*) e.getSlider();
        nMax = slider->getScaledValue();
        //ofLog() << nMax;
    }
    else if(e.getName() == "RESET")
    {
        ofxUILabelButton * b = (ofxUILabelButton*) e.getButton();
        bReset = b->getValue();
        
        if(bReset)
        {
            for(int i = 0; i < nMax; i++)
                agents[i].reset();
        }
    }
    else if (e.getName() == "SAVE SETTING")
    {
        ofxUILabelButton *button = (ofxUILabelButton*) e.getButton();
        bSave = button->getValue();
        
        if(bSave)
        {
            gui->saveSettings("settings.xml");
            ofLog() << "XML Saved";
        }
    }
    else if (e.getName() == "EXPORT FRAME")
    {
        ofxUILabelButton *button = (ofxUILabelButton*) e.getButton();
        bSaveFrame = button->getValue();
        
        if(bSaveFrame)
        {
            ofSaveScreen(ofToString("frame_") + ofToString((int)ofGetElapsedTimef()) + ofToString(".jpg"));
            ofLog() << "Frame Saved";
        }


    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key == 'g')
    {
        bGui = !bGui;
        gui->setVisible(bGui);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
