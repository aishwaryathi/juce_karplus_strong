/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class _101723test2AudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    _101723test2AudioProcessor();
    ~_101723test2AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    float mGain {0.5};
    double sliderVal = 0;

private:

    juce::dsp::LadderFilter <float> filter;
    juce::dsp::Chorus <float> chorusEffect;
//    juce::dsp::Gain<float> gainProcessor;
    std::vector<float> delayLine;
    int writePosition = 0;
    float lastSample = 0.0f;
    
    // Helper method to initialize the delay line
    void initializeDelayLine(float frequency) {
        auto delayLineLength = static_cast<int>(getSampleRate() / frequency);
        delayLine.resize(delayLineLength);
        std::generate(delayLine.begin(), delayLine.end(), []() { return static_cast<float>(std::rand()) / RAND_MAX * 2.0f - 1.0f; }); // Fill with noise
        writePosition = 0;
    }
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_101723test2AudioProcessor)
};
