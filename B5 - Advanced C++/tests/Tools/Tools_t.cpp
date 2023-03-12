/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Tools
*/

#include <gtest/gtest.h>

#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Tools/InstanceOf.hpp>
#include <memory>

TEST(Tools_, instanceOf)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);

    EXPECT_TRUE(Tools::instanceOf<TransformComponent>(pos.get()));
    EXPECT_FALSE(Tools::instanceOf<HitboxComponent>(pos.get()));
}