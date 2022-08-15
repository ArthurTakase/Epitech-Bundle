/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Mouse
*/

#pragma once
#include "Rectangle.hpp"
#include "Vector.hpp"

class MouseHandler
{
  public:
    MouseHandler() noexcept                          = default;
    MouseHandler(const MouseHandler& other) noexcept = default;
    MouseHandler(MouseHandler&& other) noexcept      = default;
    ~MouseHandler() noexcept                         = default;

    MouseHandler& operator=(const MouseHandler& rhs) noexcept = default;
    MouseHandler& operator=(MouseHandler&& rhs) noexcept = default;

    void     update() noexcept;
    bool     isColliding(const RectangleManager& bounds) const noexcept;
    bool     isClicking() const noexcept;
    bool     isClicked() const noexcept;
    Vector2D getMousePosition() const noexcept;

  protected:
  private:
    Vector2D mouse_ = { 0.0f, 0.0f };
};