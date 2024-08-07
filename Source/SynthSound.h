/*
  ==============================================================================

    SynthSound.h
    Created: 17 Jul 2024 11:08:58pm
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }
};

