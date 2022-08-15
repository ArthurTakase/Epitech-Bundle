/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Timer
*/

#include "Timer.hpp"

#include "DeltaTime.hpp"

/**
 * It initializes the life_time_ and default_ variables to the time parameter
 *
 * @param time The time in seconds that the timer will run for.
 */
Timer::Timer(float time) noexcept
    : life_time_(time)
    , default_(time)
{
}

/**
 * If the timer's life time is greater than 0, subtract the delta time from the
 * timer's life time
 */
void Timer::updateTimer() noexcept
{
    if (life_time_ > 0) life_time_ -= DeltaTime::getDeltaTime();
}

/**
 * This function returns true if the timer is done, false otherwise.
 *
 * @return A boolean value.
 */
bool Timer::isTimerDone() const noexcept
{
    return (life_time_ <= 0);
}

/**
 * This function returns the life time of the timer
 *
 * @return The life_time_ variable is being returned.
 */
float Timer::getTime() const noexcept
{
    return (life_time_);
}

/**
 * Sets the life time of the timer.
 *
 * @param time The time in seconds that the timer will run for.
 */
void Timer::setLifeTime(float time) noexcept
{
    life_time_ = time;
}

/**
 * Resets the timer to the default value.
 */
void Timer::resetTimer() noexcept
{
    life_time_ = default_;
}
