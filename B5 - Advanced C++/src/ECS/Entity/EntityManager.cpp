/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/MusicComponent.hpp>
#include <ECS/Components/SoundComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TimerComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Lib/Sprite.hpp>
#include <Lib/Timer.hpp>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

/**
 * It removes an entity from the entity manager
 *
 * @param id The id of the entity to remove.
 *
 * @return A pointer to the entity with the given id.
 */
bool EntityManager::removeEntity(size_t id) noexcept
{
    for (auto it = entities_.begin(); it != entities_.end(); it++) {
        if ((*it)->getId() == id) {
            entities_.erase(it);
            return true;
        }
    }
    return false;
}

/**
 * It loops through all the entities in the entity manager and returns the entity with the specified ID
 *
 * @param id The id of the entity to get.
 *
 * @return A pointer to an entity.
 */
Entity* EntityManager::getEntity(size_t id) const noexcept
{
    for (auto& entity : entities_) {
        if (entity->getId() == id) { return entity.get(); }
    }
    return nullptr;
}

/**
 * It returns a reference to the vector of entities
 *
 * @return A reference to the vector of entities.
 */
std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities() noexcept
{
    return entities_;
}

/**
 * It creates a new id for an entity
 *
 * @return The id of the entity.
 */
size_t EntityManager::createId() const noexcept
{
    if (entities_.empty()) { return 0; }

    int i = 0;
    for (; i < entities_.size() && entities_[i]->getId() <= i; i++) {}
    return i;
}

/**
 * It creates a new entity and adds it to the entity manager
 *
 * @return A pointer to the newly created entity.
 */
Entity* EntityManager::newEntity() noexcept
{
    size_t                  id     = createId();
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(id);
    size_t                  index  = id < entities_.size() ? id : entities_.size();

    entities_.insert(entities_.begin() + index, std::move(entity));

    return entities_[index].get();
}

/**
 * It creates a new entity and adds it to the list of entities
 *
 * @param id The id of the entity.
 *
 * @return A pointer to the last element in the vector.
 */
Entity* EntityManager::newEntity(int id) noexcept
{
    std::unique_ptr<Entity> entity = std::make_unique<Entity>(id);
    size_t                  index  = id < entities_.size() ? id : entities_.size();

    entities_.insert(entities_.begin() + index, std::move(entity));

    return entities_[index].get();
}

/**
 * It creates a log file with the current time as name, and writes in it the list of entities and their
 * components
 */
void EntityManager::log() const noexcept
{
    auto          now         = std::chrono::system_clock::now();
    time_t        currentTime = std::chrono::system_clock::to_time_t(now);
    std::string   fileName    = "log_" + std::to_string(currentTime) + ".csv";
    std::ofstream outFile(fileName);

    outFile << "Entity ID,Animation,Destroyable,Drawable,Transform,Mouvement,Behavior,Hitbox,Input,Sound,Stat"
            << std::endl;

    for (auto& entity : entities_) {
        outFile << entity->getId() << ",";
        entity->hasComponent<AnimationComponent>()
            ? outFile << entity->getComponent<AnimationComponent>()->getTimer().getElapsedTime() << ","
            : outFile << "___,";
        entity->hasComponent<DestroyableComponent>()
            ? outFile << (int)entity->getComponent<DestroyableComponent>()->getDestroyed() << ","
            : outFile << "___,";
        entity->hasComponent<DrawableComponent>()
            ? outFile << (int)entity->getComponent<DrawableComponent>()->getTextureId() << ","
            : outFile << "___,";
        entity->hasComponent<TransformComponent>()
            ? outFile << "x: " << (int)entity->getComponent<TransformComponent>()->getX()
                      << " y: " << (int)entity->getComponent<TransformComponent>()->getY() << ","
            : outFile << "___,";
        entity->hasComponent<MouvementComponent>()
            ? outFile << "x: " << (int)entity->getComponent<MouvementComponent>()->getDirX()
                      << " y: " << (int)entity->getComponent<MouvementComponent>()->getDirY()
                      << " speed: " << (float)entity->getComponent<MouvementComponent>()->getSpeed() << ","
            : outFile << "___,";
        entity->hasComponent<BehaviorComponent>() ? outFile << "yes," : outFile << "___,";
        entity->hasComponent<HitboxComponent>() ? outFile << "yes," : outFile << "___,";
        entity->hasComponent<InputComponent>() ? outFile << "yes," : outFile << "___,";
        entity->hasComponent<SoundComponent>() ? outFile << "yes," : outFile << "___,";
        entity->hasComponent<StatComponent>() ? outFile << "yes," : outFile << "___,";
        outFile << std::endl;
    }

    outFile.close();

    std::cout << "Log file created: " << fileName << std::endl;
}