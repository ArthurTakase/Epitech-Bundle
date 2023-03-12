/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundComponent
*/

#include <ECS/Components/SoundComponent.hpp>
#include <Lib/Sound.hpp>

/**
 * It creates a sound component with the given path
 *
 * @param path The path to the sound file.
 */
SoundComponent::SoundComponent(const Buffer& buffer)
    : sound_(buffer)
{
}

/**
 * It returns the sound_ member variable
 *
 * @return A reference to the sound_ member variable.
 */
Sound& SoundComponent::getSound() noexcept
{
    return sound_;
}

/**
 * A function used to determine whether or not the sound is played
 *
 * @return a boolean value
 */
bool SoundComponent::getIsPlayed() const noexcept
{
    return isPlayed_;
}

/**
 * This function sets the value of the isPlayed_ member variable
 *
 * @param value The value to set the played state to.
 */
void SoundComponent::setPlayed(bool value) noexcept
{
    isPlayed_ = value;
}

/**
 * If the sound has to be played, plays it
 */
void SoundComponent::play() noexcept
{
    if (isPlayed_) {
        sound_.play();
        isPlayed_ = false;
    }
}
