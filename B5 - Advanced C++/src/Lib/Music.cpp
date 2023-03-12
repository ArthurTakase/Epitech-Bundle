/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Music
*/

#include <Error/Error.hpp>
#include <Lib/Music.hpp>

/**
 * It creates a new music object from a file path
 *
 * @param path The path to the music file.
 */
Music::Music(const std::string& path)
    : music_(std::make_unique<sf::Music>())
{
    if (!music_->openFromFile(path)) throw Error("Error: Could not load music from file: " + path);

    music_->setLoop(true);
}

/**
 * Play the music
 */
void Music::play() noexcept
{
    music_->play();
}

/**
 * Pause the music
 */
void Music::pause() noexcept
{
    music_->pause();
}

/**
 * Stop the music
 */
void Music::stop() noexcept
{
    music_->stop();
}

/**
 * Sets the volume of the music
 *
 * @param value The volume of the music, in the range 0.0 to 100.0.
 */
void Music::setVolume(float value) noexcept
{
    music_->setVolume(value);
}

/**
 * Sets the looping state of the music
 *
 * @param value The new value for the looping flag.
 */
void Music::setLoop(bool value) noexcept
{
    music_->setLoop(value);
}

/**
 * Sets the musicPath of the music
 *
 * @param value The new value for the musicPath.
 */
void Music::setPath(std::string path) noexcept
{
    musicPath_ = path;
}

/**
 * Gets the musicPath of the music
 */
std::string Music::getPath() const noexcept
{
    return musicPath_;
}
