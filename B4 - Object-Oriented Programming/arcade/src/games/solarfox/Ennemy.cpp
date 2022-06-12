/*
** EPITECH PROJECT, 2022
** Ennemy
** File description:
** Ennemy
*/

#include "SolarFoxEnnemy.hpp"

/**
 * @brief Construct a new Solarfox:: Ennemy:: Ennemy object
 *
 * @param nstartX X de départ
 * @param nstartY Y de départ
 * @param nendX X d'arrivée
 * @param nendY Y d'arrivée
 * @param fileSprite Lien vers le sprite
 */
Solarfox::Ennemy::Ennemy(int nstartX, int nstartY, int nendX, int nendY, std::string fileSprite)
    : startX(nstartX), startY(nstartY), endX(nendX), endY(nendY)
{
    sprite.spritePath = fileSprite;
    sprite.color      = Arcade::Color::RED;
    reset();
}

/**
 * @brief Destroy the Solarfox:: Ennemy:: Ennemy object
 *
 */
Solarfox::Ennemy::~Ennemy() {}

Sprite Solarfox::Ennemy::getSprite() const noexcept
{
    return sprite;
}

void Solarfox::Ennemy::reverseSpeed() noexcept
{
    speed *= -1;
}

bool Solarfox::Ennemy::atEnd() const noexcept
{
    return (x == endX && y == endY);
}

bool Solarfox::Ennemy::atStart() const noexcept
{
    return (x == startX && y == startY);
}

void Solarfox::Ennemy::move() noexcept
{
    x += dirX * speed;
    y += dirY * speed;

    sprite.x = x;
    sprite.y = y;

    for (auto &it : pioupiou) it.move();

    countdownShoot -= 1;
}

void Solarfox::Ennemy::shoot() noexcept
{
    manageLifePiouPiou();
    if (countdownShoot > 0) return;
    int type = std::rand() % 20;
    type < 15 ? shootNormalPiouPiou() : shootSpecialPiouPiou();
    countdownShoot = std::rand() % 20 + 10;
}

void Solarfox::Ennemy::manageLifePiouPiou() noexcept
{
    int limit = pioupiou.size();
    for (int i = 0; i != limit; i++) {
        if (pioupiou[i].getLifetime() <= 0) {
            pioupiou.erase(std::next(pioupiou.begin(), i));
            i--;
            limit--;
        }
    }
}

void Solarfox::Ennemy::shootNormalPiouPiou() noexcept
{
    int ylimit = 31;
    int xlimit = 39;

    int pX = (y == ylimit) ? -dirX : dirX;
    int pY = (x == xlimit) ? -dirY : dirY;
    pioupiou.emplace_back(Solarfox::PiouPiou(x, y, pY, pX, 28, true, false));
}

void Solarfox::Ennemy::shootSpecialPiouPiou() noexcept
{
    int ylimit = 31;
    int xlimit = 39;

    int pX = (y == ylimit) ? -dirX : 1;
    int pY = (x == xlimit) ? -dirY : 1;
    pioupiou.emplace_back(Solarfox::PiouPiou(x, y, pY, pX, 28, true, true));
}

int Solarfox::Ennemy::checkColPiouPiou(Sprite &other) noexcept
{
    int limit = pioupiou.size();
    for (int i = 0; i != limit; i++)
        if (other.x == pioupiou[i].getSprite().x && other.y == pioupiou[i].getSprite().y) return i;
    return -1;
}

std::vector<Solarfox::PiouPiou> Solarfox::Ennemy::getPioupiou() const noexcept
{
    return pioupiou;
}

void Solarfox::Ennemy::reset() noexcept
{
    int maxX       = startX > endX ? startX : endX;
    int maxY       = startY > endY ? startY : endY;
    x              = startX == endX ? startX : std::rand() % (maxX + 1);
    y              = startY == endY ? startY : std::rand() % (maxY + 1);
    sprite.x       = x;
    sprite.y       = y;
    dirX           = startX == endX ? 0 : 1;
    dirY           = startY == endY ? 0 : 1;
    speed          = 1;
    countdownShoot = std::rand() % 10;
    pioupiou.clear();
}