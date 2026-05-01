cmake_minimum_required(VERSION 3.22)
project(Quetzalcoatl VERSION 0.9.2 LANGUAGES CXX)

# ---------------------------------------------------------------------------
# HISE_PATH must be supplied on the cmake command line:
#   cmake -DHISE_PATH=/path/to/HISE ...
# ---------------------------------------------------------------------------
if(NOT DEFINED HISE_PATH)
    message(FATAL_ERROR "HISE_PATH is not set. Pass -DHISE_PATH=<path-to-HISE-source>")
endif()

set(JUCE_PATH "${HISE_PATH}/JUCE")

if(NOT EXISTS "${JUCE_PATH}/extras/Build/CMake/JUCEUtils.cmake")
    message(FATAL_ERROR "Cannot find JUCE at ${JUCE_PATH}. Make sure HISE submodules are initialised.")
endif()

# ---------------------------------------------------------------------------
# Bootstrap JUCE's CMake system.
# JUCE_customized has no root CMakeLists.txt, so we drive the build
# by pointing add_subdirectory at the pre-written wrapper created by the CI
# workflow (JUCE_PATH/CMakeLists.txt), or by including JUCEUtils.cmake and
# the sub-CMakeLists files directly.
# ---------------------------------------------------------------------------
if(EXISTS "${JUCE_PATH}/CMakeLists.txt")
    # The CI workflow wrote a minimal root CMakeLists.txt – use it.
    add_subdirectory("${JUCE_PATH}" "${CMAKE_BINARY_DIR}/JUCE_build" EXCLUDE_FROM_ALL)
else()
    message(FATAL_ERROR
        "No CMakeLists.txt found in ${JUCE_PATH}. "
        "The workflow should have created one before invoking cmake.")
endif()

# ---------------------------------------------------------------------------
# Add HISE modules (order matters: dependencies before dependents)
# ---------------------------------------------------------------------------
foreach(_mod
        hi_faust_types
        hi_faust
        hi_zstd
        hi_rlottie
        hi_lac
        hi_dsp_library
        hi_tools
        hi_snex
        hi_streaming
        hi_core
        hi_scripting
        hi_frontend
        melatonin_blur)
    if(EXISTS "${HISE_PATH}/${_mod}/${_mod}.h")
        juce_add_module("${HISE_PATH}/${_mod}" ALIAS_NAMESPACE hise)
    else()
        message(WARNING "HISE module not found – skipping: ${_mod}")
    endif()
endforeach()

# ---------------------------------------------------------------------------
# Plugin target
# ---------------------------------------------------------------------------
juce_add_plugin(Quetzalcoatl
    COMPANY_NAME             "modularsamples"
    COMPANY_WEBSITE          "http://modularsamples.com"
    COMPANY_COPYRIGHT        "(c)2024, Modularsamples"
    PLUGIN_MANUFACTURER_CODE Msms
    PLUGIN_CODE              Msqz
    FORMATS                  VST3
    PRODUCT_NAME             "Quetzalcoatl"
    BUNDLE_ID                "com.modularsamples.product"
    VERSION                  "0.9.2"
    IS_SYNTH                 TRUE
    NEEDS_MIDI_INPUT         TRUE
    NEEDS_MIDI_OUTPUT        FALSE
    IS_MIDI_EFFECT           FALSE
    VST3_CATEGORIES          "Instrument" "Synth"
)

# ---------------------------------------------------------------------------
# JuceHeader.h (required by Plugin.cpp and factory.cpp via #include <JuceHeader.h>)
# ---------------------------------------------------------------------------
juce_generate_juce_header(Quetzalcoatl)

# ---------------------------------------------------------------------------
# Sources
# ---------------------------------------------------------------------------
target_sources(Quetzalcoatl PRIVATE
    Source/Plugin.cpp
    Source/PresetData.cpp
    AdditionalSourceCode/nodes/factory.cpp
)

# ---------------------------------------------------------------------------
# Include paths
# Source/      → provides AppConfig.h (HISE uses #include "AppConfig.h")
# AdditionalSourceCode/nodes/ → provides includes.h referenced by factory.cpp
# ---------------------------------------------------------------------------
target_include_directories(Quetzalcoatl PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Source"
    "${CMAKE_CURRENT_SOURCE_DIR}/AdditionalSourceCode"
    "${CMAKE_CURRENT_SOURCE_DIR}/AdditionalSourceCode/nodes"
)

