/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Systems/HitboxSystem.hpp>

/**
 * It takes an iterator of entities with a position and hitbox component, and stores it in a private
 * member variable
 *
 * @param it The iterator to use for the system.
 */
HitboxSystem::HitboxSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * For each entity in the system, check if it collides with any other entity in the system
 */
void HitboxSystem::run()
{
    size_t other;

    for (; !it_.isEnd(); ++it_) {
        if (!(it_.get()->hasComponents<HitboxComponent, TransformComponent>())) { continue; }

        checkCollision(it_.get());
    }
    it_.reset();
}

/**
 * If the entity's hitbox is colliding with another entity's hitbox, return the other entity's id
 *
 * @param entity The entity to check for collisions with.
 *
 * @return The id of the entity that is colliding with the entity passed in.
 */
void HitboxSystem::checkCollision(Entity* entity) const
{
    for (auto other = EntityIterator<TransformComponent, HitboxComponent>(it_.it); !other.isEnd(); ++other) {
        if (other.get() == entity) { continue; }

        if (!(other.get()->hasComponents<HitboxComponent, TransformComponent>())) { continue; }

        auto hitbox      = entity->getComponent<HitboxComponent>();
        auto pos         = entity->getComponent<TransformComponent>();
        auto otherHitbox = other.get()->getComponent<HitboxComponent>();
        auto otherPos    = other.get()->getComponent<TransformComponent>();

        auto x      = pos->getX();
        auto y      = pos->getY();
        auto otherX = otherPos->getX();
        auto otherY = otherPos->getY();

        if (x + hitbox->getWidth() >= otherX && x <= otherX + otherHitbox->getWidth()
            && y + hitbox->getHeight() >= otherY && y <= otherY + otherHitbox->getHeight()) {
            entity->getComponent<HitboxComponent>()->onCollision(other.get(), entity);
        }
    }
}
