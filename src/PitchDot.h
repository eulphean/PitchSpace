#pragma once

#include "ofMain.h"

class PitchDot {

private:

    // Circle's color
    ofColor color;

    // Circle's radius
    int radius;

    // Circle's center.
    ofPoint center;

public:

    void setup(int radius, ofPoint pitchPosition);
    void update();
    void draw();

    // Test if a coordinate is hitting a circle.
    bool hitTest();
};
