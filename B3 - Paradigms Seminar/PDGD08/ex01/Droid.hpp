/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** Droid
*/

#include <iostream>
#include "DroidMemory.hpp"

#ifndef DROID_HPP_
#define DROID_HPP_

class Droid
{
    std::string _id = "";
    size_t _energy = 50;
    const size_t _attack = 25;
    const size_t _toughness = 15;
    std::string *_status = new std::string("Standing by");
    DroidMemory _memory;

public:
    Droid(std::string);
    Droid(Droid const &);
    ~Droid();
    void setId(std::string);
    void setEnergy(size_t);
    void setStatus(std::string *);
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack() const;
    size_t getToughness() const;
    std::string *getStatus() const;
    bool operator==(Droid const &) const;
    bool operator!=(Droid const &) const;
    Droid &operator<<(size_t &);
    Droid &operator=(Droid const &);
};

std::ostream &operator<<(std::ostream &, Droid const &);

#endif
