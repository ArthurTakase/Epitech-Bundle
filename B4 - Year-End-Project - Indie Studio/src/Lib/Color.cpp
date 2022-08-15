/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Color
*/

#include "Color.hpp"

/**
 * It's a constructor that takes a reference to a constant array of three unsigned characters and
 * assigns it to the color_ member variable
 *
 * @param color The color to be used for the color manager.
 */
ColorManager::ColorManager(const std::array<unsigned char, 3>& color) noexcept
{
    color_ = color;
}

/**
 * It sets the color of the object
 *
 * @param color The color to set.
 */
void ColorManager::setColor(const std::array<unsigned char, 3>& color) noexcept
{
    color_ = color;
}

/**
 * It returns the color of the object
 *
 * @return A reference to the color_ array.
 */
std::array<unsigned char, 3> ColorManager::getColor() const noexcept
{
    return (color_);
}