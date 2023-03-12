/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Entity
*/

#include <gtest/gtest.h>

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/Entity.hpp>

TEST(Entity_, getId)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getId(), 1);
}

TEST(Entity_, getComponents)
{
    auto entity = std::make_unique<Entity>(1);
    EXPECT_EQ(entity->getComponents().size(), 0);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
}

TEST(Entity_, addComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 1);
    entity->addComponent(TransformComponent(10, 10));
    EXPECT_EQ(entity->getComponents().size(), 2);
}

TEST(Entity_, getComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->getComponent<HitboxComponent>());
    EXPECT_FALSE(entity->getComponent<TransformComponent>());
}

TEST(Entity_, removeComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    entity->addComponent(TransformComponent(10, 10));
    EXPECT_TRUE(entity->getComponent<HitboxComponent>());
    EXPECT_TRUE(entity->getComponent<TransformComponent>());
    EXPECT_EQ(entity->getComponents().size(), 2);
    entity->removeComponent<HitboxComponent>();
    EXPECT_FALSE(entity->getComponent<HitboxComponent>());
    EXPECT_EQ(entity->getComponents().size(), 1);
    entity->removeComponent<TransformComponent>();
    EXPECT_FALSE(entity->getComponent<TransformComponent>());
    EXPECT_FALSE(entity->removeComponent<TransformComponent>());
    EXPECT_EQ(entity->getComponents().size(), 0);
}

TEST(Entity_, hasComponent)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_TRUE(entity->hasComponent<HitboxComponent>());
    EXPECT_FALSE(entity->hasComponent<TransformComponent>());
}

TEST(Entity_, hasComponents)
{
    auto entity = std::make_unique<Entity>(1);
    entity->addComponent(HitboxComponent(10, 10));
    EXPECT_FALSE((entity->hasComponents<HitboxComponent, TransformComponent>()));
    entity->addComponent(TransformComponent(10, 10));
    EXPECT_TRUE((entity->hasComponents<HitboxComponent, TransformComponent>()));
}