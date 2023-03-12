/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#include <ECS/Components/MusicComponent.hpp>

/**
 * It takes a string_view, and uses it to construct a music object.
 *
 * @param path The path to the music file.
 */
MusicComponent::MusicComponent(const std::string_view& path)
    : music_(path.data())
{
}

/**
 * `getIsPlayed` returns the value of the private member variable `isPlayed_`
 *
 * @return isPlayed_
 */
bool MusicComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

/**
 * It sets the value of the isPlayed_ member variable to the value of the value
 * parameter
 *
 * @param value The value to set the playing state to.
 */
void MusicComponent::setPlaying(bool value) noexcept
{
    isPlayed_ = value;
}

/**
 * It plays the music if it's not already playing
 */
void MusicComponent::play() noexcept
{
    if (isPlayed_) {
        music_.play();
        isPlayed_ = false;
    }
}

/**
 * It stops the music
 */
void MusicComponent::stop() noexcept
{
    music_.stop();
}

/**
 * It returns the value of the private member variable `music_`
 *
 * @return a Music class object
 */
Music& MusicComponent::getMusic() noexcept
{
    return music_;
}