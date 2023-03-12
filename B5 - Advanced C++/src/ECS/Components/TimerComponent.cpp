/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TimerComponent
*/

#include <ECS/Components/TimerComponent.hpp>

/**
 * It's a constructor that takes a float and sets the timer_ member variable to
 * that float.
 *
 * @param time The time in seconds that the timer will count down from.
 */
TimerComponent::TimerComponent(float time)
    : timer_(time)
{
}

/**
 * It returns a reference to the timer object
 *
 * @return A reference to the timer_ member variable.
 */
Timer& TimerComponent::getTimer() noexcept
{
    return timer_;
}