/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Timer.cpp
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>

/**
 * @brief This class is used to create, modify and encapsulate a Sf::Clock.
 *
 */
class Timer
{
  public:
    Timer() noexcept;
    Timer(float limit) noexcept;
    ~Timer() noexcept                  = default;
    Timer(const Timer& other) noexcept = default;
    Timer(Timer&& other) noexcept      = default;

    Timer& operator=(const Timer& rhs) noexcept = default;
    Timer& operator=(Timer&& rhs) noexcept      = default;

    void  start() noexcept;
    void  stop() noexcept;
    void  reset() noexcept;
    bool  isOver() noexcept;
    float getElapsedTime() const noexcept;
    void  setLimit(float limit) noexcept;
    float getLimit() const noexcept;

  private:
    sf::Clock clock_;
    float     limit_;
    bool      active_;
};