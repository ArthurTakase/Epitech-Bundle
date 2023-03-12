/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Timer.cpp
*/

#include <Lib/Timer.hpp>
#include <iostream>

/**
 * It initializes the limit_ and active_ members to 0 and false, respectively
 */
Timer::Timer() noexcept
    : limit_(0)
    , active_(false)
{
}

/**
 * It initializes the limit_ and active_ member variables
 *
 * @param limit The time limit for the timer.
 */
Timer::Timer(float limit) noexcept
    : limit_(limit)
    , active_(true)
{
}

/**
 * It sets the active_ member variable to true
 */
void Timer::start() noexcept
{
    active_ = true;
}

/**
 * It stops the timer.
 */
void Timer::stop() noexcept
{
    active_ = false;
}

/**
 * Resets the timer to zero.
 */
void Timer::reset() noexcept
{
    clock_.restart();
}

/**
 * If the timer is active and the elapsed time is greater than the limit, restart
 * the clock and return true. Otherwise, return false
 *
 * @return A boolean value.
 */
bool Timer::isOver() noexcept
{
    if (!active_) { return false; }

    if (getElapsedTime() >= limit_) {
        clock_.restart();
        return true;
    }
    return false;
}

/**
 * It returns the time elapsed since the last call to reset()
 *
 * @return The time elapsed since the clock was started.
 */
float Timer::getElapsedTime() const noexcept
{
    sf::Time time = clock_.getElapsedTime();
    return time.asSeconds();
}

/**
 * It sets the limit of the timer
 *
 * @param limit The time limit for the timer.
 */
void Timer::setLimit(float limit) noexcept
{
    limit_ = limit;
}

/**
 * `getLimit` returns the limit of the timer
 *
 * @return The limit_ variable.
 */
float Timer::getLimit() const noexcept
{
    return limit_;
}