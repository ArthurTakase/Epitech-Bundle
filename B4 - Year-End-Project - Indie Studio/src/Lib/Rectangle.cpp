/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

/**
 * It initializes the member variables of the class
 *
 * @param x The x coordinate of the rectangle.
 * @param y The y-coordinate of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 */
RectangleManager::RectangleManager(float x, float y, float width, float height) noexcept
    : x_(x)
    , y_(y)
    , width_(width)
    , height_(height)
{
}

/**
 * This function returns the value of the private member variable x_, which is a float.
 *
 * @return The x coordinate of the rectangle.
 */
float RectangleManager::getX() const noexcept
{
    return (x_);
}

/**
 * This function returns the y coordinate of the rectangle.
 *
 * @return The y coordinate of the rectangle.
 */
float RectangleManager::getY() const noexcept
{
    return (y_);
}

/**
 * This function returns the width of the rectangle.
 *
 * @return The width of the rectangle.
 */
float RectangleManager::getWidth() const noexcept
{
    return (width_);
}

/**
 * `getHeight()` returns the height of the rectangle.
 *
 * @return The height of the rectangle.
 */
float RectangleManager::getHeight() const noexcept
{
    return (height_);
}

/**
 * Sets the position of the rectangle.
 *
 * @param x The x position of the rectangle.
 * @param y The y coordinate of the rectangle.
 */
void RectangleManager::setPos(float x, float y) noexcept
{
    x_ = x;
    y_ = y;
}

/**
 * `setWidth` sets the width of the rectangle.
 *
 * @param width The width of the rectangle.
 */
void RectangleManager::setWidth(float width) noexcept
{
    width_ = width;
}

/**
 * `void RectangleManager::setHeight(float height) noexcept`
 *
 * This function is a member of the `RectangleManager` class. It's a `void` function, meaning it
 * doesn't return anything. It's called `setHeight` and it takes one parameter, a `float` called
 * `height`. It's marked `noexcept` which means it won't throw any exceptions
 *
 * @param height The height of the rectangle.
 */
void RectangleManager::setHeight(float height) noexcept
{
    height_ = height;
}