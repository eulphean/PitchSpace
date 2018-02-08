#include "Midi.h"

void Midi::setup() {
  // MIDI setup.
  midiOut.openVirtualPort("ofxMidiOut"); // open a virtual port
  
  // Default channel to send midi notes on.
  defaultChannel = 2;
}

// Scene selection.
void Midi::sendMidiNoteOn(int midiNote) {
  midiOut.sendNoteOn(defaultChannel, midiNote, 100);
}

void Midi::sendMidiNoteOnChannel(int channel, int midiNote) {
  midiOut.sendNoteOn(channel, midiNote, 100);
}

void Midi::sendMidiNoteOff(int midiNote) {
  midiOut.sendNoteOff(defaultChannel, midiNote, 100);
}

void Midi::exit() {
  midiOut.closePort();
}

Midi &Midi::instance() {
  return m;
}

// For a static class, variable needs to be
// initialized in the implementation file.
Midi Midi::m;
