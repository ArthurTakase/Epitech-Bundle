/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Cameraman
*/

#pragma once

#include "Vector.hpp"
#include "raylib.h"

class Cameraman
{
  public:
    Cameraman() noexcept;
    ~Cameraman() noexcept                      = default;
    Cameraman(const Cameraman& other) noexcept = delete;
    Cameraman(Cameraman&& other) noexcept      = delete;
    Cameraman& operator=(const Cameraman& rhs) noexcept = delete;
    Cameraman& operator=(Cameraman&& rhs) noexcept = delete;

    Vector3D getPosition() const noexcept;
    Vector3D getTarget() const noexcept;
    Vector3D getUp() const noexcept;
    bool     getIsMoving() const noexcept;
    void     setPosition(const Vector3D& pos) noexcept;
    void     setIsMoving(bool isMoving) noexcept;

    void begin3D() const noexcept;
    void end3D() const noexcept;
    void moveTo(const Vector3D& to, const Vector3D& target, const Vector3D& up) noexcept;
    void tpTo(const Vector3D& to, const Vector3D& target, const Vector3D& up) noexcept;
    bool smoothMove() noexcept;

  protected:
    Camera3D camera_;
    bool     is_moving_ = false;
    float    speed_;
    Vector3D position_;
    Vector3D target_;
    Vector3D up_;

    // methods
    void moveX(float x) noexcept;
    void moveY(float y) noexcept;
    void moveZ(float z) noexcept;
};
