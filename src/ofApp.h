#pragma once

#include "ofMain.h"
#include "PitchDot.h"

using namespace std;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    // We want to lay a 6x6 grid.
    const int gridSize = 6;

    // Dots laid out on the screen that are pitches.
    vector<PitchDot> pitches;
};
