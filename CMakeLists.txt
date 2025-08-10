cmake_minimum_required(VERSION 3.16)
project(FullMixSculptorPro VERSION 0.5.0)
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
include(FetchContent)
FetchContent_Declare(juce GIT_REPOSITORY https://github.com/juce-framework/JUCE.git GIT_TAG 8.0.8)
FetchContent_MakeAvailable(juce)
set(PROJECT_SOURCES
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/Metering.h
    Source/Metering.cpp
    Source/PresetProfiles.h
    Source/PresetProfiles.cpp
    Source/SuggestionEngine.h
    Source/SuggestionEngine.cpp
    Source/LibrarySuggest.h
    Source/LibrarySuggest.cpp
    Source/SampleAuditioner.h
    Source/SampleAuditioner.cpp
    Source/AutoChopper.h
    Source/AutoChopper.cpp
    Source/KeyDetector.h
    Source/KeyDetector.cpp
)
juce_add_plugin(FullMixSculptorPro
    PRODUCT_NAME "FullMix Sculptor Pro"
    COMPANY_NAME "EMG Production Studios"
    COMPANY_WEBSITE "https://example.com"
    BUNDLE_ID com.emg.fullmixsculptorpro
    PLUGIN_MANUFACTURER_CODE EMGP
    PLUGIN_CODE Fm05
    FORMATS VST3 AU
    VST3_CATEGORIES "Mastering"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    SOURCES ${PROJECT_SOURCES}
)
target_compile_features(FullMixSculptorPro PRIVATE cxx_std_20)
target_compile_definitions(FullMixSculptorPro PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)
target_link_libraries(FullMixSculptorPro PRIVATE juce::juce_audio_utils juce::juce_dsp)
