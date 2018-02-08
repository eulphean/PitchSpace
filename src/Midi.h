// Singleton pattern for handling Midi calls by
// multiple components.

#pragma once
#include "ofMain.h"
#include "ofxMidi.h"

class Midi {
  public:
    void setup();
    void exit();
    void sendMidiNoteOn(int midiNote);
    void sendMidiNoteOnChannel(int channel, int midiNote);
    void sendMidiNoteOff(int midiNote);
    
    static Midi &instance();
    
  private:
    ofxMidiOut midiOut;
    static Midi m;
    int defaultChannel;
};
