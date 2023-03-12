/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicComponent
*/

#pragma once
#include <ECS/Components/IComponent.hpp>
#include <Lib/Music.hpp>
#include <memory>

/**
 * @brief Component used to set the music associated to an entity
 */
class MusicComponent : public IComponent
{
  public:
    MusicComponent(const std::string_view& path);
    MusicComponent(const int musicId);
    MusicComponent(const MusicComponent& other) noexcept = delete;
    MusicComponent(MusicComponent&& other) noexcept      = default;
    ~MusicComponent() noexcept                           = default;

    MusicComponent& operator=(const MusicComponent& rhs) noexcept = delete;
    MusicComponent& operator=(MusicComponent&& rhs) noexcept      = default;

    bool   getIsPlayed() const noexcept;
    Music& getMusic() noexcept;
    void   setPlaying(bool value) noexcept;
    void   play() noexcept;
    void   stop() noexcept;

  protected:
  private:
    Music music_;
    bool  isPlayed_ = true;
};
