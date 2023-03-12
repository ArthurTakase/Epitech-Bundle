/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TransformComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>

/**
 * @brief Component used to store the position of an entity
 */
class TransformComponent : public IComponent
{
  public:
    TransformComponent(int x, int y);
    TransformComponent(const TransformComponent& other) noexcept = default;
    TransformComponent(TransformComponent&& other) noexcept      = default;
    ~TransformComponent() noexcept                               = default;

    TransformComponent& operator=(const TransformComponent& rhs) noexcept = default;
    TransformComponent& operator=(TransformComponent&& rhs) noexcept      = default;

    int  getX() const noexcept;
    int  getY() const noexcept;
    void setX(int x) noexcept;
    void setY(int y) noexcept;
    void setPos(int x, int y) noexcept;

  private:
    int x_;
    int y_;
};
