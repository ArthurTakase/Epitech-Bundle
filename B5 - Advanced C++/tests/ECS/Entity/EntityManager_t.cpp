/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EntityManager
*/

#include <gtest/gtest.h>

#include <ECS/Entity/EntityManager.hpp>

void createPlayer_m(int x, int y, EntityManager* manager)
{
    auto player = manager->newEntity();

    auto hitbox = HitboxComponent(15, 21);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{
        [](Entity* entity, Entity* me) { std::cout << "Collision" << std::endl; }});

    player->addComponent(hitbox);
    player->addComponent(TransformComponent(x, y));
}

void createEnemy_m(int x, int y, EntityManager* manager)
{
    auto enemy = manager->newEntity();
    enemy->addComponent(TransformComponent(x, y));
}

TEST(EntityManager_, createPlayer)
{
    auto manager = std::make_unique<EntityManager>();
    createPlayer_m(100, 100, manager.get());
    auto player = manager->getEntity(0);
    EXPECT_TRUE(player->getComponent<TransformComponent>());
    EXPECT_TRUE(player->getComponent<HitboxComponent>());
}

TEST(EntityManager_, createEnemy)
{
    auto manager = std::make_unique<EntityManager>();
    createEnemy_m(100, 100, manager.get());
    auto enemy = manager->getEntity(0);
    EXPECT_TRUE(enemy->getComponent<TransformComponent>());
    EXPECT_FALSE(enemy->getComponent<HitboxComponent>());
}

TEST(EntityManager_, removeEntity)
{
    auto manager = std::make_unique<EntityManager>();
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    EXPECT_EQ(manager->getEntities().size(), 8);
    manager->removeEntity(0);
    manager->removeEntity(2);
    manager->removeEntity(4);
    manager->removeEntity(6);
    EXPECT_EQ(manager->getEntities().size(), 4);
    EXPECT_TRUE(manager->removeEntity(1));
    EXPECT_FALSE(manager->removeEntity(20));
}

TEST(EntityManager_, getEntity)
{
    auto manager = std::make_unique<EntityManager>();
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    EXPECT_EQ(manager->getEntity(0)->getId(), 0);
    EXPECT_EQ(manager->getEntity(1)->getId(), 1);
    EXPECT_FALSE(manager->getEntity(20));
    EXPECT_TRUE(manager->getEntity(5));
}

TEST(EntityManager_, getEntities)
{
    auto manager = std::make_unique<EntityManager>();
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    createPlayer_m(100, 100, manager.get());
    createEnemy_m(100, 100, manager.get());
    EXPECT_EQ(manager->getEntities().size(), 8);
}

TEST(EntityManager_, newEntityId)
{
    auto manager = std::make_unique<EntityManager>();

    auto player = manager->newEntity(10);

    EXPECT_EQ(player->getId(), 10);
}