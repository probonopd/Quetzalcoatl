/**
    Plugin.cpp — HISE frontend plugin entry point for CI/CMake builds.

    In a production export_ci run HISE auto-generates this file; here we
    provide the same boilerplate manually, using empty (external) data so
    the plugin compiles and links without any actual sample/preset files.
*/

#include "JuceHeader.h"
#include "PresetData.h"

// ---------------------------------------------------------------------------
// Embedded data registration
// These macros wire up the PresetData arrays to HISE's virtual file-system.
// For CI builds every data source is declared "external" (empty), except
// the pure-metadata ones which we embed as empty arrays.
// ---------------------------------------------------------------------------

BEGIN_EMBEDDED_DATA()
DEFINE_EXTERNAL_DATA(hise::FileHandlerBase::AudioFiles)
DEFINE_EXTERNAL_DATA(hise::FileHandlerBase::Images)
DEFINE_EMBEDDED_DATA(hise::FileHandlerBase::MidiFiles,   PresetData::midiFiles,     PresetData::midiFilesSize)
DEFINE_EMBEDDED_DATA(hise::FileHandlerBase::SampleMaps,  PresetData::samplemaps,    PresetData::samplemapsSize)
DEFINE_EMBEDDED_DATA(hise::FileHandlerBase::Scripts,     PresetData::externalFiles, PresetData::externalFilesSize)
DEFINE_EMBEDDED_DATA(hise::FileHandlerBase::Presets,     PresetData::preset,        PresetData::presetSize)
DEFINE_EMBEDDED_DATA(hise::FileHandlerBase::UserPresets, PresetData::userPresets,   PresetData::userPresetsSize)
END_EMBEDDED_DATA()

// ---------------------------------------------------------------------------
// Static DSP library registration
// ---------------------------------------------------------------------------

REGISTER_STATIC_DSP_LIBRARIES()
{
    REGISTER_STATIC_DSP_FACTORY(hise::HiseCoreDspFactory);
}

// ---------------------------------------------------------------------------
// Copy-protection stub (disabled for this build)
// ---------------------------------------------------------------------------

#if USE_COPY_PROTECTION
RSAKey hise::Unlocker::getPublicKey() { return RSAKey(""); }
#endif

// ---------------------------------------------------------------------------
// Plugin factory functions required by JUCE's audio-plugin-client
// ---------------------------------------------------------------------------

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    CREATE_PLUGIN(nullptr, nullptr);
}

AudioProcessor* hise::StandaloneProcessor::createProcessor()
{
    return nullptr;
}

// ---------------------------------------------------------------------------
// HISE FrontendHandler project-info callbacks
// ---------------------------------------------------------------------------

String hise::FrontendHandler::getProjectName()       { return "Quetzalcoatl"; }
String hise::FrontendHandler::getCompanyName()       { return "modularsamples"; }
String hise::FrontendHandler::getCompanyWebsiteName(){ return "http://modularsamples.com"; }
String hise::FrontendHandler::getCompanyCopyright()  { return "(c)2024, Modularsamples"; }
String hise::FrontendHandler::getVersionString()     { return "0.9.2"; }
String hise::FrontendHandler::getAppGroupId()        { return ""; }
String hise::FrontendHandler::getExpansionKey()      { return "Qzex"; }
String hise::FrontendHandler::getExpansionType()     { return "Encrypted"; }
String hise::FrontendHandler::getHiseVersion()       { return "4.1.0"; }
String hise::FrontendHandler::getDefaultUserPreset() const { return ""; }
