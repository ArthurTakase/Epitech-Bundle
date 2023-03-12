/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include <ECS/Systems/AnimationSystem.hpp>

/**
 * It takes a reference to a unique pointer to an EntityManager, and then it initializes the manager_
 * member variable with that reference, and it initializes the it_ member variable with an
 * EntityIterator that iterates over the entities in the EntityManager
 *
 * @param EntityManager The EntityManager that the system will use to iterate over entities.
 */
AnimationSystem::AnimationSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * It iterates through all entities with a BehaviorComponent and calls their onUpdate() function
 */
void AnimationSystem::run()
{
    for (; !it_.isEnd(); ++it_) {
        Entity* entity = it_.get();

        if (!entity->hasComponents<DrawableComponent, AnimationComponent>()) { continue; }

        auto  draw   = entity->getComponent<DrawableComponent>();
        auto  anime  = entity->getComponent<AnimationComponent>();
        auto& timer  = anime->getTimer();
        auto& sprite = draw->getSprite();

        if (timer.isOver()) {
            auto offsetX = draw->getOffsetX();
            draw->setOffsetX(offsetX + draw->getWidth());
            if (draw->getOffsetX() >= anime->getLimit()) { draw->setOffsetX(0); }
        }
    }
    it_.reset();
}
