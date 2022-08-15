/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** Fire.cpp
** File description:
** Fire
*/

#include "Fire.hpp"

#include "Bomb.hpp"
#include "Crate.hpp"
#include "Entity.hpp"
#include "Error.hpp"
#include "InstanceOf.hpp"
#include "Item.hpp"
#include "Wall.hpp"

/**
 * It creates a fire entity with a transform, a renderer, and a box collider
 *
 * @param position The position of the fire.
 * @param model The model to be used for the fire.
 */
Fire::Fire(Vector3D position, Model3D& model)
    : Entity()
    , explodeTime(0.5f)
    , explodeTimer(explodeTime)
{
    addComponent(Transform3D());
    addComponent(Render(model));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the player element.\n"));

    transform->get().setPosition({ position.x, position.y - 0.3f, position.z });
    transform->get().setScale(1.2f);
    transform->get().setRotationAxis({ 1.0f, 0.0f, 0.0f });
    transform->get().setRotationAngle(-90.0f);
    renderer->get().setRenderType(RenderType::R_ANIMATE);
    renderer->get().getAnimation().addAnimation("assets/models/fire.iqm");

    addComponent(BoxCollider({ position.x, position.y, position.z }, { 0.5f, 0.5f, 0.5f }, true));
}

/**
 * If the timer is done, destroy the object
 */
void Fire::Update()
{
    explodeTimer.updateTimer();
    if (explodeTimer.isTimerDone()) destroy();
}

/**
 * > This function is called when the fire collides with another entity
 *
 * @param other The entity that collided with this entity.
 */
void Fire::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept {}

/**
 * If the entity is a crate, drop its item and destroy it. If it's an item, destroy it. If it's a
 * wall, return true. If it's a bomb, explode it. Otherwise, return false
 *
 * @param other The entity that the fire is colliding with.
 *
 * @return A boolean value.
 */
bool Fire::ExplodeElements(std::unique_ptr<Entity>& other) noexcept
{
    if (Type:: instanceof <Crate>(other.get())) {
        ((std::unique_ptr<Crate>&)other)->dropItem();
        other->destroy();
        return true;
    }
    if (Type:: instanceof <Item>(other.get())) {
        other->destroy();
        return false;
    }
    if (Type:: instanceof <Wall>(other.get())) return true;
    if (Type:: instanceof <Bomb>(other.get())) {
        ((std::unique_ptr<Bomb>&)other)->explode();
        return true;
    }
    return false;
}
