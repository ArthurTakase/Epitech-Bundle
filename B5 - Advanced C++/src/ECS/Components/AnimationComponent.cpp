/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** AnimationComponent
*/

#include <ECS/Components/AnimationComponent.hpp>

/**
 * It's a constructor that takes in two parameters, limit and timer_limit, and sets
 * the limit and timer_limit variables to the values of the parameters.
 *
 * @param limit The number of frames in the animation.
 * @param timer_limit The time between each frame.
 */
AnimationComponent::AnimationComponent(int limit, float timer_limit)
    : limit(limit)
    , timer_(timer_limit)
{
}

/**
 * It returns the limit of the animation.
 *
 * @return The limit variable is being returned.
 */
int AnimationComponent::getLimit() const noexcept
{
    return limit;
}

/**
 * It sets the limit of the animation
 *
 * @param limit The number of times the animation will play.
 */
void AnimationComponent::setLimit(int limit) noexcept
{
    this->limit = limit;
}

/**
 * It returns a reference to the timer_ member variable
 *
 * @return A reference to the timer_ member variable.
 */
Timer& AnimationComponent::getTimer() noexcept
{
    return timer_;
}