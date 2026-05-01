#include "PresetData.h"

/**
    PresetData.cpp — empty embedded-data arrays for CI builds.
    In a production export_ci build HISE replaces this file with actual
    binary-encoded preset / sample-map / script data.
*/
namespace PresetData
{
    static const char preset_data[]       = {};
    const char*  preset     = preset_data;
    const int    presetSize = 0;

    static const char samplemaps_data[]   = {};
    const char*  samplemaps     = samplemaps_data;
    const int    samplemapsSize = 0;

    static const char midiFiles_data[]    = {};
    const char*  midiFiles     = midiFiles_data;
    const int    midiFilesSize = 0;

    static const char externalFiles_data[] = {};
    const char*  externalFiles     = externalFiles_data;
    const int    externalFilesSize = 0;

    static const char userPresets_data[]  = {};
    const char*  userPresets     = userPresets_data;
    const int    userPresetsSize = 0;

    static const char impulses_data[]     = {};
    const char*  impulses     = impulses_data;
    const int    impulsesSize = 0;

    static const char images_data[]       = {};
    const char*  images     = images_data;
    const int    imagesSize = 0;
}
