/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DrawableSystem.cpp
*/

#pragma once

#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <ECS/Entity/EntityManager.hpp>
#include <Lib/Window.hpp>
#include <Tools/EntityIterator.hpp>

/**
 * @brief System used to check if an entity is colliding with another
 */
class DrawableSystem
{
  public:
    DrawableSystem(EntityManager* manager) noexcept;
    ~DrawableSystem() noexcept                           = default;
    DrawableSystem(const DrawableSystem& other) noexcept = default;
    DrawableSystem(DrawableSystem&& other) noexcept      = delete;

    DrawableSystem& operator=(const DrawableSystem& rhs) noexcept = delete;
    DrawableSystem& operator=(DrawableSystem&& rhs) noexcept      = delete;

    void run();
    void setWindow(Window* window) noexcept;

  private:
    EntityIterator<DrawableComponent, TransformComponent> it_;
    EntityManager*                                        manager_;
    Window*                                               window_ = nullptr;
};