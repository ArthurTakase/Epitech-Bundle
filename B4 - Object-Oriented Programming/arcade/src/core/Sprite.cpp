/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Sprite
*/

#include "Elements.hpp"

/**
 * @brief Construct a new Sprite:: Sprite object
 *
 * @param filePath Lien du sprite à aficher (lib graphiques uniquement)
 * @param color Couleur de l'élement (lib textuelles uniquement)
 * @param x Position X du sprite
 * @param y Position Y du sprite
 */
Sprite::Sprite(std::string filePath, Arcade::Color color, size_t x, size_t y) : spritePath(filePath), color(color), x(x), y(y) {}

Sprite::Sprite(const Sprite &other) : spritePath(other.spritePath), color(other.color), x(other.x), y(other.y) {}

Sprite::Sprite(const Sprite &&other) : spritePath(other.spritePath), color(other.color), x(other.x), y(other.y) {}

Sprite::Sprite() : spritePath("assets/img/powerup.png"), color(Arcade::Color::WHITE), x(0), y(0) {}

Sprite &Sprite::operator=(const Sprite &other) noexcept
{
    spritePath = other.spritePath;
    color      = other.color;
    x          = other.x;
    y          = other.y;

    return *this;
}

Sprite &Sprite::operator=(Sprite &&other) noexcept
{
    spritePath = other.spritePath;
    color      = other.color;
    x          = other.x;
    y          = other.y;

    return *this;
}
