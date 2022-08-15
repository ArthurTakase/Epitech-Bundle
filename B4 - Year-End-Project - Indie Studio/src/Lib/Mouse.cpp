/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Mouse
*/

#include "Mouse.hpp"

#include "raylib.h"

/**
 * It returns the mouse position
 *
 * @return A Vector2D object.
 */
Vector2D MouseHandler::getMousePosition() const noexcept
{
    return (mouse_);
}

/**
 * It updates the mouse's position
 */
void MouseHandler::update() noexcept
{
    Vector2 mouse = GetMousePosition();
    mouse_.x      = mouse.x;
    mouse_.y      = mouse.y;
}

/**
 * If the mouse is within the bounds of the rectangle, return true
 *
 * @param bounds The rectangle to check collision with
 *
 * @return A boolean value.
 */
bool MouseHandler::isColliding(const RectangleManager& bounds) const noexcept
{
    Rectangle rectangle = { bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight() };
    Vector2   mouse     = { mouse_.x, mouse_.y };

    return (CheckCollisionPointRec(mouse, rectangle));
}

/**
 * If the left mouse button is down, return true, otherwise return false.
 *
 * @return A boolean value.
 */
bool MouseHandler::isClicking() const noexcept
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) return (true);
    return (false);
}

/**
 * This function returns true if the left mouse button is released
 *
 * @return A boolean value.
 */
bool MouseHandler::isClicked() const noexcept
{
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) return (true);
    return (false);
}
