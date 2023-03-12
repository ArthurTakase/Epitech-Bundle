/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Lib.cpp
*/

#pragma once

#include <Lib/Window.hpp>

/**
 * @brief This class is used to create a library.
 *
 */
class Lib
{
  public:
    Lib() noexcept                 = default;
    ~Lib() noexcept                = default;
    Lib(const Lib& other) noexcept = delete;
    Lib(Lib&& other) noexcept      = delete;

    Lib& operator=(const Lib& rhs) noexcept = delete;
    Lib& operator=(Lib&& rhs) noexcept      = delete;

    Window& getWindow();

  private:
    Window window_;
};