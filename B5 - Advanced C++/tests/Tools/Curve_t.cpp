/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Tools
*/

#include <gtest/gtest.h>

#include <Tools/Curve.hpp>

TEST(Tools_, Curve)
{
    EXPECT_EQ(Tools::curve(20, 0.05, 10), 9);
    EXPECT_EQ(Tools::curve(20, 1, 0), 0);
    EXPECT_EQ(Tools::curve(20, 0.05, 20), 16);
    EXPECT_EQ(Tools::curve(10, 0.2, 5), 8);
}