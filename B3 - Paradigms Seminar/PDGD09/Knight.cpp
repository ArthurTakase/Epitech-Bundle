/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Knight
*/

#include "Knight.hpp"

Knight::Knight(std::string const &name, int power) : Peasant(name, power)
{
    std::cout << _name << " vows to protect the kingdom." << std::endl;
}

Knight::~Knight()
{
    std::cout << _name << " takes off his armor." << std::endl;
}

int Knight::attack()
{
    if (!checkTechnique(10))
    {
        return 0;
    }
    _power -= 10;
    std::cout << _name << " strikes with his sword." << std::endl;
    return 20;
}

int Knight::special()
{
    if (!checkTechnique(30))
    {
        return 0;
    }
    _power -= 30;
    std::cout << _name << " impales his enemy." << std::endl;
    return 50;
}

void Knight::rest()
{
    if (checkTechnique(0))
    {
        if ((_power += 50) > 100)
            _power = 100;
        std::cout << _name << " eats." << std::endl;
    }
}