/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundComponent
*/

#pragma once
#include <ECS/Components/IComponent.hpp>
#include <Lib/Sound.hpp>

/**
 * @brief Component used to set a sound associated to an entity
 */
class SoundComponent : public IComponent
{
  public:
    SoundComponent() noexcept = default;
    explicit SoundComponent(const Buffer& buffer);
    SoundComponent(const SoundComponent& other) noexcept = delete;
    SoundComponent(SoundComponent&& other) noexcept      = default;
    ~SoundComponent() noexcept                           = default;

    SoundComponent& operator=(const SoundComponent& rhs) noexcept = delete;
    SoundComponent& operator=(SoundComponent&& rhs) noexcept      = default;

    Sound& getSound() noexcept;
    bool   getIsPlayed() const noexcept;
    void   setPlayed(bool value) noexcept;
    void   play() noexcept;

  protected:
  private:
    Sound sound_;
    bool  isPlayed_ = false;
};