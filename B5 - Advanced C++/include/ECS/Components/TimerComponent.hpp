/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TimerComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <Lib/Timer.hpp>

/**
 * @brief Component used to store the position of an entity
 */
class TimerComponent : public IComponent
{
  public:
    TimerComponent(float time);
    ~TimerComponent() noexcept                           = default;
    TimerComponent(const TimerComponent& other) noexcept = default;
    TimerComponent(TimerComponent&& other) noexcept      = default;

    TimerComponent& operator=(const TimerComponent& rhs) noexcept = default;
    TimerComponent& operator=(TimerComponent&& rhs) noexcept      = default;

    Timer& getTimer() noexcept;

  private:
    Timer timer_;
};
