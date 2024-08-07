/*
  ==============================================================================

    OscComponent.h
    Created: 18 Jul 2024 5:42:37pm
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Source/StyleSheet.h"

//==============================================================================
/*
*/
class OscComponent  : public juce::Component
{
public:
    OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId);
    ~OscComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscWaveSelector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscWaveSelectorAttachment;

    CustomDial fmFreqSlider, fmDepthSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fmFreqAttachment, fmDepthAttachment;

    juce::ImageComponent oscTypeLabel;
    juce::ImageComponent fmFreqLabel;
    juce::ImageComponent fmDepthLabel;

    void setSlider(juce::Slider& slider,
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment,
        juce::AudioProcessorValueTreeState& apvts, juce::String paramId);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscComponent)
};
