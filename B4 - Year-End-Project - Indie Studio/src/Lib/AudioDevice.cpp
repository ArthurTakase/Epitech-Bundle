/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AudioDevice
*/

#include "AudioDevice.hpp"

#include "raylib.h"

/**
 * > Initialize the audio device
 */
void AudioDevice::initialize() noexcept
{
    InitAudioDevice();
}

/**
 * It updates the music
 *
 * @param scene The scene to update the music of.
 */
void AudioDevice::update(const Scene& scene) noexcept
{
    scene.updateMusic();
}

/**
 * It closes the audio device.
 */
void AudioDevice::close() noexcept
{
    CloseAudioDevice();
}

/**
 * It sets the music volume
 *
 * @param value The volume of the music.
 */
void AudioDevice::setMusic(float value) noexcept
{
    SetMasterVolume(value / 100);
}