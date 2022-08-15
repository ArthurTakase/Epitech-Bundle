/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Round
*/

#include "Round.hpp"

#include <math.h>

/**
 * Round a float to n decimal places.
 *
 * @param x The number to round.
 * @param n The number of decimal places to round to.
 *
 * @return a float.
 */
float Round::round(const float& x, const int& n) noexcept
{
    return static_cast<float>(static_cast<int>((x * pow(10, n)) / pow(10, n)));
}

/**
 * It rounds a vector to a specified number of decimal places
 *
 * @param x The vector to round.
 * @param n The number of decimal places to round to.
 *
 * @return A Vector3D object.
 */
Vector3D Round::roundVector(const Vector3D& x, const int& n) noexcept
{
    return { Round::round(x.x, n), Round::round(x.y, n), Round::round(x.z, n) };
}
