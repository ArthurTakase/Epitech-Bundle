/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AnimationSystem.cpp
*/

#pragma once

#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief System used to check if an entity is colliding with another
 */
class AnimationSystem
{
  public:
    AnimationSystem(EntityManager* manager) noexcept;
    ~AnimationSystem() noexcept                            = default;
    AnimationSystem(const AnimationSystem& other) noexcept = default;
    AnimationSystem(AnimationSystem&& other) noexcept      = delete;

    AnimationSystem& operator=(const AnimationSystem& rhs) noexcept = delete;
    AnimationSystem& operator=(AnimationSystem&& rhs) noexcept      = delete;

    void run();

  private:
    EntityIterator<DrawableComponent, AnimationComponent> it_;
    EntityManager*                                        manager_;
};