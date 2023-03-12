/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <iostream>
#include <memory>

TEST(DestroyableComponent_, classic)
{
    DestroyableComponent dest;

    EXPECT_EQ(dest.getDestroyed(), false);

    dest.destroy();

    EXPECT_EQ(dest.getDestroyed(), true);
}

TEST(DestroyableComponent_, argument)
{
    DestroyableComponent dest(1);

    EXPECT_EQ(dest.getDestroyed(), true);

    dest.destroy();

    EXPECT_EQ(dest.getDestroyed(), true);
}