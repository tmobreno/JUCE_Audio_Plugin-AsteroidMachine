/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 18 Jul 2024 2:39:13pm
    Author:  tmobr

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId,
    juce::String sustainId, juce::String releaseId)
{
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    componentName = name;

    setSliderParams(attackSlider, attackAttachment, apvts, attackId);
    setSliderParams(decaySlider, decayAttachment, apvts, decayId);
    setSliderParams(sustainSlider, sustainAttachment, apvts, sustainId);
    setSliderParams(releaseSlider, releaseAttachment, apvts, releaseId);

    aLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::a_lbl_png, BinaryData::a_lbl_pngSize));
    dLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::d_lbl_png, BinaryData::d_lbl_pngSize));
    sLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::s_lbl_png, BinaryData::s_lbl_pngSize));
    rLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::r_lbl_png, BinaryData::r_lbl_pngSize));

    addAndMakeVisible(aLabel);
    addAndMakeVisible(dLabel);
    addAndMakeVisible(sLabel);
    addAndMakeVisible(rLabel);
}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 10;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = (bounds.getHeight() / 1.2f);
    const auto sliderStartX = 0;
    const auto sliderStartY = 25;

    const auto labelStartY = 0;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);

    aLabel.setBounds(attackSlider.getX(), labelStartY, sliderWidth, 25);
    dLabel.setBounds(decaySlider.getX(), labelStartY, sliderWidth, 25);
    sLabel.setBounds(sustainSlider.getX(), labelStartY, sliderWidth, 25);
    rLabel.setBounds(releaseSlider.getX(), labelStartY, sliderWidth, 25);
}

void AdsrComponent::setSliderParams(juce::Slider& slider,
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attachment,
    juce::AudioProcessorValueTreeState& apvts, juce::String paramId) {

    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    slider.setColour(juce::Slider::trackColourId, juce::Colours::white.withAlpha(0.8f));
    slider.setColour(juce::Slider::backgroundColourId, juce::Colours::darkgrey.withAlpha(0.3f));
    slider.setColour(juce::Slider::thumbColourId, juce::Colours::white);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);
}
