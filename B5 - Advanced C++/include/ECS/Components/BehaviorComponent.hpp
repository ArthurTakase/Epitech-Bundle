/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** BehaviorComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component for the behavior of an entity.
 */
class BehaviorComponent : public IComponent
{
  public:
    BehaviorComponent()                                        = default;
    BehaviorComponent(const BehaviorComponent& other) noexcept = default;
    BehaviorComponent(BehaviorComponent&& other) noexcept      = default;
    ~BehaviorComponent() noexcept                              = default;

    BehaviorComponent& operator=(const BehaviorComponent& rhs) noexcept = default;
    BehaviorComponent& operator=(BehaviorComponent&& rhs) noexcept      = default;

    void setOnUpdate(std::function<void(Entity* self)> onUpdate) noexcept;
    void onUpdate(Entity* self) const noexcept;

  private:
    std::function<void(Entity* self)> onUpdate_;
};
