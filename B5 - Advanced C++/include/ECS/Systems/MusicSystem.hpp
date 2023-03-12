/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicSystem
*/

#pragma once

#include <ECS/Components/MusicComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief A system that will handle and update all MusicComponents contained inside our entities.
 */
class MusicSystem
{
  public:
    MusicSystem(EntityManager* manager) noexcept;
    MusicSystem(const MusicSystem& other) noexcept = delete;
    MusicSystem(MusicSystem&& other) noexcept      = delete;
    ~MusicSystem() noexcept                        = default;

    MusicSystem& operator=(const MusicSystem& rhs) noexcept = delete;
    MusicSystem& operator=(MusicSystem&& rhs) noexcept      = delete;

    void run();

  protected:
  private:
    EntityIterator<MusicComponent> it_;
    EntityManager*                 manager_;
};