/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include <ECS/Components/HitboxComponent.hpp>

/**
 * It's a constructor for the HitboxComponent class
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
HitboxComponent::HitboxComponent(size_t width, size_t height)
    : width_(width)
    , height_(height)
{
}

/**
 * It returns the width of the hitbox
 *
 * @return The width of the hitbox.
 */
size_t HitboxComponent::getWidth() const noexcept
{
    return width_;
}

/**
 * It returns the height of the hitbox
 *
 * @return The height of the hitbox.
 */
size_t HitboxComponent::getHeight() const noexcept
{
    return height_;
}

/**
 * It sets the width of the hitbox
 *
 * @param width The width of the hitbox.
 */
void HitboxComponent::setWidth(size_t width) noexcept
{
    width_ = width;
}

/**
 * It sets the height of the hitbox
 *
 * @param height The height of the hitbox.
 */
void HitboxComponent::setHeight(size_t height) noexcept
{
    height_ = height;
}

/**
 * It sets the width and height of the hitbox
 *
 * @param width The width of the hitbox.
 * @param height The height of the hitbox.
 */
void HitboxComponent::setSize(size_t width, size_t height) noexcept
{
    width_  = width;
    height_ = height;
}

/**
 * It sets the onCollision_ function object to the function object passed in
 *
 * @param onCollision A function that takes two entities as parameters and returns
 * void.
 */
void HitboxComponent::setOnCollision(std::function<void(Entity*, Entity*)> onCollision) noexcept
{
    onCollision_ = onCollision;
}

/**
 * It calls the function pointer `onCollision_` with the given arguments
 *
 * @param entity The entity that collided with this entity.
 * @param me The entity that has this component.
 */
void HitboxComponent::onCollision(Entity* entity, Entity* me) const noexcept
{
    if (onCollision_) onCollision_(entity, me);
}

/**
 * This function sets the width and height of the hitbox to the width and height of
 * the hitbox multiplied by the x and y values passed in.
 *
 * @param x The x position of the hitbox
 * @param y The y position of the hitbox.
 */
void HitboxComponent::setScale(float x, float y) noexcept
{
    width_  = width_ * x;
    height_ = height_ * y;
}