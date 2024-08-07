/*
  ==============================================================================

    AdsrData.h
    Created: 18 Jul 2024 2:39:44pm
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR {
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
private:
    juce::ADSR::Parameters adsrParams;
};
