/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DestroyableSystem.cpp
*/

#pragma once

#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief System used to check if an entity is colliding with another
 */
class DestroyableSystem
{
  public:
    DestroyableSystem(EntityManager* manager) noexcept;
    ~DestroyableSystem() noexcept                              = default;
    DestroyableSystem(const DestroyableSystem& other) noexcept = default;
    DestroyableSystem(DestroyableSystem&& other) noexcept      = delete;

    DestroyableSystem& operator=(const DestroyableSystem& rhs) noexcept = delete;
    DestroyableSystem& operator=(DestroyableSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<DestroyableComponent> it_;
    EntityManager*                       manager_;
};