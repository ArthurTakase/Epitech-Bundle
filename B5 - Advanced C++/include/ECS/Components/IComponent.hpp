/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** IComponent.cpp
*/

#pragma once

#include <cstddef>
#include <string>

/**
 * @brief Interface for all components
 */
class IComponent
{
  public:
    IComponent() noexcept          = default;
    virtual ~IComponent() noexcept = default;

    IComponent(const IComponent& other) noexcept = default;
    IComponent(IComponent&& other) noexcept      = default;

    IComponent& operator=(const IComponent& rhs) noexcept = default;
    IComponent& operator=(IComponent&& rhs) noexcept      = default;
};