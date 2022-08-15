/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sound
*/

#include "Sound.hpp"

/**
 * It loads a sound from a file and sets the volume to 1
 *
 * @param path The path to the sound file.
 */
SoundManager::SoundManager(const std::string& path) noexcept
    : sound_(LoadSound(path.c_str()))
{
    setVolume(1);
    load_ = true;
}

/**
 * "Move the sound from the other SoundManager into this one, and mark the other one as unloaded."
 *
 * The first line of the function is the function declaration. It's a move constructor, so it takes
 * a SoundManager&& as a parameter. The && is a reference to a reference, which is a rvalue
 * reference. A rvalue reference is a reference to a temporary object
 *
 * @param other The SoundManager object to move from.
 */
SoundManager::SoundManager(SoundManager&& other) noexcept
    : sound_(std::move(other.sound_))
{
    other.unloaded_ = true;
    other.setVolume(1);
}

/**
 * "Move the sound from the right hand side to the left hand side, and mark the right hand side as
 * unloaded."
 *
 * The first thing we do is move the sound from the right hand side to the left hand side. This is
 * done by calling the move assignment operator of the `std::unique_ptr` class. This will move the
 * sound from the right hand side to the left hand side, and set the right hand side to null
 *
 * @return A reference to the object that called the function.
 */
SoundManager& SoundManager::operator=(SoundManager&& rhs) noexcept
{
    sound_        = std::move(rhs.sound_);
    rhs.unloaded_ = true;
    return *(this);
}

/**
 * It calls the unload() function
 */
SoundManager::~SoundManager() noexcept
{
    this->unload();
}

/**
 * If the sound is not unloaded, unload it and set the unloaded flag to true.
 */
void SoundManager::unload() noexcept
{
    if (!unloaded_) {
        UnloadSound(sound_);
        unloaded_ = true;
    }
}

/**
 * PlaySound() is a Windows API function that plays a sound
 */
void SoundManager::play() const noexcept
{
    if (load_) { PlaySound(sound_); }
}

/**
 * It sets the volume of the sound
 *
 * @param value The volume to set the sound to.
 */
void SoundManager::setVolume(float value) noexcept
{
    if (load_) { SetSoundVolume(sound_, value); }
}