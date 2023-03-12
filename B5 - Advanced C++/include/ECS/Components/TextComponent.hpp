/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** TextComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Lib/Text.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component assigned to drawable entities.
 */
class TextComponent : public IComponent
{
  public:
    TextComponent() noexcept = default;
    TextComponent(const std::string& text, const std::string& fontPath, int fontSize, int x, int y);
    TextComponent(const TextComponent& other) noexcept;
    TextComponent(TextComponent&& other) noexcept = default;
    ~TextComponent() noexcept                     = default;

    TextComponent& operator=(const TextComponent& rhs) noexcept = default;
    TextComponent& operator=(TextComponent&& rhs) noexcept      = default;

    Text& getText() noexcept;

  private:
    Text text_;
};