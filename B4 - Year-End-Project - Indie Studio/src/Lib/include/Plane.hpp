/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Plane.cpp
*/

#pragma once

#include "Color.hpp"
#include "Vector.hpp"

class Plane
{
  public:
    Plane() noexcept                   = delete;
    ~Plane() noexcept                  = delete;
    Plane(const Plane& other) noexcept = delete;
    Plane(Plane&& other) noexcept      = delete;

    Plane& operator=(const Plane& rhs) noexcept = delete;
    Plane& operator=(Plane&& rhs) noexcept = delete;

    static void draw(Vector3D pos, Vector2D size, std::array<unsigned char, 3> color) noexcept;
};