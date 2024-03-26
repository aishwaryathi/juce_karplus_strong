/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
_101723test2AudioProcessorEditor::_101723test2AudioProcessorEditor (_101723test2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    mySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mySlider.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 50, 20);
    mySlider.setRange(0.0f, 1.0f, 0.01f);
    mySlider.setValue(0.5f);
    mySlider.addListener(this);
    addAndMakeVisible(mySlider);
    pitchSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    pitchSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 50, 20);
    pitchSlider.setRange(0.0f, 1.0f, 0.01f);
    pitchSlider.setValue(0.5f);
    pitchSlider.addListener(this);
    addAndMakeVisible(pitchSlider);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 300);
}

_101723test2AudioProcessorEditor::~_101723test2AudioProcessorEditor()
{
}

//==============================================================================
void _101723test2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // Fill the background with a solid colour
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // Set text properties
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Gain Change", getLocalBounds(), juce::Justification::centredBottom, 1);
    
    mySlider.setBounds(50, getHeight() / 2 - 150, 100, 200); // Adjusted position for visibility
    pitchSlider.setBounds(150, getHeight() / 2 - 150, 100, 200); // Adjusted position for visibility
}


void _101723test2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void _101723test2AudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
//    if (slider == &mySlider) {
//        audioProcessor.sliderVal = mySlider.getValue();
//    }else if(slider==&pitchSlider) {
//        audioProcessor.sliderVal = pitchSlider.getValue();
//    }
}
