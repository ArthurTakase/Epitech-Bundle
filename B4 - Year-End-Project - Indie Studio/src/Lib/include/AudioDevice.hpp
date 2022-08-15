/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AudioDevice
*/

#pragma once
#include "Scene.hpp"

class AudioDevice
{
  public:
    AudioDevice() noexcept                         = delete;
    AudioDevice(const AudioDevice& other) noexcept = delete;
    AudioDevice(AudioDevice&& other) noexcept      = delete;
    ~AudioDevice() noexcept                        = delete;

    AudioDevice& operator=(const AudioDevice& rhs) noexcept = delete;
    AudioDevice& operator=(AudioDevice&& rhs) noexcept = delete;

    static void initialize() noexcept;
    static void update(const Scene& scene) noexcept;
    static void close() noexcept;
    static void setMusic(float value) noexcept;

  protected:
  private:
};
