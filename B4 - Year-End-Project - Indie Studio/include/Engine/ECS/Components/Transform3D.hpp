/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Transform3D.cpp
*/

#pragma once

#include "Component.hpp"
#include "Vector.hpp"

class Transform3D : public Component
{
  public:
    Transform3D() noexcept                         = default;
    Transform3D(const Transform3D& other) noexcept = default;
    Transform3D(Transform3D&& other) noexcept      = default;
    ~Transform3D() noexcept                        = default;

    Transform3D& operator=(const Transform3D& rhs) noexcept = default;
    Transform3D& operator=(Transform3D&& rhs) noexcept = default;

    // getters and setters
    Vector3D      getPosition() const noexcept;
    float         getPositionX() const noexcept;
    float         getPositionY() const noexcept;
    float         getPositionZ() const noexcept;
    float         getScale() const noexcept;
    Vector3D      getRotationAxis() const noexcept;
    float         getRotationAngle() const noexcept;
    ComponentType getComponentType() const noexcept;
    void          setScale(float scale) noexcept;
    void          setRotationAxis(const Vector3D& rotationAxis) noexcept;
    void          setRotationAngle(float rotationAngle) noexcept;
    void          setPosition(const Vector3D& position) noexcept;

    // methods
    void moveX(float x) noexcept;
    void moveY(float y) noexcept;
    void moveZ(float z) noexcept;
    void setX(float x) noexcept;
    void setY(float y) noexcept;
    void setZ(float z) noexcept;
    void addX(float x) noexcept;
    void addY(float y) noexcept;
    void addZ(float z) noexcept;

    static constexpr ComponentType TYPE = ComponentType::TRANSFORM;

  private:
    Vector3D position_ = { 0.0f, 0.0f, 0.0f };
    Vector3D size_     = { 1.0f, 1.0f, 1.0f };
    float    scale_    = 1.0f;
    Vector3D rotation_axis_;
    float    rotation_angle_;
};
