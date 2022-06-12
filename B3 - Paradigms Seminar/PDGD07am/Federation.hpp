/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07am-arthur.decaen
** File description:
** Federation
*/

#include <string>
#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include "Borg.hpp"

namespace Borg
{
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain
        {
        private:
            std::string _name;
            int _age;

        public:
            Captain(std::string);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int);
        };

        class Ship
        {
        private:
            int _length = 289;
            int _width = 132;
            std::string _name = "Enterprise";
            short _maxWarp = 6;
            WarpSystem::Core *_core;
            Federation::Starfleet::Captain *_captain;
            Destination _home = EARTH;
            Destination _location = _home;
            int _shield;
            int _photonTorpedo = 0;

        public:
            Ship();
            Ship(int, int, std::string, short);
            Ship(int, int, std::string, short, int);
            ~Ship();
            void setupCore(WarpSystem::Core *);
            void checkCore();
            void promote(Federation::Starfleet::Captain *);
            bool move(int, Destination);
            bool move(int);
            bool move(Destination);
            bool move();
            int getShield();
            void setShield(int);
            int getTorpedo();
            void setTorpedo(int);
            void fire(Borg::Ship *);
            void fire(int, Borg::Ship *);
        };

        class Ensign
        {
        private:
            std::string _name;

        public:
            Ensign(std::string);
            ~Ensign();
        };
    }
    class Ship
    {
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home = VULCAN;
        Destination _location = _home;

    public:
        Ship(int, int, std::string);
        ~Ship();
        void setupCore(WarpSystem::Core *);
        WarpSystem::Core *getCore();
        void checkCore();
        bool move(int, Destination);
        bool move(int);
        bool move(Destination);
        bool move();
    };
}

#endif
