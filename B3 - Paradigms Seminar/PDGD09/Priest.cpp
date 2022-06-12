/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Priest
*/

#include "Priest.hpp"

Priest::Priest(std::string const &name, int power) : Peasant(name, power), Enchanter(name, power)
{
    std::cout << _name << " enters in the order." << std::endl;
}

Priest::~Priest()
{
    std::cout << _name << " finds peace." << std::endl;
}

void Priest::rest()
{
    if (checkTechnique(0))
    {
        _power = 100;
        _health = 100;
        std::cout << _name << " prays." << std::endl;
    }
}