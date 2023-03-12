/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MusicSystem
*/

#include <ECS/Systems/MusicSystem.hpp>

/**
 * It initializes the member variables of the MusicSystem class
 *
 * @param manager The entity manager that the system will be using.
 */
MusicSystem::MusicSystem(EntityManager* manager) noexcept
    : manager_(manager)
    , it_(manager->getEntities())
{
}

/**
 * It iterates through all entities with a MusicComponent and plays the music
 */
void MusicSystem::run()
{
    for (; !it_.isEnd(); ++it_) {
        Entity* entity = it_.get();

        if (!entity->hasComponent<MusicComponent>()) { continue; }

        entity->getComponent<MusicComponent>()->play();
    }
    it_.reset();
}