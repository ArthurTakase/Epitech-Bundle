/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#include <ECS/Components/TransformComponent.hpp>

/**
 * It's a constructor for the TransformComponent class
 *
 * @param x The x coordinate of the position.
 * @param y The y coordinate of the position.
 */
TransformComponent::TransformComponent(int x, int y)
    : x_(x)
    , y_(y)
{
}

/**
 * This function returns the value of the private member variable _x.
 *
 * @return The value of the private member variable _x.
 */
int TransformComponent::getX() const noexcept
{
    return x_;
}

/**
 * It returns the y coordinate of the position component
 *
 * @return The y position of the entity.
 */
int TransformComponent::getY() const noexcept
{
    return y_;
}

/**
 * Sets the x position of the entity.
 *
 * @param x The x coordinate of the position.
 */
void TransformComponent::setX(int x) noexcept
{
    x_ = x;
}

/**
 * This function sets the y coordinate of the position component.
 *
 * @param y The y coordinate of the position.
 */
void TransformComponent::setY(int y) noexcept
{
    y_ = y;
}

/**
 * Sets the position of the entity to the given x and y coordinates.
 *
 * @param x The x position of the entity.
 * @param y The y coordinate of the position.
 */
void TransformComponent::setPos(int x, int y) noexcept
{
    x_ = x;
    y_ = y;
}
