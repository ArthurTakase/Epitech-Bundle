/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <iostream>
#include <memory>

TEST(BehaviorComponent_, setOnUpdate)
{
    std::string captured_output;

    auto ent = std::make_unique<Entity>(0);

    auto behaviorComponent = std::make_unique<BehaviorComponent>();
    behaviorComponent->setOnUpdate(
        std::function<void(Entity * entity)>{[](Entity* entity) { std::cout << "Hello World" << std::endl; }});

    testing::internal::CaptureStdout();
    behaviorComponent->onUpdate(ent.get());
    captured_output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(captured_output, "Hello World\n");
}