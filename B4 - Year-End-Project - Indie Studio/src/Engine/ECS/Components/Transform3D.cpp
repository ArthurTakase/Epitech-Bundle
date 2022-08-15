/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Transform3D
*/

#include "Transform3D.hpp"

#include "DeltaTime.hpp"

/**
 * It returns the type of the component.
 *
 * @return The type of the component.
 */
ComponentType Transform3D::getComponentType() const noexcept
{
    return (TYPE);
}

/**
 * This function returns the position of the Transform3D object.
 *
 * @return The position of the object.
 */
Vector3D Transform3D::getPosition() const noexcept
{
    return (position_);
}

/**
 * This function returns the x position of the object.
 *
 * @return The x position of the position_ vector.
 */
float Transform3D::getPositionX() const noexcept
{
    return (position_.x);
}

/**
 * This function returns the y-coordinate of the position vector.
 *
 * @return The y position of the object.
 */
float Transform3D::getPositionY() const noexcept
{
    return (position_.y);
}

/**
 * This function returns the z-coordinate of the position vector.
 *
 * @return The z position of the object.
 */
float Transform3D::getPositionZ() const noexcept
{
    return (position_.z);
}

/**
 * This function returns the scale of the object.
 *
 * @return The scale of the object.
 */
float Transform3D::getScale() const noexcept
{
    return (scale_);
}

/**
 * This function returns the rotation axis of the transform.
 *
 * @return The rotation axis of the transform.
 */
Vector3D Transform3D::getRotationAxis() const noexcept
{
    return (rotation_axis_);
}

/**
 * This function returns the rotation angle of the object.
 *
 * @return The rotation angle of the object.
 */
float Transform3D::getRotationAngle() const noexcept
{
    return (rotation_angle_);
}

/**
 * Sets the position of the transform
 *
 * @param position The position of the object.
 */
void Transform3D::setPosition(const Vector3D& position) noexcept
{
    position_ = position;
}

/**
 * Sets the scale of the transform
 *
 * @param scale The scale of the object.
 */
void Transform3D::setScale(float scale) noexcept
{
    scale_ = scale;
}

/**
 * This function sets the rotation axis of the transform
 *
 * @param rotation_axis The axis of rotation.
 */
void Transform3D::setRotationAxis(const Vector3D& rotation_axis) noexcept
{
    rotation_axis_ = rotation_axis;
}

/**
 * Sets the rotation angle of the transform.
 *
 * @param angle The angle of rotation in degrees.
 */
void Transform3D::setRotationAngle(float angle) noexcept
{
    rotation_angle_ = angle;
}

/**
 * It moves the object in the x direction.
 *
 * @param x The amount to move the object in the x direction.
 */
void Transform3D::moveX(float x) noexcept
{
    position_.x += x * DeltaTime::getDeltaTime();
}

/**
 * It moves the object in the Y direction.
 *
 * @param y The amount to move the object in the y direction.
 */
void Transform3D::moveY(float y) noexcept
{
    position_.y += y * DeltaTime::getDeltaTime();
}

/**
 * It moves the object in the z direction.
 *
 * @param z The amount to move the object in the z direction.
 */
void Transform3D::moveZ(float z) noexcept
{
    position_.z += z * DeltaTime::getDeltaTime();
}

/**
 * Sets the x position of the transform.
 *
 * @param x The x position of the transform.
 */
void Transform3D::setX(float x) noexcept
{
    position_.x = x;
}

/**
 * Sets the y position of the transform.
 *
 * @param y The y position of the transform.
 */
void Transform3D::setY(float y) noexcept
{
    position_.y = y;
}

/**
 * Sets the z position of the Transform3D
 *
 * @param z The z-coordinate of the position.
 */
void Transform3D::setZ(float z) noexcept
{
    position_.z = z;
}

/**
 * Adds the given value to the x position.
 *
 * @param x The x position of the transform.
 */
void Transform3D::addX(float x) noexcept
{
    position_.x += x;
}

/**
 * Adds the given value to the y position.
 *
 * @param y The amount to add to the y position.
 */
void Transform3D::addY(float y) noexcept
{
    position_.y += y;
}

/**
 * Adds the given value to the z-coordinate of the position.
 *
 * @param z The amount to add to the z position.
 */
void Transform3D::addZ(float z) noexcept
{
    position_.z += z;
}
