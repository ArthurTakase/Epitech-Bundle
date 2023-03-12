/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/TransformComponent.hpp>

TEST(TransformComponent_, getX)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);
    EXPECT_EQ(pos->getX(), 10);
}

TEST(TransformComponent_, getY)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);
    EXPECT_EQ(pos->getY(), 10);
}

TEST(TransformComponent_, setX)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);
    pos->setX(20);
    EXPECT_EQ(pos->getX(), 20);
}

TEST(TransformComponent_, setY)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);
    pos->setY(20);
    EXPECT_EQ(pos->getY(), 20);
}

TEST(TransformComponent_, setPos)
{
    auto pos = std::make_unique<TransformComponent>(10, 10);
    pos->setPos(20, 20);
    EXPECT_EQ(pos->getX(), 20);
    EXPECT_EQ(pos->getY(), 20);
}
