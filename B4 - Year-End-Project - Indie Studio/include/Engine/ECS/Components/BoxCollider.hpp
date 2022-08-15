/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** BoxCollider
*/

#pragma once

#include <memory>

#include "Component.hpp"
#include "Vector.hpp"

class BoxCollider : public Component
{
  public:
    BoxCollider(const Vector3D& pos, const Vector3D& size, bool solid) noexcept;
    BoxCollider(const BoxCollider& other) noexcept = default;
    BoxCollider(BoxCollider&& other) noexcept      = default;
    ~BoxCollider() noexcept                        = default;

    BoxCollider& operator=(const BoxCollider& rhs) noexcept = default;
    BoxCollider& operator=(BoxCollider&& rhs) noexcept = default;

    Vector3D      getPosition() const noexcept;
    void          setPosition(const Vector3D& pos) noexcept;
    void          setPositionY(int pos) noexcept;
    void          setPositionZ(int pos) noexcept;
    bool          getIsSolid() const noexcept;
    void          setIsSolid(bool newValue) noexcept;
    Vector3D      getSize() const noexcept;
    ComponentType getComponentType() const noexcept;

    void addX(float value) noexcept;
    void addY(float value) noexcept;
    void addZ(float value) noexcept;

    bool checkCollision(const Vector3D& pos,
        const Vector3D&                 size,
        const Vector3D&                 otherPos,
        const Vector3D&                 otherSize) const noexcept;
    void update(const Vector3D& pos) noexcept;
    bool isColliding(const BoxCollider& other) const noexcept;
    bool isColliding(const BoxCollider& otherHit, const Vector3D& otherPos) const noexcept;

    static constexpr ComponentType TYPE = ComponentType::BOXCOLLIDER;

  protected:
  private:
    Vector3D position_;
    Vector3D size_;
    bool     is_solid_;
};