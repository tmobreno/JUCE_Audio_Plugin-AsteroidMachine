/*
  ==============================================================================

    OscComponent.cpp
    Created: 18 Jul 2024 5:42:37pm
    Author:  tmobr

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray choices{ "Sine", "Saw", "Square" };
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);

    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector); 

    setSlider(fmFreqSlider, fmFreqAttachment, apvts, fmFreqId);
    setSlider(fmDepthSlider, fmDepthAttachment, apvts, fmDepthId);

    oscTypeLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::osc_type_lbl_png, BinaryData::osc_type_lbl_pngSize));
    fmFreqLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::fm_freq_lbl_png, BinaryData::fm_freq_lbl_pngSize));
    fmDepthLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::fm_depth_lbl_png, BinaryData::fm_depth_lbl_pngSize));

    addAndMakeVisible(fmFreqLabel);
    addAndMakeVisible(fmDepthLabel);
    addAndMakeVisible(oscTypeLabel);

    fmFreqSlider.setRandomImage();
    fmDepthSlider.setRandomImage();
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    //g.setColour(juce::Colours::white);
    //g.drawRect(getLocalBounds());
}

void OscComponent::resized()
{
    const auto sliderWidth = 100;
    const auto sliderHeight = 90;
    const auto labelYOffset = 20;
    const auto labelHeight = 20;
    const auto sliderPosX = 40;
    const auto sliderPosY = 60;

    oscWaveSelector.setBounds(5, 0, 90, 20);
    oscTypeLabel.setBounds(oscWaveSelector.getRight() + 5, 0, 90, 20);

    fmFreqSlider.setBounds(sliderPosX, sliderPosY, sliderWidth, sliderHeight);
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - labelYOffset,fmFreqSlider.getWidth(), labelHeight);

    fmDepthSlider.setBounds(fmFreqSlider.getRight(), sliderPosY, sliderWidth, sliderHeight);
    fmDepthLabel.setBounds(fmDepthSlider.getX(), fmDepthSlider.getY() - labelYOffset, fmDepthSlider.getWidth(), labelHeight);
}

void OscComponent::setSlider(juce::Slider& slider,
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
