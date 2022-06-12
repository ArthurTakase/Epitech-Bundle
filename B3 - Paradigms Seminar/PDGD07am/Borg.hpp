/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07am-arthur.decaen
** File description:
** Borg
*/

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef BORG_HPP_
#define BORG_HPP_

#include "Federation.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}

namespace Borg
{
    class Ship
    {
    private:
        int _side = 300;
        short _maxWarp = 9;
        WarpSystem::Core *_core;
        Destination _home = UNICOMPLEX;
        Destination _location = _home;
        int _shield = 100;
        int _weaponFrequency = 20;
        short _repair = 3;

    public:
        Ship();
        Ship(int, short);
        ~Ship();
        void setupCore(WarpSystem::Core *);
        void checkCore();
        bool move(int, Destination);
        bool move(int);
        bool move(Destination);
        bool move();
        int getShield();
        void setShield(int);
        int getWeaponFrequency();
        void setWeaponFrequency(int);
        short getRepair();
        void setRepair(short);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    };
}

#endif