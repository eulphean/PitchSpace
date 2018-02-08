#pragma once

#include "ofMain.h"
#include "PitchDot.h"
#include "ofxOsc.h"

using namespace std;
// Update the port after setting the right port through TouchOSC.
#define PORT 8000

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
  
    // Setup midi pitch notes. 
    void setupPitchDotsMidi();

    // We want to lay a 6x6 grid.
    const int gridSize = 6;
    const int mousePositionMidiChannel = 3;
    const int oscPositionMidiChannel = 4;

    // Dots laid out on the screen that are pitches.
    vector<PitchDot> pitches;
  
    // Last active pitch index that was played.
    int lastActiveMousePitchIndex;
    int lastActiveOscPitchIndex;
  
    ofxOscReceiver receive;
    glm::vec2 mappedOsc;
    glm::vec2 mousePosition;
};
