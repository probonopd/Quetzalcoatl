#include "PresetData.h"

/**
    PresetData.cpp — empty embedded-data arrays for CI builds.
    In a production export_ci build HISE replaces this file with actual
    binary-encoded preset / sample-map / script data.
*/
namespace PresetData
{
    static const char preset_data[]       = {'\0'};
    const char*  preset     = preset_data;
    const int    presetSize = 0;

    static const char samplemaps_data[]   = {'\0'};
    const char*  samplemaps     = samplemaps_data;
    const int    samplemapsSize = 0;

    static const char midiFiles_data[]    = {'\0'};
    const char*  midiFiles     = midiFiles_data;
    const int    midiFilesSize = 0;

    static const char externalFiles_data[] = {'\0'};
    const char*  externalFiles     = externalFiles_data;
    const int    externalFilesSize = 0;

    static const char userPresets_data[]  = {'\0'};
    const char*  userPresets     = userPresets_data;
    const int    userPresetsSize = 0;

    static const char impulses_data[]     = {'\0'};
    const char*  impulses     = impulses_data;
    const int    impulsesSize = 0;

    static const char images_data[]       = {'\0'};
    const char*  images     = images_data;
    const int    imagesSize = 0;
}
