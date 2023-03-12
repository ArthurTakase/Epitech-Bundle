/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxSystem.cpp
*/

#include <ECS/Systems/MouvementSystem.hpp>

/**
 * It's a constructor that takes an EntityIterator as a parameter and assigns it to the EntityIterator
 * member variable
 *
 * @param it The iterator that will be used to iterate over the entities.
 */
MouvementSystem::MouvementSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * It iterates over all entities that have a MouvementComponent and a TransformComponent, and updates
 * the TransformComponent's position according to the MouvementComponent's speed and direction
 */
void MouvementSystem::run()
{
    size_t other;

    for (; !it_.isEnd(); ++it_) {
        if (!(it_.get()->hasComponents<MouvementComponent, TransformComponent>())) { continue; }

        auto mouvement = it_.get()->getComponent<MouvementComponent>();
        auto transform = it_.get()->getComponent<TransformComponent>();

        transform->setX(transform->getX() + (mouvement->getSpeed() * mouvement->getDirX()));
        transform->setY(transform->getY() + (mouvement->getSpeed() * mouvement->getDirY()));
    }
    it_.reset();
}
