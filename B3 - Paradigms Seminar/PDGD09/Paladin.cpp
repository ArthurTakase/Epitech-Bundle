/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Paladin
*/

#include "Paladin.hpp"

Paladin::Paladin(std::string const &name, int power) : Peasant(name, power), Knight(name, power), Enchanter(name, power), Priest(name, power)
{
    std::cout << _name << " fights for the light." << std::endl;
}

Paladin::~Paladin()
{
    std::cout << _name << " is blessed." << std::endl;
}

int Paladin::attack()
{
    return (Knight::attack());
}

int Paladin::special()
{
    return (Enchanter::special());
}

void Paladin::rest()
{
    Priest::rest();
}
