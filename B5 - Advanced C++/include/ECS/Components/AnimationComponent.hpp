/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AnimationComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Lib/Sprite.hpp>
#include <Lib/Timer.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component assigned to drawable entities.
 */
class AnimationComponent : public IComponent
{
  public:
    AnimationComponent(int limit, float timer_limit);
    ~AnimationComponent() noexcept                               = default;
    AnimationComponent(const AnimationComponent& other) noexcept = default;
    AnimationComponent(AnimationComponent&& other) noexcept      = default;

    AnimationComponent& operator=(const AnimationComponent& rhs) noexcept = default;
    AnimationComponent& operator=(AnimationComponent&& rhs) noexcept      = default;

    int    getLimit() const noexcept;
    void   setLimit(int limit) noexcept;
    Timer& getTimer() noexcept;

  private:
    int   limit;
    Timer timer_;
};