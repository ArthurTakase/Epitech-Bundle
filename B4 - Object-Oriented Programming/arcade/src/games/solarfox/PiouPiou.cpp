/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** PiouPiou
*/

#include "SolarFoxPiouPiou.hpp"

Solarfox::PiouPiou::PiouPiou(int x, int y, int xdir, int ydir, unsigned int lifetime, bool ennemy, bool special)
    : xdir(xdir), ydir(ydir), lifetime(lifetime)
{
    sprite.x          = x;
    sprite.y          = y;
    sprite.spritePath = "assets/img/solarfox/";

    if (special) sprite.spritePath += "special_";
    if (ennemy) sprite.spritePath += "bad_";
    sprite.color = (ennemy) ? Arcade::Color::BROWN : Arcade::Color::MAGENTA;
    sprite.spritePath += (xdir != 0) ? "pioupiou_h.png" : "pioupiou_v.png";
}

Solarfox::PiouPiou::~PiouPiou() {}

void Solarfox::PiouPiou::move()
{
    sprite.x += xdir * 2;
    sprite.y += ydir * 2;

    lifetime -= 1;
}

Sprite Solarfox::PiouPiou::getSprite() const noexcept
{
    return sprite;
}

int Solarfox::PiouPiou::getLifetime() const noexcept
{
    return lifetime;
}

void Solarfox::PiouPiou::setLifetime(int life) noexcept
{
    lifetime = life;
}
