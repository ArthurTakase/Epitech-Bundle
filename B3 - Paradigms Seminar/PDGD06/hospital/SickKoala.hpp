/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <iostream>

class SickKoala
{
    std::string name;
    
    public:
        SickKoala(std::string);
        ~SickKoala();
        void poke();
        bool takeDrug(std::string);
        void overDrive(std::string);
        std::string getName();
};

#endif
