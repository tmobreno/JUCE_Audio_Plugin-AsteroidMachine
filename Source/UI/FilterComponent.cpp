/*
  ==============================================================================

    FilterComponent.cpp
    Created: 19 Jul 2024 11:37:19am
    Author:  tmobr

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeSelectorId,
    juce::String filterCutoffId, juce::String filterResId)
{
    juce::StringArray choices{ "Low-Pass", "Band-Pass", "High-Pass" };
    filterTypeSelector.addItemList(choices, 1);
    addAndMakeVisible(filterTypeSelector);
    addAndMakeVisible(filterTypeLabel);

    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, filterTypeSelectorId, filterTypeSelector);

    setSlider(filterCutoffSlider, filterCutoffAttachment, apvts, filterCutoffId);
    setSlider(filterResonanceSlider, filterResAttachment, apvts, filterResId);

    filterTypeLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::filter_type_lbl_png, BinaryData::filter_type_lbl_pngSize));
    filterCutoffLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::cutoff_lbl_png, BinaryData::cutoff_lbl_pngSize));
    filterResLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::resonance_lbl_png, BinaryData::resonance_lbl_pngSize));

    addAndMakeVisible(filterTypeLabel);
    addAndMakeVisible(filterCutoffLabel);
    addAndMakeVisible(filterResLabel);

    filterCutoffSlider.setRandomImage();
    filterResonanceSlider.setRandomImage();
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (juce::Graphics& g)
{
    //auto bounds = getLocalBounds().reduced(5);
    //auto labelSpace = bounds.removeFromTop(25.0f);

    g.fillAll(juce::Colours::black);
    //g.drawText("Filter", labelSpace.withX(5), juce::Justification::left);
}

void FilterComponent::resized()
{
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    const auto sliderPosX = 40;
    const auto sliderPosY = 60;

    filterTypeSelector.setBounds(5, 0, 90, 20);
    filterTypeLabel.setBounds(filterTypeSelector.getRight()+5, 0, 120, 20);

    filterCutoffSlider.setBounds(sliderPosX, sliderPosY, sliderWidth, sliderHeight);
    filterCutoffLabel.setBounds(filterCutoffSlider.getX(), filterCutoffSlider.getY() - labelYOffset, filterCutoffSlider.getWidth(), labelHeight);

    filterResonanceSlider.setBounds(filterCutoffSlider.getRight(), sliderPosY, sliderWidth, sliderHeight);
    filterResLabel.setBounds(filterResonanceSlider.getX(), filterResonanceSlider.getY() - labelYOffset, filterResonanceSlider.getWidth(), labelHeight);

}

void FilterComponent::setSlider(juce::Slider& slider,
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment,
    juce::AudioProcessorValueTreeState& apvts, juce::String paramId) {

    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::white.withAlpha(0.8f));
    slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkgrey.withAlpha(0.3f));
    slider.setColour(juce::Slider::thumbColourId, juce::Colours::white);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);
}
