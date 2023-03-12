/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** BehaviorSystem.cpp
*/

#pragma once

#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief System used to check if an entity is colliding with another
 */
class BehaviorSystem
{
  public:
    BehaviorSystem(EntityManager* manager) noexcept;
    ~BehaviorSystem() noexcept                           = default;
    BehaviorSystem(const BehaviorSystem& other) noexcept = default;
    BehaviorSystem(BehaviorSystem&& other) noexcept      = delete;

    BehaviorSystem& operator=(const BehaviorSystem& rhs) noexcept = delete;
    BehaviorSystem& operator=(BehaviorSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<BehaviorComponent> it_;
    EntityManager*                    manager_;
};