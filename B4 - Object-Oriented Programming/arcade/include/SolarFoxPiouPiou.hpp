/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SolarFoxPiouPiou
*/

#ifndef SOLARFOXPIOUPIOU_HPP_
#define SOLARFOXPIOUPIOU_HPP_

#include "Elements.hpp"

namespace Solarfox {
class PiouPiou {
public:
    PiouPiou(int x, int y, int xdir, int ydir, unsigned int lifetime, bool ennemy, bool special);
    PiouPiou(const PiouPiou &other) = default;
    PiouPiou(PiouPiou &&other)      = default;
    ~PiouPiou();
    PiouPiou &operator=(const PiouPiou &other) = default;
    PiouPiou &operator=(PiouPiou &&other) = default;
    void      move();
    Sprite    getSprite() const noexcept;
    int       getLifetime() const noexcept;
    void      setLifetime(int life) noexcept;

private:
    int          x;
    int          y;
    int          xdir;
    int          ydir;
    unsigned int lifetime;
    Sprite       sprite;
};

} // namespace Solarfox

#endif /* !SOLARFOXPIOUPIOU_HPP_ */
