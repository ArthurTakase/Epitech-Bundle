/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Clock
*/

#include <Time/Clock.hpp>

/**
 * It initializes the Clock class object and its member variables
 */
Clock::Clock() noexcept
    : end_(std::chrono::high_resolution_clock::now())
    , start_(std::chrono::high_resolution_clock::now())
    , actualTime_(std::chrono::high_resolution_clock::now())
    , lastPing_(std::chrono::high_resolution_clock::now())
{
}

/**
 * It returns the end time of the clock.
 *
 * @return The end_ variable is being returned.
 */
std::chrono::high_resolution_clock::time_point Clock::getEnd() const noexcept
{
    return (end_);
}

/**
 * This function returns the start time of the clock.
 *
 * @return The start_ variable.
 */
std::chrono::high_resolution_clock::time_point Clock::getStart() const noexcept
{
    return (start_);
}

/**
 * It returns the actual time.
 *
 * @return The actual time.
 */
std::chrono::high_resolution_clock::time_point Clock::getActualTime() const noexcept
{
    return (actualTime_);
}

/**
 * Returns the last ping time.
 *
 * @return A reference to the lastPing_ member variable.
 */
std::chrono::high_resolution_clock::time_point Clock::getLastPing() const noexcept
{
    return (lastPing_);
}

/**
 * Sets the end time of the clock.
 *
 * @param end The end time of the clock.
 */
void Clock::setEnd(std::chrono::high_resolution_clock::time_point end) noexcept
{
    end_ = end;
}

/**
 * Sets the start time of the clock to the given time.
 *
 * @param start The time at which the clock was started.
 */
void Clock::setStart(std::chrono::high_resolution_clock::time_point start) noexcept
{
    start_ = start;
}

/**
 * `void Clock::setActualTime(std::chrono::high_resolution_clock::time_point
 * actualTime) noexcept`
 *
 * `setActualTime` is a function that takes a
 * `std::chrono::high_resolution_clock::time_point` and returns nothing
 *
 * @param actualTime The actual time of the clock.
 */
void Clock::setActualTime(std::chrono::high_resolution_clock::time_point actualTime) noexcept
{
    actualTime_ = actualTime;
}

/**
 * It sets the lastPing_ member variable to the value of the lastPing parameter
 *
 * @param lastPing The last time the client pinged the server.
 */
void Clock::setLastPing(std::chrono::high_resolution_clock::time_point lastPing) noexcept
{
    lastPing_ = lastPing;
}