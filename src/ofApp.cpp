#include "ofApp.h"
#include "Midi.h"

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    // Setup the midi connection.
    Midi::instance().setup();
    
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
  
    // Setup MIDI notes for pitch dots.
    setupPitchDotsMidi();
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mousePosition (ofGetMouseX(), ofGetMouseY());
  
    // Update logic for each pitch. 
    for (auto& pitch: pitches) {
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

void ofApp::setupPitchDotsMidi() {
  
  // Row 1
  pitches[0].setMidiPitchNote(46);
  pitches[1].setMidiPitchNote(53);
  pitches[2].setMidiPitchNote(48);
  pitches[3].setMidiPitchNote(67);
  pitches[4].setMidiPitchNote(74);
  pitches[5].setMidiPitchNote(81);
  
  // Row 2
  pitches[6].setMidiPitchNote(42);
  pitches[7].setMidiPitchNote(49);
  pitches[8].setMidiPitchNote(55);
  pitches[9].setMidiPitchNote(63);
  pitches[10].setMidiPitchNote(70);
  pitches[11].setMidiPitchNote(77);
  
  // Row 3
  pitches[12].setMidiPitchNote(38);
  pitches[13].setMidiPitchNote(45);
  pitches[14].setMidiPitchNote(52);
  pitches[15].setMidiPitchNote(59);
  pitches[16].setMidiPitchNote(66);
  pitches[17].setMidiPitchNote(72);
  
  // Row 4
  pitches[18].setMidiPitchNote(34);
  pitches[19].setMidiPitchNote(41);
  pitches[20].setMidiPitchNote(48);
  pitches[21].setMidiPitchNote(55);
  pitches[22].setMidiPitchNote(63);
  pitches[23].setMidiPitchNote(69);
  
  // Row 5
  pitches[24].setMidiPitchNote(30);
  pitches[25].setMidiPitchNote(37);
  pitches[26].setMidiPitchNote(32);
  pitches[27].setMidiPitchNote(51);
  pitches[28].setMidiPitchNote(58);
  pitches[29].setMidiPitchNote(65);
  
  // Row 6
  pitches[30].setMidiPitchNote(27);
  pitches[31].setMidiPitchNote(33);
  pitches[32].setMidiPitchNote(40);
  pitches[33].setMidiPitchNote(48);
  pitches[34].setMidiPitchNote(54);
  pitches[35].setMidiPitchNote(61);
}
