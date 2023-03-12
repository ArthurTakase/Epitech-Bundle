/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundManager
*/

#pragma once
#include <Lib/Sound.hpp>
#include <string_view>
#include <vector>

/**
 * @brief This class is used to create and encapsulate a vector of Sf::SoundBuffer.
 *
 */
class SoundManager
{
  public:
    SoundManager() noexcept                          = default;
    SoundManager(const SoundManager& other) noexcept = default;
    SoundManager(SoundManager&& other) noexcept      = default;
    ~SoundManager() noexcept                         = default;

    SoundManager& operator=(const SoundManager& rhs) noexcept = default;
    SoundManager& operator=(SoundManager&& rhs) noexcept      = default;

    void    addSoundBuffer(const std::string_view& path) noexcept;
    Buffer& getBufferFromPath(const std::string_view& path);

  protected:
  private:
    std::vector<Buffer>           buffers_;
    std::vector<std::string_view> buffersPaths_;

    unsigned int getBufferIdFromPath(const std::string_view& path) const;
};