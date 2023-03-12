/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DestroyableComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <functional>

/**
 * @brief Component assigned to drawable entities.
 */
class DestroyableComponent : public IComponent
{
  public:
    DestroyableComponent() noexcept = default;
    DestroyableComponent(int destroy) noexcept;
    DestroyableComponent(const DestroyableComponent& other) noexcept = default;
    DestroyableComponent(DestroyableComponent&& other) noexcept      = default;
    ~DestroyableComponent() noexcept                                 = default;

    DestroyableComponent& operator=(const DestroyableComponent& rhs) noexcept = default;
    DestroyableComponent& operator=(DestroyableComponent&& rhs) noexcept      = default;

    bool getDestroyed() const noexcept;
    void destroy() noexcept;

    void setOnDestroy(std::function<void(Entity* self)> onDestroy) noexcept;
    void onDestroy(Entity* self) const noexcept;

  private:
    bool                              destroyed_ = false;
    std::function<void(Entity* self)> onDestroy_;
};