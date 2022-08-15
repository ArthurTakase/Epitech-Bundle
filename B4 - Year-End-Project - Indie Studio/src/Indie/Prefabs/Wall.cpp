/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Wall
*/

#include "Wall.hpp"

#include "Error.hpp"
#include "InstanceOf.hpp"

/**
 * It creates a wall entity with a transform, a renderer and a box collider
 *
 * @param pos The position of the wall
 * @param model The model to be used for the wall.
 */
Wall::Wall(Vector3D pos, Model3D& model)
    : Entity()
{
    addComponent(Transform3D());
    addComponent(Render(model));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the bomb element.\n"));

    transform->get().setPosition(pos);
    transform->get().setScale(0.017f);
    renderer->get().setRenderType(RenderType::R_3DMODEL);
    Vector3D size = { 0.9f, 1.0f, 0.9f };
    addComponent(BoxCollider(transform->get().getPosition(), size, true));
}

/**
 * If the wall is enabled, move it down by 4 units per frame
 *
 * @return The return type is a pointer to a Component.
 */
void Wall::Update()
{
    if (!getEnabledValue()) return;
    auto transform = getComponent<Transform3D>();

    if (transform->get().getPosition().y > 0) { transform->get().moveY(-4.0f); }
    if (transform->get().getPosition().y < 0) { transform->get().setY(0.0f); }

    getComponent<BoxCollider>()->get().update(transform->get().getPosition());
}

/**
 * If the entity colliding with this wall is another wall, and the position of this wall is greater
 * than 0, destroy the other wall
 *
 * @param other The entity that collided with this entity.
 */
void Wall::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept
{
    auto transform = getComponent<Transform3D>();

    if (Type:: instanceof <Wall>(other.get()) && transform->get().getPosition().y > 0)
        other->destroy();
}
