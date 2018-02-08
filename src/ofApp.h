#pragma once

#include "ofMain.h"
#include "PitchDot.h"

using namespace std;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
  
    // Setup midi pitch notes. 
    void setupPitchDotsMidi();

    // We want to lay a 6x6 grid.
    const int gridSize = 6;

    // Dots laid out on the screen that are pitches.
    vector<PitchDot> pitches;
  
    // Last active pitch index that was played.
    int lastActivePitchIndex; 
};
