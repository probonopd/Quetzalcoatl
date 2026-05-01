/**
    AppConfig.h for CMake-based frontend VST3 plugin build.
    This file replaces the Projucer-generated AppConfig.h.
    JUCE_MODULE_AVAILABLE_* flags are set by juce_add_module() via compile definitions.
    JucePlugin_* flags are set by juce_add_plugin() via compile definitions.
*/

#pragma once

// ============================================================================
// HISE frontend plugin configuration
// ============================================================================

#ifndef USE_BACKEND
#define USE_BACKEND 0
#endif

#ifndef USE_FRONTEND
#define USE_FRONTEND 1
#endif

#ifndef USE_RAW_FRONTEND
#define USE_RAW_FRONTEND 0
#endif

#ifndef IS_STANDALONE_APP
#define IS_STANDALONE_APP 0
#endif

#ifndef IS_STANDALONE_FRONTEND
#define IS_STANDALONE_FRONTEND 0
#endif

#ifndef FRONTEND_IS_PLUGIN
#define FRONTEND_IS_PLUGIN 1
#endif

#ifndef USE_COPY_PROTECTION
#define USE_COPY_PROTECTION 0
#endif

#ifndef USE_SCRIPT_COPY_PROTECTION
#define USE_SCRIPT_COPY_PROTECTION 0
#endif

#ifndef HI_EXPORT_DSP_LIBRARY
#define HI_EXPORT_DSP_LIBRARY 0
#endif

#ifndef IS_STATIC_DSP_LIBRARY
#define IS_STATIC_DSP_LIBRARY 0
#endif

#ifndef HISE_MIDIFX_PLUGIN
#define HISE_MIDIFX_PLUGIN 0
#endif

#ifndef HISE_ENABLE_MIDI_INPUT_FOR_FX
#define HISE_ENABLE_MIDI_INPUT_FOR_FX 0
#endif

#ifndef PROCESS_SOUND_GENERATORS_IN_FX_PLUGIN
#define PROCESS_SOUND_GENERATORS_IN_FX_PLUGIN 0
#endif

#ifndef USE_GLITCH_DETECTION
#define USE_GLITCH_DETECTION 1
#endif

#ifndef ENABLE_PLOTTER
#define ENABLE_PLOTTER 0
#endif

#ifndef ENABLE_SCRIPTING_SAFE_CHECKS
#define ENABLE_SCRIPTING_SAFE_CHECKS 0
#endif

#ifndef ENABLE_SCRIPTING_BREAKPOINTS
#define ENABLE_SCRIPTING_BREAKPOINTS 0
#endif

#ifndef HISE_COMPLAIN_ABOUT_ILLEGAL_BUFFER_SIZE
#define HISE_COMPLAIN_ABOUT_ILLEGAL_BUFFER_SIZE 0
#endif

#ifndef JUCE_DISABLE_NATIVE_FILECHOOSERS
#define JUCE_DISABLE_NATIVE_FILECHOOSERS 1
#endif

#ifndef HISE_SAMPLE_DIALOG_SHOW_INSTALL_BUTTON
#define HISE_SAMPLE_DIALOG_SHOW_INSTALL_BUTTON 0
#endif

#ifndef HISE_SAMPLE_DIALOG_SHOW_LOCATE_BUTTON
#define HISE_SAMPLE_DIALOG_SHOW_LOCATE_BUTTON 0
#endif

#ifndef HISE_NUM_MACROS
#define HISE_NUM_MACROS 8
#endif

#ifndef USE_CUSTOM_FRONTEND_TOOLBAR
#define USE_CUSTOM_FRONTEND_TOOLBAR 0
#endif

#ifndef HI_SUPPORT_FULL_DYNAMICS_HLAC
#define HI_SUPPORT_FULL_DYNAMICS_HLAC 0
#endif

#ifndef READ_ONLY_FACTORY_PRESETS
#define READ_ONLY_FACTORY_PRESETS 0
#endif

#ifndef HISE_USE_OPENGL_FOR_PLUGIN
#define HISE_USE_OPENGL_FOR_PLUGIN 0
#endif

// ============================================================================
// HISE DSP Library flags
// ============================================================================

#ifndef HISE_INCLUDE_FAUST
#define HISE_INCLUDE_FAUST 0
#endif

#ifndef HISE_FAUST_USE_LLVM_JIT
#define HISE_FAUST_USE_LLVM_JIT 0
#endif

#ifndef HISE_INCLUDE_FAUST_JIT
#define HISE_INCLUDE_FAUST_JIT 0
#endif

// ============================================================================
// HLAC flags
// ============================================================================

