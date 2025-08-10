#include "PluginProcessor.h"

// JUCE needs this factory to create your processor instance
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FullMixSculptorProAudioProcessor();
}
