/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Music
*/

#include "Music.hpp"

/**
 * It loads a music file from the given path and sets the volume to 50%
 *
 * @param path The path to the music file.
 */
MusicManager::MusicManager(const std::string& path) noexcept
    : music_(LoadMusicStream(path.c_str()))
{
    setVolume(0.5f);
}

/**
 * "Move the other object's music_ into this object's music_, and set the other object's unloaded_
 * to true."
 *
 * The first line of the function is the function declaration. It's a move constructor, so it takes
 * a MusicManager&& as a parameter. The && is a reference to a reference, which is a rvalue
 * reference. A rvalue reference is a reference to a temporary object
 *
 * @param other The other MusicManager object that we're moving from.
 */
MusicManager::MusicManager(MusicManager&& other) noexcept
    : music_(std::move(other.music_))
    , isPlaying_(other.isPlaying_)
{
    setVolume(0.5f);
    other.unloaded_ = true;
}

/**
 * "Move the data from the right hand side to the left hand side, and then set the right hand side
 * to a default state."
 *
 * The first thing we do is move the data from the right hand side to the left hand side. This is
 * done by calling the move assignment operator for the `std::unique_ptr` class. This is the same as
 * calling the move constructor for the `std::unique_ptr` class
 *
 * @return A reference to the object that called the function.
 */
MusicManager& MusicManager::operator=(MusicManager&& rhs) noexcept
{
    music_         = std::move(rhs.music_);
    isPlaying_     = rhs.isPlaying_;
    rhs.isPlaying_ = false;
    rhs.unloaded_  = true;
    return *(this);
}

/**
 * It unloads all the music files
 */
MusicManager::~MusicManager() noexcept
{
    this->unload();
}

/**
 * It unloads the music stream
 */
void MusicManager::unload() noexcept
{
    if (!unloaded_) {
        UnloadMusicStream(music_);
        unloaded_ = true;
    }
}

/**
 * It plays the music
 */
void MusicManager::play() noexcept
{
    isPlaying_ = true;
    PlayMusicStream(music_);
}

/**
 * Update the music stream
 */
void MusicManager::update() const noexcept
{
    UpdateMusicStream(music_);
}

/**
 * It sets the volume of the music
 *
 * @param volume The volume to set the music to.
 */
void MusicManager::setVolume(float volume) noexcept
{
    SetMusicVolume(music_, volume);
}

/**
 * Stop the music stream
 */
void MusicManager::stop() noexcept
{
    isPlaying_ = false;
    StopMusicStream(music_);
}

/**
 * This function returns true if the music is playing, false otherwise.
 *
 * @return isPlaying_
 */
bool MusicManager::isPlaying() const noexcept
{
    return (isPlaying_);
}