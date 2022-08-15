/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** CollisionChecker.cpp
*/

#pragma once

#include "Vector.hpp"

class CollisionChecker
{
  public:
    CollisionChecker() noexcept                              = delete;
    ~CollisionChecker() noexcept                             = delete;
    CollisionChecker(const CollisionChecker& other) noexcept = delete;
    CollisionChecker(CollisionChecker&& other) noexcept      = delete;

    CollisionChecker& operator=(const CollisionChecker& rhs) noexcept = delete;
    CollisionChecker& operator=(CollisionChecker&& rhs) noexcept = delete;

    static bool check(const Vector3D& pos,
        const Vector3D&               size,
        const Vector3D&               otherPos,
        const Vector3D&               otherSize) noexcept;
};