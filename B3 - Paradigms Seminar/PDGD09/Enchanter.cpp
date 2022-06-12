/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Enchanter
*/

#include "Enchanter.hpp"

Enchanter::Enchanter(std::string const &name, int power) : Peasant(name, power)
{
    std::cout << _name << " learns magic from his spellbook." << std::endl;
}

Enchanter::~Enchanter()
{
    std::cout << _name << " closes his spellbook." << std::endl;
}

int Enchanter::attack()
{
    if (!checkTechnique(0))
    {
        return 0;
    }
    std::cout << _name << " doesn't know how to fight." << std::endl;
    return 0;
}

int Enchanter::special()
{
    if (!checkTechnique(50))
    {
        return 0;
    }
    _power -= 50;
    std::cout << _name << " casts a fireball." << std::endl;
    return 99;
}

void Enchanter::rest()
{
    if (checkTechnique(0))
    {
        _power = 100;
        std::cout << _name << " meditates." << std::endl;
    }
}