/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include <gtest/gtest.h>

#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <Tools/EntityIterator.hpp>

void createPlayer_ds(int x, int y, EntityManager* manager, int dest)
{
    auto player = manager->newEntity();
    player->addComponent(DestroyableComponent(dest));
}

TEST(DestroyableSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    createPlayer_ds(100, 100, manager.get(), 0);
    createPlayer_ds(100, 100, manager.get(), 0);
    createPlayer_ds(100, 100, manager.get(), 1);

    auto system = std::make_unique<DestroyableSystem>(manager.get());

    EXPECT_EQ(manager->getEntities().size(), 3);
    system->run();
    EXPECT_EQ(manager->getEntities().size(), 2);
    manager->getEntity(0)->getComponent<DestroyableComponent>()->destroy();
    system->run();
    EXPECT_EQ(manager->getEntities().size(), 1);
}