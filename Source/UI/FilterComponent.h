/*
  ==============================================================================

    FilterComponent.h
    Created: 19 Jul 2024 11:37:19am
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Source/StyleSheet.h"

//==============================================================================
/*
*/
class FilterComponent  : public juce::Component
{
public:
    FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeSelectorId,
        juce::String filterCutoffId, juce::String filterResId);
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox filterTypeSelector{ "Filter Type" };

    CustomDial filterCutoffSlider, filterResonanceSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> filterResAttachment, filterCutoffAttachment;

    juce::ImageComponent filterTypeLabel;
    juce::ImageComponent filterCutoffLabel;
    juce::ImageComponent filterResLabel;

    void setSlider (juce::Slider& slider,
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment,
        juce::AudioProcessorValueTreeState& apvts, juce::String paramId);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
