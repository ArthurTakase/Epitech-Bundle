/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Component
*/

#pragma once

enum class ComponentType { BOXCOLLIDER, RENDER, TRANSFORM, CONTROLLER, AI };

class Component
{
  public:
    Component() noexcept                       = default;
    Component(const Component& other) noexcept = default;
    Component(Component&& other) noexcept      = default;
    virtual ~Component() noexcept              = default;

    Component& operator=(const Component& rhs) noexcept = default;
    Component& operator=(Component&& rhs) noexcept = default;

    virtual ComponentType getComponentType() const noexcept = 0;

  protected:
  private:
};