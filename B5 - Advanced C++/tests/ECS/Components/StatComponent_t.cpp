/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/StatComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <iostream>
#include <memory>

TEST(StatComponent_, getStat)
{
    auto dest = StatComponent({1, 2, 3});

    EXPECT_EQ(dest.getStat(0), 1);
    EXPECT_EQ(dest.getStat(1), 2);
    EXPECT_EQ(dest.getStat(2), 3);
    EXPECT_EQ(dest.getStat(3), StatComponent::NO_INDEX);
}

TEST(StatComponent_, setStat)
{
    auto dest = StatComponent({0, 0, 0});

    dest.setStat(0, 1);
    dest.setStat(1, 2);
    dest.setStat(2, 3);
    dest.setStat(10, 5);

    EXPECT_EQ(dest.getStat(0), 1);
    EXPECT_EQ(dest.getStat(1), 2);
    EXPECT_EQ(dest.getStat(2), 3);
    EXPECT_EQ(dest.getStat(10), 5);
}