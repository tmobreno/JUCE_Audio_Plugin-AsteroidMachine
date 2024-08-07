/*
  ==============================================================================

    AdsrComponent.h
    Created: 18 Jul 2024 2:39:13pm
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId,
        juce::String sustainId, juce::String releaseId);
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    void setSliderParams(juce::Slider& slider,
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment,
        juce::AudioProcessorValueTreeState& apvts, juce::String paramId);

    juce::Slider attackSlider, decaySlider, sustainSlider, releaseSlider;

    std::unique_ptr<SliderAttachment> attackAttachment, decayAttachment, sustainAttachment, releaseAttachment;

    juce::String componentName{ "" };

    juce::ImageComponent aLabel;
    juce::ImageComponent dLabel;
    juce::ImageComponent sLabel;
    juce::ImageComponent rLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
