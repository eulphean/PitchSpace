#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){    
    // Circle radius we want to have for each circle in the grid.
    int diameter = ofGetWidth()/gridSize;
    circleRadius = diameter/2;
    ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = circleRadius; i < ofGetWidth(); i += circleRadius*2) {
        for (int j = circleRadius; j < ofGetHeight(); j += circleRadius*2) {
            ofPushStyle();
            ofSetColor(ofColor::red);
            ofDrawCircle(i, j, circleRadius);
            ofPopStyle();
        }
    }
}


// Pitch space
// Make a 6 x 6 grid of cirles.
// Each circle will trigger a note when I hover my mouse on top of it.
// I need MIDI to send midi signals to ableton
// Light up each circle on the grid as soon as the mouse hovers on it and that indicates
// that a note is lit up.
