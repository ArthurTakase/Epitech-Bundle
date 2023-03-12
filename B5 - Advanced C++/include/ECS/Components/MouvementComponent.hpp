/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MouvementComponent.hpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>

/**
 * @brief Component used to set the direction and speed of the movement of an entity
 */
class MouvementComponent : public IComponent
{
  public:
    MouvementComponent(int dirX, int dirY, float speed) noexcept;
    MouvementComponent(const MouvementComponent& other) noexcept = default;
    MouvementComponent(MouvementComponent&& other) noexcept      = default;
    ~MouvementComponent() noexcept                               = default;

    MouvementComponent& operator=(const MouvementComponent& rhs) noexcept = default;
    MouvementComponent& operator=(MouvementComponent&& rhs) noexcept      = default;

    int getDirX() const noexcept;
    int getDirY() const noexcept;
    float getSpeed() const noexcept;
    void  setDirX(int x) noexcept;
    void  setDirY(int y) noexcept;
    void  setDir(int x, int y) noexcept;
    void  setSpeed(float speed) noexcept;

  private:
    int   dirX_;
    int   dirY_;
    float speed_;
};