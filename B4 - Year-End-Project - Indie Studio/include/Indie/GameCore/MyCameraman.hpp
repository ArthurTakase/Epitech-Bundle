/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MyCameraman.cpp
*/

#pragma once

#include <memory>
#include <vector>

#include "Cameraman.hpp"
#include "Entity.hpp"

class MyCameraman : public Cameraman
{
  public:
    MyCameraman() noexcept                         = default;
    MyCameraman(const MyCameraman& other) noexcept = delete;
    MyCameraman(MyCameraman&& other) noexcept      = delete;
    ~MyCameraman() noexcept                        = default;

    MyCameraman& operator=(const MyCameraman& rhs) noexcept = delete;
    MyCameraman& operator=(MyCameraman&& rhs) noexcept = delete;

    void lookBetweenEntity(const std::vector<std::unique_ptr<Entity>>& entities);
};