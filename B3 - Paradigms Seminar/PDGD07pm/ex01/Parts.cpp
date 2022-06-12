/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** Parts
*/

#include "Parts.hpp"

// ----------------- ARMS ------------------

Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Arms::Arms() {}

Arms::~Arms() {}

bool Arms::isFunctional() const { return _functional; }

std::string Arms::serial() const { return _serial; }

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : ";
    std::cout << (_functional ? "OK" : "KO") << std::endl;
}

// ----------------- LEGS ------------------

Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Legs::Legs() {}

Legs::~Legs() {}

bool Legs::isFunctional() const { return _functional; }

std::string Legs::serial() const { return _serial; }

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : ";
    std::cout << (_functional ? "OK" : "KO") << std::endl;
}

// ----------------- HEAD ------------------

Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Head::Head() {}

Head::~Head() {}

bool Head::isFunctional() const { return _functional; }

std::string Head::serial() const { return _serial; }

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : ";
    std::cout << (_functional ? "OK" : "KO") << std::endl;
}