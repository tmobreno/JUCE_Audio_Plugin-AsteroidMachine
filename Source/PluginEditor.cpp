/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SimpleSynthAudioProcessorEditor::SimpleSynthAudioProcessorEditor (SimpleSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    osc(audioProcessor.apvts, "OSC", "FMFREQ", "FMDEPTH"), 
    adsr("Amp Envelope", audioProcessor.apvts,"ATTACK","DECAY","SUSTAIN","RELEASE"),
    filter(audioProcessor.apvts,"FILTERTYPE", "FILTERCUTOFF", "FILTERRES"),
    adsrMod("Mod Envelope", audioProcessor.apvts, "MODATTACK", "MODDECAY", "MODSUSTAIN", "MODRELEASE")
{
    juce::LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);

    setSize (600, 450);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filter);
    addAndMakeVisible(adsrMod);

    titleLabel.setImage(juce::ImageCache::getFromMemory(BinaryData::title_lbl_png, BinaryData::title_lbl_pngSize));
    addAndMakeVisible(titleLabel);
}

SimpleSynthAudioProcessorEditor::~SimpleSynthAudioProcessorEditor()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void SimpleSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void SimpleSynthAudioProcessorEditor::resized()
{
    auto headerOffset = 40;
    auto sideOffset = 20;
    auto headerHeight = 50;
    auto componentTotalHeight = getHeight() - headerHeight;

    titleLabel.setBounds((getWidth() / 2) -  150, 0, getWidth() / 2, headerHeight - 5);

    osc.setBounds(sideOffset, headerOffset, getWidth() / 2, componentTotalHeight / 2);
    adsr.setBounds(osc.getRight() - 10, headerOffset, getWidth() / 2, componentTotalHeight / 2);
    filter.setBounds(sideOffset, (componentTotalHeight / 2) + headerOffset, getWidth() / 2, componentTotalHeight / 2);
    adsrMod.setBounds(filter.getRight() - 10, (componentTotalHeight / 2) + headerOffset, getWidth() / 2, componentTotalHeight / 2);
}