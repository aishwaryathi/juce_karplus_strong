/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class _101723test2AudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    _101723test2AudioProcessorEditor (_101723test2AudioProcessor&);
    ~_101723test2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _101723test2AudioProcessor& audioProcessor;
//    
//    juce::Slider mySlider;
//    juce::Slider pitchSlider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_101723test2AudioProcessorEditor)
};
