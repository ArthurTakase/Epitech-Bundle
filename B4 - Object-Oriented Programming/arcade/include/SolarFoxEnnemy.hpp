/*
** EPITECH PROJECT, 2022
** Ennemy
** File description:
** Ennemy
*/

#include "Elements.hpp"
#include "SolarFoxPiouPiou.hpp"
#include <cstdlib>
#include <vector>

#ifndef SOLARFOXENNEMY_HPP_
#define SOLARFOXENNEMY_HPP_

namespace Solarfox {
class Ennemy {
public:
    Ennemy(int nstartX, int nstartY, int nendX, int nendY, std::string fileSprite);
    Ennemy(const Ennemy &other) = default;
    Ennemy(Ennemy &&other)      = default;
    ~Ennemy();
    Ennemy                         &operator=(const Ennemy &other) = default;
    Ennemy                         &operator=(Ennemy &&other) = default;
    Sprite                          getSprite() const noexcept;
    void                            reverseSpeed() noexcept;
    bool                            atEnd() const noexcept;
    bool                            atStart() const noexcept;
    void                            move() noexcept;
    void                            shoot() noexcept;
    std::vector<Solarfox::PiouPiou> getPioupiou() const noexcept;
    int                             checkColPiouPiou(Sprite &other) noexcept;
    void                            reset() noexcept;

private:
    void manageLifePiouPiou() noexcept;
    void shootNormalPiouPiou() noexcept;
    void shootSpecialPiouPiou() noexcept;

private:
    int                             x;
    int                             y;
    int                             startX;
    int                             startY;
    int                             endX;
    int                             endY;
    int                             dirX;
    int                             dirY;
    int                             speed;
    int                             countdownShoot;
    Sprite                          sprite;
    std::vector<Solarfox::PiouPiou> pioupiou;
};
} // namespace Solarfox

#endif /* !SOLARFOXENNEMY_HPP_ */
