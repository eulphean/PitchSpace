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
  isActive = false;
}


//--------------------------------------------------------------
void PitchDot::update(){

}

//--------------------------------------------------------------
void PitchDot::draw(){
  ofPushStyle();
    // Change the color when dot is active. 
    if (isActive) {
      ofSetColor(ofColor::black);
    } else {
      ofSetColor(color);
    }
    ofDrawCircle(center, radius);
  ofPopStyle();
}

bool PitchDot::isHitSuccessful(glm::vec2 position) {
  // Calculate distance from the center to the mouse.
  float mouseDistance = glm::distance(position, center);
  
  if (mouseDistance <= radius) {
    return true;
  } else {
    return false;
  }
}

int PitchDot::getPitchIndex() {
  return pitchIndex;
}

// Play a midi note on channel. 
void PitchDot::play(int midiChannel) {
  cout << "Playing Pitch Index: " << pitchIndex << " Note: " << pitchMidiNote << endl;
  Midi::instance().sendMidiNoteOnChannel(midiChannel, pitchMidiNote);
}

void PitchDot::setMidiPitchNote(int noteNumber) {
  pitchMidiNote = noteNumber; 
}
