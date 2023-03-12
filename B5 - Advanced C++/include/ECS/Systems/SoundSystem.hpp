/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SoundSystem
*/

#pragma once

#include <ECS/Components/SoundComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Lib/SoundManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief A system that will handle and update all SoundComponents contained inside our entities.
 */
class SoundSystem
{
  public:
    SoundSystem(EntityManager* manager) noexcept;
    SoundSystem(const SoundSystem& other) noexcept = delete;
    SoundSystem(SoundSystem&& other) noexcept      = delete;
    ~SoundSystem() noexcept                        = default;

    SoundSystem& operator=(const SoundSystem& rhs) noexcept = delete;
    SoundSystem& operator=(SoundSystem&& rhs) noexcept      = delete;

    void run();
    void setSoundManager(SoundManager* soundManager) noexcept;

  protected:
  private:
    EntityIterator<SoundComponent> it_;
    EntityManager*                 entityManager_;
    SoundManager*                  soundManager_;
};