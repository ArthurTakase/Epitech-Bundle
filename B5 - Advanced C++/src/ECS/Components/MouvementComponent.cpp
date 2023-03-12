/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#include <ECS/Components/MouvementComponent.hpp>

/**
 * It's a constructor that takes three parameters and assigns them to the three member variables
 *
 * @param dirX The direction of the movement on the X axis. (-1, 0 or 1)
 * @param dirY The direction of the movement on the Y axis. (-1, 0 or 1)
 * @param speed the speed of the entity
 */
MouvementComponent::MouvementComponent(int dirX, int dirY, float speed) noexcept
    : dirX_(dirX)
    , dirY_(dirY)
    , speed_(speed)
{
}

/**
 * It returns the value of the private member _dirX
 *
 * @return The direction of the x axis.
 */
int MouvementComponent::getDirX() const noexcept
{
    return dirX_;
}

/**
 * It returns the value of the private attribute _dirY
 *
 * @return The direction of the Y axis.
 */
int MouvementComponent::getDirY() const noexcept
{
    return dirY_;
}

/**
 * It returns the speed of the entity
 *
 * @return The speed of the object.
 */
float MouvementComponent::getSpeed() const noexcept
{
    return speed_;
}

/**
 * It sets the direction of the entity on the X axis
 *
 * @param x The x-coordinate of the direction vector. (-1, 0 or 1)
 */
void MouvementComponent::setDirX(int x) noexcept
{
    dirX_ = x;
}

/**
 * It sets the direction of the Y axis
 *
 * @param y The y-axis direction of the movement. (-1, 0 or 1)
 */
void MouvementComponent::setDirY(int y) noexcept
{
    dirY_ = y;
}

/**
 * It sets the speed of the entity
 *
 * @param speed The speed of the entity.
 */
void MouvementComponent::setSpeed(float speed) noexcept
{
    speed_ = speed;
}

/**
 * It sets the direction of the entity
 *
 * @param x The x-coordinate of the direction vector.
 * @param y The y-coordinate of the direction vector.
 */
void MouvementComponent::setDir(int x, int y) noexcept
{
    dirX_ = x;
    dirY_ = y;
}