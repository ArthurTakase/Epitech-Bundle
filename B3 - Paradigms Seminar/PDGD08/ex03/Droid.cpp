/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) : _id(serial)
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &other) : _id(other._id), _energy(50),
                                   _attack(other._attack), _toughness(other._toughness),
                                   _status(new std::string(*(other._status)))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

void Droid::setId(std::string id) { _id = id; }

void Droid::setEnergy(size_t energy) { _energy = energy; }

void Droid::setStatus(std::string *status) { _status = status; }

std::string Droid::getId() const { return _id; }

size_t Droid::getEnergy() const { return _energy; }

size_t Droid::getAttack() const { return _attack; }

size_t Droid::getToughness() const { return _toughness; }

std::string *Droid::getStatus() const { return _status; }

Droid &Droid::operator=(Droid const &other)
{
    this->_id = other._id;
    this->_energy = 50;
    _status = new std::string(*(other._status));
    return *this;
}

bool Droid::operator==(Droid const &other) const
{
    return this->_status->compare(*other._status) == 0;
}

bool Droid::operator!=(Droid const &other) const
{
    return !(*this == other);
}

Droid &Droid::operator<<(size_t &energy)
{
    if (this->_energy + energy >= 100)
    {
        energy -= (100 - _energy);
        this->_energy = 100;
    }
    else
    {
        this->_energy += energy;
        energy = 0;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Droid const &k)
{
    os << "Droid '" << k.getId() << "', " << *k.getStatus() << ", " << k.getEnergy();
    return os;
}

bool Droid::operator()(const std::string *task, size_t need_exp)
{
    this->_energy -= 10;
    if (this->_energy < 10)
    {
        this->_status = new std::string("Battery Low");
        this->_energy = 0;
        return false;
    }
    if (this->_memory.getExp() >= need_exp)
    {
        this->_status = new std::string(*task + " - Completed!");
        this->_memory.setExp(this->_memory.getExp() + (need_exp / 2));
        return true;
    }
    else
    {
        this->_status = new std::string(*task + " - Failed");
        this->_memory.setExp(this->_memory.getExp() + need_exp);
        return false;
    }
}