#ifndef HLAC_MEASURE_DECODING_PERFORMANCE
#define HLAC_MEASURE_DECODING_PERFORMANCE 0
#endif

#ifndef HLAC_DEBUG_LOG
#define HLAC_DEBUG_LOG 0
#endif

#ifndef HLAC_INCLUDE_TEST_SUITE
#define HLAC_INCLUDE_TEST_SUITE 0
#endif

// ============================================================================
// SNEX flags
// ============================================================================

#ifndef HISE_INCLUDE_SNEX
#define HISE_INCLUDE_SNEX 1
#endif

// ============================================================================
// Loris flags
// ============================================================================

#ifndef HISE_INCLUDE_LORIS
#define HISE_INCLUDE_LORIS 0
#endif

// ============================================================================
// Rlottie flags
// ============================================================================

#ifndef HISE_INCLUDE_RLOTTIE
#define HISE_INCLUDE_RLOTTIE 0
#endif

// ============================================================================
// JUCE splash screen
// ============================================================================

#ifndef JUCE_DISPLAY_SPLASH_SCREEN
#define JUCE_DISPLAY_SPLASH_SCREEN 0
#endif

#ifndef JUCE_USE_DARK_SPLASH_SCREEN
#define JUCE_USE_DARK_SPLASH_SCREEN 1
#endif

// ============================================================================
// JUCE module flags (set via compile definitions by juce_add_module,
// but provide defaults here for modules that include AppConfig.h early)
// ============================================================================

#ifndef JUCE_MODULE_AVAILABLE_juce_core
#define JUCE_MODULE_AVAILABLE_juce_core 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_events
#define JUCE_MODULE_AVAILABLE_juce_events 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_graphics
#define JUCE_MODULE_AVAILABLE_juce_graphics 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_gui_basics
#define JUCE_MODULE_AVAILABLE_juce_gui_basics 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_gui_extra
#define JUCE_MODULE_AVAILABLE_juce_gui_extra 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_basics
#define JUCE_MODULE_AVAILABLE_juce_audio_basics 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_devices
#define JUCE_MODULE_AVAILABLE_juce_audio_devices 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_formats
#define JUCE_MODULE_AVAILABLE_juce_audio_formats 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_processors
#define JUCE_MODULE_AVAILABLE_juce_audio_processors 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_plugin_client
#define JUCE_MODULE_AVAILABLE_juce_audio_plugin_client 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_audio_utils
#define JUCE_MODULE_AVAILABLE_juce_audio_utils 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_cryptography
#define JUCE_MODULE_AVAILABLE_juce_cryptography 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_data_structures
#define JUCE_MODULE_AVAILABLE_juce_data_structures 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_dsp
#define JUCE_MODULE_AVAILABLE_juce_dsp 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_product_unlocking
#define JUCE_MODULE_AVAILABLE_juce_product_unlocking 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_opengl
#define JUCE_MODULE_AVAILABLE_juce_opengl 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_juce_osc
#define JUCE_MODULE_AVAILABLE_juce_osc 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_core
#define JUCE_MODULE_AVAILABLE_hi_core 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_dsp_library
#define JUCE_MODULE_AVAILABLE_hi_dsp_library 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_faust
#define JUCE_MODULE_AVAILABLE_hi_faust 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_faust_types
#define JUCE_MODULE_AVAILABLE_hi_faust_types 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_frontend
#define JUCE_MODULE_AVAILABLE_hi_frontend 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_lac
#define JUCE_MODULE_AVAILABLE_hi_lac 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_rlottie
#define JUCE_MODULE_AVAILABLE_hi_rlottie 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_scripting
#define JUCE_MODULE_AVAILABLE_hi_scripting 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_snex
#define JUCE_MODULE_AVAILABLE_hi_snex 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_streaming
#define JUCE_MODULE_AVAILABLE_hi_streaming 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_tools
#define JUCE_MODULE_AVAILABLE_hi_tools 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_hi_zstd
#define JUCE_MODULE_AVAILABLE_hi_zstd 1
#endif

#ifndef JUCE_MODULE_AVAILABLE_melatonin_blur
#define JUCE_MODULE_AVAILABLE_melatonin_blur 1
#endif

// ============================================================================
// JUCE standalone application guard
// ============================================================================

#ifndef JUCE_STANDALONE_APPLICATION
#if defined(JucePlugin_Name) && defined(JucePlugin_Build_Standalone)
#define JUCE_STANDALONE_APPLICATION JucePlugin_Build_Standalone
#else
#define JUCE_STANDALONE_APPLICATION 0
#endif
#endif