# ---------------------------------------------------------------------------
# Compile definitions
# These match project_info.xml ExtraDefinitionsLinux + HISE frontend flags.
# ---------------------------------------------------------------------------
target_compile_definitions(Quetzalcoatl PRIVATE
    # HISE build mode
    USE_FRONTEND=1
    USE_BACKEND=0
    IS_STANDALONE_APP=0
    IS_STANDALONE_FRONTEND=0
    FRONTEND_IS_PLUGIN=1
    USE_RAW_FRONTEND=0
    USE_COPY_PROTECTION=0
    HI_EXPORT_DSP_LIBRARY=0
    HISE_MIDIFX_PLUGIN=0
    HISE_ENABLE_MIDI_INPUT_FOR_FX=0
    PROCESS_SOUND_GENERATORS_IN_FX_PLUGIN=0

    # Plugin channel layout (stereo out, instrument synth)
    HISE_NUM_PLUGIN_CHANNELS=2

    # From ExtraDefinitionsLinux in project_info.xml
    HISE_COMPLAIN_ABOUT_ILLEGAL_BUFFER_SIZE=0
    JUCE_DISABLE_NATIVE_FILECHOOSERS=1
    HISE_SAMPLE_DIALOG_SHOW_INSTALL_BUTTON=0
    HISE_SAMPLE_DIALOG_SHOW_LOCATE_BUTTON=0

    # Faust disabled
    HISE_INCLUDE_FAUST=0
    HISE_INCLUDE_FAUST_JIT=0

    # Loris disabled (keeps binary smaller and avoids extra deps)
    HISE_INCLUDE_LORIS=0

    # Rlottie disabled (no Lottie animations needed in CI build)
    HISE_INCLUDE_RLOTTIE=0

    # Misc
    USE_GLITCH_DETECTION=1
    ENABLE_PLOTTER=0
    ENABLE_SCRIPTING_SAFE_CHECKS=0
    ENABLE_SCRIPTING_BREAKPOINTS=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_USE_DARK_SPLASH_SCREEN=1
    NUM_POLYPHONIC_VOICES=128
    JUCE_STRICT_REFCOUNTEDPOINTER=1
    JUCE_LOAD_CURL_SYMBOLS_LAZILY=1
)

# Silence some common HISE/JUCE warnings to keep CI output readable
target_compile_options(Quetzalcoatl PRIVATE
    -fpermissive
    -Wno-reorder
    -Wno-inconsistent-missing-override
    -Wno-unused-variable
    -Wno-sign-compare
)

# ---------------------------------------------------------------------------
# Link libraries
# ---------------------------------------------------------------------------
target_link_libraries(Quetzalcoatl PRIVATE
    # JUCE modules
    juce::juce_core
    juce::juce_events
    juce::juce_graphics
    juce::juce_data_structures
    juce::juce_dsp
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_cryptography
    juce::juce_audio_basics
    juce::juce_audio_devices
    juce::juce_audio_formats
    juce::juce_audio_processors
    juce::juce_audio_plugin_client
    juce::juce_product_unlocking
    juce::juce_audio_utils
    juce::juce_opengl

    # HISE modules
    hise::hi_faust_types
    hise::hi_faust
    hise::hi_zstd
    hise::hi_rlottie
    hise::hi_lac
    hise::hi_dsp_library
    hise::hi_tools
    hise::hi_snex
    hise::hi_streaming
    hise::hi_core
    hise::hi_scripting
    hise::hi_frontend
    hise::melatonin_blur

    # System
    juce::juce_recommended_warning_flags
    juce::juce_recommended_config_flags
)

# ---------------------------------------------------------------------------
# FluidSynth (system library, installed via apt libfluidsynth-dev)
# ---------------------------------------------------------------------------
find_package(PkgConfig REQUIRED)
pkg_check_modules(FLUIDSYNTH REQUIRED fluidsynth)
target_link_libraries(Quetzalcoatl PRIVATE ${FLUIDSYNTH_LIBRARIES})
target_include_directories(Quetzalcoatl PRIVATE ${FLUIDSYNTH_INCLUDE_DIRS})
target_compile_options(Quetzalcoatl PRIVATE ${FLUIDSYNTH_CFLAGS_OTHER})
