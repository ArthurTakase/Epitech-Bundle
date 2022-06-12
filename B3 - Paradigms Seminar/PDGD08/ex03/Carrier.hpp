/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** Carrier
*/

#include <iostream>
#include "Droid.hpp"

#ifndef CARRIER_HPP_
#define CARRIER_HPP_

class Carrier
{
    std::string _id = "";
    size_t _energy = 300;
    const size_t _attack = 100;
    const size_t _toughness = 90;
    size_t _speed = 0;
    Droid *_droids[5] = {NULL, NULL, NULL, NULL, NULL};
    int _nbDroid = 0;

public:
    Carrier(std::string);
    Carrier();
    ~Carrier();
    void setId(std::string);
    void setEnergy(size_t);
    void setSpeed(size_t);
    std::string getId();
    size_t getEnergy();
    const size_t getAttack();
    const size_t getToughness();
    size_t getSpeed();
    Carrier &operator<<(Droid *);
    Carrier &operator<<(size_t &);
    Carrier &operator>>(Droid *);
    Droid *operator[](int) const;
};

#endif /* !CARRIER_HPP_ */
