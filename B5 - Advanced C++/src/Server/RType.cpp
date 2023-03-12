/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** RType.cpp
*/

#include <ECS/Components/SoundComponent.hpp>
#include <Server/RType.hpp>

/**
 * It initializes the server's game systems and creates a game object
 */
RType::RType()
    : hitboxSystem_(&entityManager_)
    , behaviorSystem_(&entityManager_)
    , mouvementSystem_(&entityManager_)
    , animationSystem_(&entityManager_)
    , destroyableSystem_(&entityManager_)
{
}

/**
 * It stops the game loop
 */
void RType::stop() noexcept
{
    looping_ = false;
}

/**
 * It sets the looping_ variable to true.
 */
void RType::reset() noexcept
{
    looping_ = true;
}

/**
 * It runs all the game's systems
 */
void RType::run() noexcept
{
    destroyableSystem_.run();
    hitboxSystem_.run();
    mouvementSystem_.run();
    behaviorSystem_.run();
    animationSystem_.run();
}

/**
 * It returns a reference to the hitbox system
 *
 * @return A reference to the hitbox system.
 */
HitboxSystem& RType::getHitboxSystem() noexcept
{
    return hitboxSystem_;
}

/**
 * It returns a reference to the behavior system
 *
 * @return A reference to the behavior system.
 */
BehaviorSystem& RType::getBehaviorSystem() noexcept
{
    return behaviorSystem_;
}

/**
 * It returns a reference to the entity manager
 *
 * @return A reference to the entity manager.
 */
EntityManager& RType::getManager() noexcept
{
    return entityManager_;
}

/**
 * It plays a sound
 *
 * @param id The id of the entity that has the SoundComponent
 */
void RType::playSound(int id) noexcept
{
    auto sound = entityManager_.getEntity(id);
    sound->getComponent<SoundComponent>()->setPlayed(true);
}

/**
 * It creates two backgrounds with different positions
 */
void RType::init() noexcept
{
    for (int i = 0; i < MUSIC_NB; i++) createSound();
    createBackground(0);
    createBackground(255);
}
