/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MouvementSystem Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/MouvementSystem.hpp>

TEST(MouvementSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    auto ent     = manager->newEntity();
    ent->addComponent(TransformComponent(10, 10));
    ent->addComponent(MouvementComponent(1, 0, 1.0));

    auto ent2 = manager->newEntity();
    ent2->addComponent(TransformComponent(10, 10));
    ent2->addComponent(MouvementComponent(1, 0, 1.0));

    manager->getEntity(0)->getComponent<MouvementComponent>()->setSpeed(10);
    manager->getEntity(1)->getComponent<MouvementComponent>()->setDirY(1);
    manager->getEntity(1)->getComponent<MouvementComponent>()->setDirX(0);

    auto system = std::make_unique<MouvementSystem>(manager.get());

    system->run();

    EXPECT_EQ(manager->getEntity(0)->getComponent<TransformComponent>()->getX(), 20);
    EXPECT_EQ(manager->getEntity(0)->getComponent<TransformComponent>()->getY(), 10);

    EXPECT_EQ(manager->getEntity(1)->getComponent<TransformComponent>()->getX(), 10);
    EXPECT_EQ(manager->getEntity(1)->getComponent<TransformComponent>()->getY(), 11);
}