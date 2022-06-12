/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug == "Mars") {
        std::cout << "Mr." << this->name << ": Mars, and it kreogs!" << std::endl;
        return true;
    }
    if (drug == "Kinder") {
        std::cout << "Mr." << this->name << ": There is a toy inside!" << std::endl;
        return true;
    }
    std::cout << "Mr." << this->name << ": Goerkreog!" << std::endl;
    return false;
}

void SickKoala::overDrive(std::string str)
{
    while (str.find("Kreog!") != std::string::npos)
        str.replace(str.find("Kreog!"), 6, "1337!");
    std::cout << "Mr." << this->name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
    return this->name;
}
