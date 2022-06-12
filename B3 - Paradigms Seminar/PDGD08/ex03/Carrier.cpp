/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** Carrier
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string id) : _id(id) {}

Carrier::Carrier() {}

Carrier::~Carrier()
{
    for (int i = 0; i != 5; i++)
    {
        if (this->_droids[i])
        {
            delete _droids[i];
            _droids[i] = NULL;
        }
    }
}

Carrier &Carrier::operator<<(Droid *droid)
{
    if (this->_nbDroid == 0)
        this->_speed = 100;
    for (int i = 0; i != 5; i++)
    {
        if (this->_droids[i] != NULL && this->_droids[i]->getId() == droid->getId())
            return *this;
        if (this->_droids[i] == NULL)
        {
            this->_droids[i] = droid;
            this->_nbDroid += 1;
            this->_speed -= 10;
            break;
        }
    }
    return *this;
}

Carrier &Carrier::operator<<(size_t &energy)
{
}

Carrier &Carrier::operator>>(Droid *droid)
{
    for (int i = 0; i != 5; i++)
    {
        if (this->_droids[i] != NULL && this->_droids[i]->getId() == droid->getId())
        {
            this->_droids[i] = NULL;
            this->_nbDroid -= 1;
            this->_speed += 10;
            if (_nbDroid == 0)
                this->_speed = 0;
            return *this;
        }
    }
    return *this;
}

Droid *Carrier::operator[](int position) const
{
    return (_droids[position]);
}

void Carrier::setId(std::string id) { _id = id; }

void Carrier::setEnergy(size_t energy) { _energy = energy; }

void Carrier::setSpeed(size_t speed) { _speed = speed; }

std::string Carrier::getId() { return _id; }

size_t Carrier::getEnergy() { return _energy; }

const size_t Carrier::getAttack() { return _attack; }

const size_t Carrier::getToughness() { return _toughness; }

size_t Carrier::getSpeed() { return _speed; }
