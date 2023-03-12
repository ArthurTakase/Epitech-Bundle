/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Clock
*/

#pragma once
#include <chrono>

/**
 * @brief a class that will be used to handle ping management in our game between a client and the server.
 *
 */
class Clock
{
  public:
    Clock() noexcept;
    Clock(const Clock& other) noexcept = default;
    Clock(Clock&& other) noexcept      = default;
    ~Clock() noexcept                  = default;

    Clock& operator=(const Clock& rhs) noexcept = default;
    Clock& operator=(Clock&& rhs) noexcept      = default;

    // getters
    std::chrono::high_resolution_clock::time_point getEnd() const noexcept;
    std::chrono::high_resolution_clock::time_point getStart() const noexcept;
    std::chrono::high_resolution_clock::time_point getActualTime() const noexcept;
    std::chrono::high_resolution_clock::time_point getLastPing() const noexcept;

    // setters
    void setEnd(std::chrono::high_resolution_clock::time_point end) noexcept;
    void setStart(std::chrono::high_resolution_clock::time_point start) noexcept;
    void setActualTime(std::chrono::high_resolution_clock::time_point actualTime) noexcept;
    void setLastPing(std::chrono::high_resolution_clock::time_point actualTime) noexcept;

  protected:
  private:
    std::chrono::high_resolution_clock::time_point end_;
    std::chrono::high_resolution_clock::time_point start_;
    std::chrono::high_resolution_clock::time_point actualTime_;
    std::chrono::high_resolution_clock::time_point lastPing_;
};