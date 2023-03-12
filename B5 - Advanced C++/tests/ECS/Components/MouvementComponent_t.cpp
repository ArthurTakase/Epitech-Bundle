/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** MouvementComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/MouvementComponent.hpp>

TEST(MouvementComponent_, getDirX)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    EXPECT_EQ(pos->getDirX(), 10);
}

TEST(MouvementComponent_, getDirY)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    EXPECT_EQ(pos->getDirY(), 10);
}

TEST(MouvementComponent_, getSpeed)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    EXPECT_EQ(pos->getSpeed(), 5.0);
}

TEST(MouvementComponent_, setDirX)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    pos->setDirX(20);
    EXPECT_EQ(pos->getDirX(), 20);
}

TEST(MouvementComponent_, setDirY)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    pos->setDirY(20);
    EXPECT_EQ(pos->getDirY(), 20);
}

TEST(MouvementComponent_, setSpeed)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    pos->setSpeed(20);
    EXPECT_EQ(pos->getSpeed(), 20);
}

TEST(MouvementComponent_, setDir)
{
    auto pos = std::make_unique<MouvementComponent>(10, 10, 5.0);
    pos->setDir(20, 20);
    EXPECT_EQ(pos->getDirX(), 20);
    EXPECT_EQ(pos->getDirY(), 20);
}