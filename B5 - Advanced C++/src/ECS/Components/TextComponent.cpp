/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** TextComponent
*/

#include <ECS/Components/TextComponent.hpp>

/**
 * It's a constructor that takes a string, a font path, a font size, and two
 * integers, and it uses those to initialize a Text object
 *
 * @param text The text to be displayed
 * @param fontPath The path to the font file.
 * @param fontSize The size of the font.
 * @param x The x position of the text
 * @param y The y coordinate of the text.
 */
TextComponent::TextComponent(const std::string& text, const std::string& fontPath, int fontSize, int x, int y)
    : text_(text, fontPath, fontSize, x, y)
{
}

/**
 * It creates a new TextComponent object that is a copy of the other TextComponent
 * object
 *
 * @param other The TextComponent object that is being copied.
 */
TextComponent::TextComponent(const TextComponent& other) noexcept
    : text_(other.text_.getTextString(),
        other.text_.getFontPath(),
        other.text_.getFontSize(),
        other.text_.getX(),
        other.text_.getY())
{
}

/**
 * It returns a reference to the Text object
 *
 * @return A reference to the text_ member variable.
 */
Text& TextComponent::getText() noexcept
{
    return text_;
}