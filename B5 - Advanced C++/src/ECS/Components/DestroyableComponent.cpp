/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** DestroyableComponent.cpp
*/

#include <ECS/Components/DestroyableComponent.hpp>

/**
 * It's a constructor that takes an integer and sets the destroyed_ member variable
 * to the integer's value
 *
 * @param destroy Whether or not the component is destroyed.
 */
DestroyableComponent::DestroyableComponent(int destroy) noexcept
{
    destroyed_ = static_cast<bool>(destroy);
}

/**
 * Returns whether or not the entity is destroyed.
 *
 * @return A boolean value.
 */
bool DestroyableComponent::getDestroyed() const noexcept
{
    return destroyed_;
}

/**
 * The function sets the destroyed_ member variable to true.
 */
void DestroyableComponent::destroy() noexcept
{
    destroyed_ = true;
}

/**
 * It sets the function that will be called when the entity is destroyed
 *
 * @param self The entity that this component is attached to.
 */
void DestroyableComponent::setOnDestroy(std::function<void(Entity* self)> onDestroy) noexcept
{
    onDestroy_ = onDestroy;
}

/**
 * If the onDestroy_ function pointer is not null, call it
 *
 * @param self The entity that the component is attached to.
 *
 * @return A pointer to the DestroyableComponent.
 */
void DestroyableComponent::onDestroy(Entity* self) const noexcept
{
    if (!onDestroy_) return;
    onDestroy_(self);
}