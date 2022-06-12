/*
** EPITECH PROJECT, 2022
** Text
** File description:
** Text
*/

#include "Elements.hpp"

/**
 * @brief Construct a new Text:: Text object
 *
 * @param str Phrase à afficher
 * @param color Couleur du texte
 * @param x Position X du texte
 * @param y Position Y du texte
 * @param underline Active ou non le soulignage
 */
Text::Text(std::string str, Arcade::TextColor color, size_t x, size_t y, bool underline)
    : str(str), color(color), x(x), y(y), underline(underline)
{
}

Text::Text(const Text &other) : str(other.str), color(other.color), x(other.x), y(other.y), underline(other.underline) {}

Text::Text(const Text &&other) : str(other.str), color(other.color), x(other.x), y(other.y), underline(other.underline) {}

Text &Text::operator=(const Text &other) noexcept
{
    str   = other.str;
    color = other.color;
    x     = other.x;
    y     = other.y;

    return *this;
}

Text &Text::operator=(Text &&other) noexcept
{
    str   = other.str;
    color = other.color;
    x     = other.x;
    y     = other.y;

    return *this;
}
