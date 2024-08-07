/*
  ==============================================================================

    FilterData.h
    Created: 19 Jul 2024 11:19:26am
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>

class FilterData {
public:
    void prepareToPlay(double sampleRate, int samplesPerBlock, int numChannels);
    void process(juce::AudioBuffer<float>& buffer);
    void updateParameters(const int filterType, const float frequency, const float resonance, const float modulator = 1.0f);
    void reset();

private:
    juce::dsp::StateVariableTPTFilter<float> filter;
    bool isPrepared{ false };
};
