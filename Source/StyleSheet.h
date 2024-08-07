/*
  ==============================================================================

    StyleSheet.h
    Created: 20 Jul 2024 2:10:35pm
    Author:  tmobr

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class CustomLNF : public juce::LookAndFeel_V4 {
public:
    void drawRotarySlider(juce::Graphics& g,
        int	x,
        int	y,
        int	width,
        int	height,
        float	sliderPos,
        float	rotaryStartAngle,
        float	rotaryEndAngle,
        juce::Slider& slider);
    void drawLinearSlider(juce::Graphics& g,
        int	x,
        int	y,
        int	width,
        int	height,
        float	sliderPos,
        float	minSliderPos,
        float	maxSliderPos,
        juce::Slider::SliderStyle style,
        juce::Slider& slider);
private:
};

class CustomDial : public juce::Slider {
public:
    juce::Image getImage();
    void setRandomImage();
private:
    juce::Image image{ juce::ImageCache::getFromMemory(BinaryData::asteroid_1_png, BinaryData::asteroid_1_pngSize) };
};
