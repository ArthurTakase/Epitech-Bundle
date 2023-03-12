/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** BehaviorComponent
*/

#include <ECS/Components/BehaviorComponent.hpp>

/**
 * It sets the onUpdate_ member variable to the function passed in as a parameter
 *
 * @param self The entity that owns this component.
 */
void BehaviorComponent::setOnUpdate(std::function<void(Entity* self)> onUpdate) noexcept
{
    onUpdate_ = onUpdate;
}

/**
 * If the onUpdate_ function pointer is not null, call it with the given Entity*.
 *
 * @param self The entity that the component is attached to.
 *
 * @return A reference to the onUpdate_ function.
 */
void BehaviorComponent::onUpdate(Entity* self) const noexcept
{
    if (!onUpdate_) return;
    onUpdate_(self);
}
