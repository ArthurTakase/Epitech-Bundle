/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _nbStrimpacks = stimPaks;
}

Skat::Skat() {}

Skat::~Skat() {}

int &Skat::stimPaks()
{
    return _nbStrimpacks;
}

int &Skat::stimPaks(int number)
{
    _nbStrimpacks = number;
    return _nbStrimpacks;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (_nbStrimpacks < number)
    {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    stock += number;
    _nbStrimpacks -= number;
    std::cout << "Keep the change." << std::endl;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?";
    _nbStrimpacks += number;
}

void Skat::useStimPaks()
{
    if (_nbStrimpacks)
    {
        _nbStrimpacks--;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        return;
    }
    std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _nbStrimpacks << " stimpaks remaining sir!" << std::endl;
}