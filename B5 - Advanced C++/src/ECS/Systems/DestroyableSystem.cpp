/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include <ECS/Systems/DestroyableSystem.hpp>

/**
 * It takes a reference to a unique pointer to an EntityManager, and then it initializes the manager_
 * member variable with that reference, and it initializes the it_ member variable with an
 * EntityIterator that iterates over the entities in the EntityManager
 *
 * @param EntityManager The EntityManager that the system will use to iterate over entities.
 */
DestroyableSystem::DestroyableSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * It iterates through all entities with a BehaviorComponent and calls their onUpdate() function
 */
void DestroyableSystem::run()
{
    for (; !it_.isEnd(); ++it_) {
        Entity* entity = it_.get();

        if (!entity->hasComponents<DestroyableComponent>()) { continue; }

        auto dest = entity->getComponent<DestroyableComponent>();

        if (dest->getDestroyed()) {
            dest->onDestroy(entity);
            manager_->removeEntity(entity->getId());
            --it_;
        }
    }
    it_.reset();
}
