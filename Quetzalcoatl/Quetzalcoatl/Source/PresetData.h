#pragma once

/**
    PresetData.h — minimal stub for CI builds.
    A real export_ci run would embed actual preset/sample-map/script data here;
    for CI we use empty buffers so that the plugin compiles and links cleanly.
*/
namespace PresetData
{
    extern const char*  preset;
    extern const int    presetSize;

    extern const char*  samplemaps;
    extern const int    samplemapsSize;

    extern const char*  midiFiles;
    extern const int    midiFilesSize;

    extern const char*  externalFiles;
    extern const int    externalFilesSize;

    extern const char*  userPresets;
    extern const int    userPresetsSize;

    // Impulse responses / audio files (used when EmbedAudioFiles is enabled)
    extern const char*  impulses;
    extern const int    impulsesSize;

    // Images (used when EmbedImageFiles is enabled)
    extern const char*  images;
    extern const int    imagesSize;
}
