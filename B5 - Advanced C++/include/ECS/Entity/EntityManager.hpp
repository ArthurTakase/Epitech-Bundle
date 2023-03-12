/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** EntityManager.cpp
*/

#pragma once

#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Tools/InstanceOf.hpp>
#include <memory>
#include <vector>

/**
 * @brief Object used to create the different entities of the game
 */
class EntityManager
{
  public:
    EntityManager()                                    = default;
    ~EntityManager() noexcept                          = default;
    EntityManager(const EntityManager& other) noexcept = default;
    EntityManager(EntityManager&& other) noexcept      = delete;

    EntityManager& operator=(const EntityManager& rhs) noexcept = delete;
    EntityManager& operator=(EntityManager&& rhs) noexcept      = delete;

    bool                                  removeEntity(size_t id) noexcept;
    Entity*                               getEntity(size_t id) const noexcept;
    std::vector<std::unique_ptr<Entity>>& getEntities() noexcept;
    Entity*                               newEntity() noexcept;
    Entity*                               newEntity(int id) noexcept;
    void                                  log() const noexcept;

  private:
    size_t createId() const noexcept;

    std::vector<std::unique_ptr<Entity>> entities_;
};
