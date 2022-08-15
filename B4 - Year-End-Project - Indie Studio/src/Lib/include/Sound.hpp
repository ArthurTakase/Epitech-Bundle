/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sound
*/

#pragma once
#include <string>

#include "raylib.h"

class SoundManager
{
  public:
    explicit SoundManager(const std::string& path) noexcept;
    SoundManager(const SoundManager& other) noexcept = delete;
    SoundManager(SoundManager&& other) noexcept;
    ~SoundManager() noexcept;

    SoundManager& operator=(const SoundManager& rhs) noexcept = delete;
    SoundManager& operator                                    =(SoundManager&& rhs) noexcept;

    void unload() noexcept;
    void play() const noexcept;
    void setVolume(float volume) noexcept;

  protected:
  private:
    Sound sound_;
    bool  unloaded_ = false;
    bool  load_     = false;
};