/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MouvementSystem.cpp
*/

#pragma once

#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief A system that will update the position of the entities that have a TransformComponent and a
 * MouvementComponent.
 */
class MouvementSystem
{
  public:
    MouvementSystem(EntityManager* manager) noexcept;
    ~MouvementSystem() noexcept                            = default;
    MouvementSystem(const MouvementSystem& other) noexcept = delete;
    MouvementSystem(MouvementSystem&& other) noexcept      = delete;

    MouvementSystem& operator=(const MouvementSystem& rhs) noexcept = delete;
    MouvementSystem& operator=(MouvementSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<TransformComponent, MouvementComponent> it_;
    EntityManager*                                         manager_;
};
