/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Sound
*/

#pragma once

#include <SFML/Audio.hpp>
#include <string_view>

/**
 * @brief This class is used to create and encapsulate a Sf::SoundBuffer.
 *
 */
class Buffer
{
    friend class Sound;

  public:
    Buffer(const std::string_view& path);
    Buffer(const Buffer& other) noexcept = delete;
    Buffer(Buffer&& other) noexcept      = default;
    ~Buffer() noexcept                   = default;

    Buffer& operator=(const Buffer& rhs) noexcept = delete;
    Buffer& operator=(Buffer&& rhs) noexcept      = default;

  protected:
  private:
    sf::SoundBuffer buffer_;
};

/**
 * @brief This class is used to create and encapsulate a Sf::Sound.
 *
 */
class Sound
{
  public:
    Sound() noexcept = default;
    explicit Sound(const Buffer& buffer);
    Sound(const Sound& other) noexcept = delete;
    Sound(Sound&& other) noexcept      = default;
    ~Sound() noexcept                  = default;

    Sound& operator=(const Sound& rhs) noexcept = delete;
    Sound& operator=(Sound&& rhs) noexcept      = default;

    void        play() noexcept;
    void        pause() noexcept;
    void        stop() noexcept;
    void        setVolume(float volume) noexcept;
    std::string getPath() const noexcept;

  protected:
  private:
    sf::Sound sound_;
};