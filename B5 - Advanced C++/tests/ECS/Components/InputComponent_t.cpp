/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HitboxComponent Unit Test
*/

#include <gtest/gtest.h>

#include <ECS/Components/InputComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <iostream>
#include <memory>

TEST(InputComponent_, input)
{
    auto input = std::make_unique<InputComponent>();

    EXPECT_EQ(input->getInput(), -1);

    input->addInput(1);
    input->addInput(2);
    input->addInput(3);

    EXPECT_EQ(input->getInput(), 1);
    EXPECT_EQ(input->getInput(), 2);
    EXPECT_EQ(input->getInput(), 3);

    input->addInput(4);
    input->addInput(5);
    input->addInput(6);
    input->clearInputs();

    EXPECT_EQ(input->getInput(), -1);
}