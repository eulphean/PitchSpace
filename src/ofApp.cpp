#include "ofApp.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(60);
    lastActivePitchIndex = -1; 

    // Diameter for each pitch dot.
    int circleRadius = ( ofGetWidth() / gridSize ) / 2;

    int y = circleRadius;
  
    // Pitch index to recognize which Pitch got struck. 
    int index = 0;
  
    // Lay out the pitch dot space grid row by row. 
    for (int i = 0; i < gridSize; i++) {
        int x = circleRadius;

        for (int j = 0; j < gridSize; j++) {
            PitchDot pitch;
            glm::vec2 pitchPosition(x, y);
            // Setup pitch.
            pitch.setup(circleRadius, pitchPosition, index);
            // Push the pitch in the vector.
            pitches.push_back(pitch);

            // Increment x
            x = x + circleRadius * 2;
          
            // Increment pitch index.
            index++;
        }

        // Increment y
        y = y + circleRadius * 2;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePosition (ofGetMouseX(), ofGetMouseY());
  
    // Update logic for each pitch. 
    for (auto pitch: pitches) {
      if (pitch.isHitSuccessful(mousePosition)) {
        int index = pitch.getPitchIndex();
        
        // Only play the note when the previous note played was different than the current
        // note being played. 
        if (lastActivePitchIndex != index) {
          lastActivePitchIndex = index;
          pitch.play();
        }
      }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the pitches.
   for (PitchDot pitch: pitches) {
      pitch.draw();
   }
}
