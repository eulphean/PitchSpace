#include "PitchDot.h"
#include "Midi.h"

using namespace std;

//--------------------------------------------------------------
void PitchDot::setup(int r, glm::vec2 pitchPosition, int index){
  // Set radius and color
  radius = r;
  color = ofColor::fromHsb(ofRandom(255), 255, 255);
  center = pitchPosition;
  pitchIndex = index;
  // Default pitch midi node. This gets update once the pitch dot is created. 
  pitchMidiNote = 48;
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

bool PitchDot::isHitSuccessful(glm::vec2 mousePosition) {
  // Calculate distance from the center to the mouse.
  float distance = glm::distance(mousePosition, center);
  if (distance <= radius) {
    return true;
  }
  
  return false;
}

int PitchDot::getPitchIndex() {
  return pitchIndex;
}

void PitchDot::play() {
  cout << "Playing Pitch Index: " << pitchIndex << " Note: " << pitchMidiNote << endl;
  Midi::instance().sendMidiNoteOn(pitchMidiNote);
}

void PitchDot::setMidiPitchNote(int noteNumber) {
  pitchMidiNote = noteNumber; 
}
