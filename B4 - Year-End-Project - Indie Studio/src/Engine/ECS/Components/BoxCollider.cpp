/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** BoxCollider
*/

#include "BoxCollider.hpp"

#include "CollisionChecker.hpp"

/**
 * It's a constructor that takes a position, size, and a boolean value that
 * determines whether the box is solid or not
 *
 * @param newPos The position of the box collider.
 * @param newSize The size of the box collider.
 * @param solid If true, the box collider will be solid. If false, it will be a
 * trigger.
 */
BoxCollider::BoxCollider(const Vector3D& newPos, const Vector3D& newSize, bool solid) noexcept
    : position_(newPos)
    , size_(newSize)
    , is_solid_(solid)
{
}
/**
 * If the two boxes are not
 * colliding, return false, otherwise return true
 *
 * @param pos The position of the box collider.
 * @param size The size of the box collider.
 * @param otherPos The position of the other box collider.
 * @param otherSize The size of the other box collider.
 *
 * @return A boolean value.
 */

bool BoxCollider::checkCollision(const Vector3D& pos,
    const Vector3D&                              size,
    const Vector3D&                              otherPos,
    const Vector3D&                              otherSize) const noexcept
{
    return CollisionChecker::check(pos, size, otherPos, otherSize);
}

/**
 * This function returns the position of the box collider.
 *
 * @return The position of the box collider.
 */
Vector3D BoxCollider::getPosition() const noexcept
{
    return (position_);
}

/**
 * Sets the position of the box collider.
 *
 * @param pos The position of the box collider.
 */
void BoxCollider::setPosition(const Vector3D& pos) noexcept
{
    position_ = pos;
}

/**
 * It sets the z position of the box collider
 *
 * @param pos The new position of the box collider.
 */
void BoxCollider::setPositionZ(int pos) noexcept
{
    position_.z = pos;
}

/**
 * It sets the y position of the box collider
 *
 * @param pos The new position of the box collider.
 */
void BoxCollider::setPositionY(int pos) noexcept
{
    position_.y = pos;
}

/**
 * It updates the position of the box collider.
 *
 * @param newPos The new position of the box collider.
 */
void BoxCollider::update(const Vector3D& newPos) noexcept
{
    position_ = newPos;
}

/**
 * If the two boxes are colliding, return true, otherwise return false
 *
 * @param other The other box collider to check collision with.
 *
 * @return A boolean value.
 */
bool BoxCollider::isColliding(const BoxCollider& other) const noexcept
{
    return (checkCollision(position_, size_, other.getPosition(), other.getSize()));
}

/**
 * If the position of the current box collider is less than the position of the
 * other box collider plus the size of the other box collider, and the position of
 * the current box collider plus the size of the current box collider is greater
 * than the position of the other box collider, then return true
 *
 * @param otherHit The other hitbox to check collision with.
 * @param otherPos The position of the other hitbox.
 *
 * @return A boolean value.
 */
bool BoxCollider::isColliding(const BoxCollider& otherHit, const Vector3D& otherPos) const noexcept
{
    return (checkCollision(position_, size_, otherPos, otherHit.getSize()));
}

/**
 * It returns the type of the component.
 *
 * @return The type of the component.
 */
ComponentType BoxCollider::getComponentType() const noexcept
{
    return (TYPE);
}

/**
 * This function returns the size of the box collider.
 *
 * @return The size of the box collider.
 */
Vector3D BoxCollider::getSize() const noexcept
{
    return (size_);
}

/**
 * It sets the value of the is_solid_ member variable to the value of the value
 * parameter
 *
 * @param value The new value for the is_solid_ variable.
 */
void BoxCollider::setIsSolid(bool value) noexcept
{
    is_solid_ = value;
}

/**
 * This function returns the value of the private member variable is_solid_.
 *
 * @return The is_solid_ variable is being returned.
 */
bool BoxCollider::getIsSolid() const noexcept
{
    return (is_solid_);
}

/**
 * Adds a value to the x position of the box collider
 *
 * @param value The value to add to the x position.
 */
void BoxCollider::addX(float value) noexcept
{
    position_.x += value;
}

/**
 * It adds the value to the y position of the box collider
 *
 * @param value The value to add to the y position.
 */
void BoxCollider::addY(float value) noexcept
{
    position_.y += value;
}

/**
 * Adds the given value to the z-coordinate of the position of the box collider.
 *
 * @param value The value to add to the position.
 */
void BoxCollider::addZ(float value) noexcept
{
    position_.z += value;
}
