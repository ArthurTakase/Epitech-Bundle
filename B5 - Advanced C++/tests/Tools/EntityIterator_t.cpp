/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** EntityIterator_t
*/

#include <gtest/gtest.h>

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Tools/EntityIterator.hpp>

void createPlayer_it(int x, int y, EntityManager* manager)
{
    auto player = manager->newEntity();

    auto hitbox = HitboxComponent(15, 21);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{
        [](Entity* entity, Entity* me) { std::cout << "Collision" << std::endl; }});

    player->addComponent(hitbox);
    player->addComponent(TransformComponent(x, y));
}

void createEnemy_it(int x, int y, EntityManager* manager)
{
    auto enemy = manager->newEntity();
    enemy->addComponent(TransformComponent(x, y));
}

TEST(EntityIterator, search_hitbox_and_position_and_check_both)
{
    std::string captured_output;

    auto manager = std::make_unique<EntityManager>();
    createEnemy_it(100, 100, manager.get());
    createPlayer_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createPlayer_it(100, 100, manager.get());
    createPlayer_it(100, 100, manager.get());

    auto it = EntityIterator<HitboxComponent, TransformComponent>(manager->getEntities());

    testing::internal::CaptureStdout();

    while (!it.isEnd()) {
        std::cout << it.get()->getId() << std::endl;
        ++it;
    }
    it.reset();

    createPlayer_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createPlayer_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createPlayer_it(100, 100, manager.get());

    while (!it.isEnd()) {
        std::cout << it.get()->getId() << std::endl;
        ++it;
    }
    it.reset();

    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "1\n4\n5\n1\n4\n5\n6\n9\n11\n");
}

TEST(EntityIterator, search_position_and_check_for_hitbox)
{
    auto manager = std::make_unique<EntityManager>();
    createEnemy_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());
    createEnemy_it(100, 100, manager.get());

    auto it = EntityIterator<TransformComponent>(manager->getEntities());

    while (!it.isEnd()) {
        EXPECT_FALSE((it.get()->hasComponents<HitboxComponent>()));
        ++it;
    }
    it.reset();
}