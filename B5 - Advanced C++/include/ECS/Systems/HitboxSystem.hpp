/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#pragma once

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief System used to check if an entity is colliding with another
 */
class HitboxSystem
{
  public:
    HitboxSystem(EntityManager* manager) noexcept;
    ~HitboxSystem() noexcept                         = default;
    HitboxSystem(const HitboxSystem& other) noexcept = default;
    HitboxSystem(HitboxSystem&& other) noexcept      = delete;

    HitboxSystem& operator=(const HitboxSystem& rhs) noexcept = delete;
    HitboxSystem& operator=(HitboxSystem&& rhs) noexcept      = delete;

    void run();
    void checkCollision(Entity* entity) const;

  private:
    EntityIterator<TransformComponent, HitboxComponent> it_;
    EntityManager*                                      manager_;
};