/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Music
*/

#pragma once
#include <string>

#include "raylib.h"

class MusicManager
{
  public:
    MusicManager(const std::string& path) noexcept;
    MusicManager(const MusicManager& other) noexcept = delete;
    MusicManager(MusicManager&& other) noexcept;
    ~MusicManager() noexcept;

    MusicManager& operator=(const MusicManager& rhs) noexcept = delete;
    MusicManager& operator                                    =(MusicManager&& rhs) noexcept;

    void play() noexcept;
    void update() const noexcept;
    void setVolume(float volume) noexcept;
    void stop() noexcept;
    bool isPlaying() const noexcept;
    void unload() noexcept;

  protected:
  private:
    Music music_;
    bool  isPlaying_ = false;
    bool  unloaded_  = false;
};