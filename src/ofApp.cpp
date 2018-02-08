#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(60);

    // Diameter for each pitch dot.
    int circleRadius = ( ofGetWidth() / gridSize ) / 2;

    int x = circleRadius;

    // Create the grid.
    for (int i = 0; i < gridSize; i++) {
        int y = circleRadius;

        for (int j = 0; j < gridSize; j++) {
            PitchDot pitch;
            ofPoint pitchPosition(x, y);
            // Setup pitch.
            pitch.setup(circleRadius, pitchPosition);

            // Push the pitch in the vector.
            pitches.push_back(pitch);

            // Increment y
            y = y + circleRadius * 2;
        }

        // Increment x
        x = x + circleRadius * 2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    // Hit test.
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the pitches.
   for (PitchDot pitch: pitches) {
      pitch.draw();
   }
}


// Pitch space
// Each circle will trigger a note when I hover my mouse on top of it.
// I need MIDI to send midi signals to ableton
// Light up each circle on the grid as soon as the mouse hovers on it and that indicates
// that a note is lit up.
