#pragma once

#include "ofMain.h"

class PitchDot {

private:

    // Circle's color
    ofColor color;

    // Circle's radius
    int radius;
  
    // Circle's radius when it's active
    int activeRadiusOffset;

    // Circle's center.
    glm::vec2 center;
  
    // Dot index in the map.
    int pitchIndex;
  
    // Midi note for this pitch. 
    int pitchMidiNote;

public:
    void setup(int radius, glm::vec2 pitchPosition, int index);
    void update();
    void draw();
  
    // Return the pitch's index.
    int getPitchIndex();
  
    // Test if a coordinate is hitting a circle.
    bool isHitSuccessful(glm::vec2 mousePosition);
  
    // Send the midi note to Ableton to play the note associated with this pitch. 
    void play();
  
    // We will externally set the Midi note number for each pitch dot when the application initializes.
    // This will be assigned based on pitch space concept. 
    void setMidiPitchNote(int noteNumber);
};
