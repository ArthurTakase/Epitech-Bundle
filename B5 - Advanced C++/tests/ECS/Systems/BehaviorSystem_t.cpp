/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxSystem
*/

#include <gtest/gtest.h>

#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
#include <Tools/EntityIterator.hpp>

void createPlayer_bs(int x, int y, EntityManager* manager)
{
    auto player = manager->newEntity();

    auto hitbox = HitboxComponent(15, 21);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{
        [](Entity* entity, Entity* me) { std::cout << "Collision" << std::endl; }});

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(
        std::function<void(Entity * entity)>{[](Entity* entity) { std::cout << "Hello World" << std::endl; }});

    player->addComponent(behaviorComponent);
    player->addComponent(hitbox);
    player->addComponent(TransformComponent(x, y));
}

TEST(BehaviorSystem_, run)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    createPlayer_bs(100, 100, manager.get());
    createPlayer_bs(100, 100, manager.get());
    createPlayer_bs(100, 100, manager.get());
    manager->getEntity(0)->removeComponent<BehaviorComponent>();

    auto system = std::make_unique<BehaviorSystem>(manager.get());

    testing::internal::CaptureStdout();
    system->run();
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Hello World\nHello World\n");
}