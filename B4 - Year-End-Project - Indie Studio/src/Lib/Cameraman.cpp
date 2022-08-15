/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Cameraman
*/

#include "Cameraman.hpp"

#include "DeltaTime.hpp"
#include "Round.hpp"

/**
 * The constructor initializes the camera's field of view to 60 degrees and sets the projection to
 * perspective
 */
Cameraman::Cameraman() noexcept
    : speed_(15.0f)
{
    camera_.fovy       = 60.0f;
    camera_.projection = CAMERA_PERSPECTIVE;
    camera_.position   = { 0.0f, 0.0f, 0.0f };
    camera_.target     = { 0.0f, 0.0f, 0.0f };
    camera_.up         = { 0.0f, 0.0f, 0.0f };
}

/**
 * It moves the camera in the X direction
 *
 * @param x The amount to move the camera in the x direction.
 */
void Cameraman::moveX(float x) noexcept
{
    camera_.position.x += x * DeltaTime::getDeltaTime();
}

/**
 * It moves the camera in the Y direction
 *
 * @param y The amount to move the camera in the y direction.
 */
void Cameraman::moveY(float y) noexcept
{
    camera_.position.y += y * DeltaTime::getDeltaTime();
}

/**
 * It moves the camera in the Z axis
 *
 * @param z The amount to move the camera in the z direction.
 */
void Cameraman::moveZ(float z) noexcept
{
    camera_.position.z += z * DeltaTime::getDeltaTime();
}

/**
 * It moves the camera to a new position, and sets the target and up vectors
 *
 * @param to The position of the camera.
 * @param target The point in space that the camera is looking at.
 * @param up The up vector of the camera.
 */
void Cameraman::moveTo(const Vector3D& to, const Vector3D& target, const Vector3D& up) noexcept
{
    position_  = to;
    target_    = target;
    up_        = up;
    is_moving_ = true;
}

/**
 * It teleports the camera to a new position, target and up vector
 *
 * @param to the new position of the camera
 * @param tar the target point of the camera
 * @param newUp the new up vector of the camera.
 */
void Cameraman::tpTo(const Vector3D& to, const Vector3D& tar, const Vector3D& newUp) noexcept
{
    camera_.position.x = to.x;
    camera_.position.y = to.y;
    camera_.position.z = to.z;

    camera_.target.x = tar.x;
    camera_.target.y = tar.y;
    camera_.target.z = tar.z;

    camera_.up.x = newUp.x;
    camera_.up.y = newUp.y;
    camera_.up.z = newUp.z;

    is_moving_ = false;
}

/**
 * It moves the camera towards the target position, and returns true if the camera is still moving
 *
 * @return A boolean.
 */
bool Cameraman::smoothMove() noexcept
{
    bool     thereIsMovement = false;
    Vector3D roundPos        = { Round::round(camera_.position.x, 1),
        Round::round(camera_.position.y, 1),
        Round::round(camera_.position.z, 1) };
    Vector3D roundTarget     = Round::roundVector(position_, 1);
    float    dirX            = (roundPos.x < roundTarget.x) ? 1.0f : -1.0f;
    float    dirY            = (roundPos.y < roundTarget.y) ? 1.0f : -1.0f;
    float    dirZ            = (roundPos.y < roundTarget.y) ? 1.0f : -1.0f;

    if ((dirZ == 1 && roundTarget.z > roundPos.z) || (dirZ == -1 && roundTarget.z < roundPos.z)) {
        thereIsMovement = true;
        moveZ(dirZ * speed_);
    }
    if ((dirX == 1 && roundTarget.x > roundPos.x) || (dirX == -1 && roundTarget.x < roundPos.x)) {
        thereIsMovement = true;
        moveX(dirX * speed_);
    }
    if ((dirY == 1 && roundTarget.y > roundPos.y) || (dirY == -1 && roundTarget.y < roundPos.y)) {
        thereIsMovement = true;
        moveY(dirY * speed_);
    }

    camera_.target.x = target_.x;
    camera_.target.y = target_.y;
    camera_.target.z = target_.z;

    camera_.up.x = up_.x;
    camera_.up.y = up_.y;
    camera_.up.z = up_.z;

    return (thereIsMovement);
}

/**
 * It returns the position of the cameraman
 *
 * @return A copy of the position_ member variable.
 */
Vector3D Cameraman::getPosition() const noexcept
{
    return position_;
}

/**
 * Returns the target of the cameraman.
 *
 * @return A copy of the target_ member variable.
 */
Vector3D Cameraman::getTarget() const noexcept
{
    return target_;
}

/**
 * Returns the up vector of the cameraman.
 *
 * @return A copy of the up_ vector.
 */
Vector3D Cameraman::getUp() const noexcept
{
    return up_;
}

/**
 * Returns whether the cameraman is moving.
 *
 * @return A boolean value.
 */
bool Cameraman::getIsMoving() const noexcept
{
    return is_moving_;
}

/**
 * It sets up the camera for 3D rendering
 */
void Cameraman::begin3D() const noexcept
{
    BeginMode3D(camera_);
}

/**
 * It ends the 3D mode
 */
void Cameraman::end3D() const noexcept
{
    EndMode3D();
}

/**
 * It sets the position of the camera
 *
 * @param pos The position of the camera.
 */
void Cameraman::setPosition(const Vector3D& pos) noexcept
{
    position_ = pos;
}

/**
 * Sets the value of the is_moving_ member variable.
 *
 * @param value The new value of the is_moving_ variable.
 */
void Cameraman::setIsMoving(bool value) noexcept
{
    is_moving_ = value;
}
