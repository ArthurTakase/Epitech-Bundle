/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include <gtest/gtest.h>

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/HitboxSystem.hpp>
#include <Tools/EntityIterator.hpp>

void createPlayer_hs(int x, int y, EntityManager* manager)
{
    auto player = manager->newEntity();

    auto hitbox = HitboxComponent(15, 21);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{
        [](Entity* entity, Entity* me) { std::cout << "Collision" << std::endl; }});

    player->addComponent(hitbox);
    player->addComponent(TransformComponent(x, y));
}

TEST(HitboxSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    createPlayer_hs(100, 100, manager.get());
    createPlayer_hs(100, 100, manager.get());
    createPlayer_hs(100, 100, manager.get());
    manager->getEntity(0)->getComponent<TransformComponent>()->setPos(0, 0);

    auto system = std::make_unique<HitboxSystem>(manager.get());

    testing::internal::CaptureStdout();
    system->run();
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Collision\nCollision\n");
}