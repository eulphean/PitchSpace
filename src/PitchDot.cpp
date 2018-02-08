#include "PitchDot.h"

using namespace std;

//--------------------------------------------------------------
void PitchDot::setup(int r, ofPoint pitchPosition){
    // Set radius and color
    radius = r;
    color = ofColor::fromHsb(ofRandom(255), 255, 255);
    center = pitchPosition;
}


//--------------------------------------------------------------
void PitchDot::update(){
}

//--------------------------------------------------------------
void PitchDot::draw(){
    ofPushStyle();
      ofSetColor(color);
      ofDrawCircle(center, radius);
    ofPopStyle();
}

bool PitchDot::hitTest() {
    return true;
}
