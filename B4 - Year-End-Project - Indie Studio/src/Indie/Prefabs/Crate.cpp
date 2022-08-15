/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Crate
*/

#include "Crate.hpp"

#include <type_traits>

#include "Error.hpp"
#include "InstanceOf.hpp"
#include "Item.hpp"
#include "Wall.hpp"

/**
 * It creates a crate entity, adds a transform, a renderer and a box collider to it, and sets the
 * transform's position, scale and rotation
 *
 * @param pos The position of the crate.
 * @param newModel The model to be used for the crate.
 * @param data The GameData object, which is used to get the model of the crate.
 */
Crate::Crate(Vector3D pos, Model3D& newModel, GameData& data)
    : Entity()
    , data_(data)
{
    addComponent(Transform3D());
    addComponent(Render(newModel));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the crate element.\n"));

    transform->get().setPosition(pos);
    transform->get().setScale(0.015f);
    transform->get().setY(0 - transform->get().getScale());
    renderer->get().setRenderType(RenderType::R_3DMODEL);

    addComponent(
        BoxCollider({ transform->get().getPositionX(), 0.35f, transform->get().getPositionZ() },
            { 0.8f, 0.8f, 0.8f },
            true));
}

/**
 * If the crate is enabled, do nothing
 *
 * @return Nothing.
 */
void Crate::Update()
{
    if (!getEnabledValue()) return;
}

/**
 * If the random number generator returns a number that is not 0, then the function returns.
 * Otherwise, it adds an item to the game world
 *
 * @return A reference to the data_ member.
 */
void Crate::dropItem()
{
    auto transform = getComponent<Transform3D>();

    if (!transform.has_value()) throw(Error("Error in dropping item.\n"));
    if (rand() % 3 != 0) return;

    data_.addItem(transform->get().getPosition());
}

/**
 * If the crate collides with a wall, destroy the crate
 *
 * @param other The entity that collided with this entity.
 */
void Crate::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept
{
    if (Type:: instanceof <Wall>(other.get())) destroy();
}
