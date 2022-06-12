/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <fstream>
#include <iostream>
#include "SickKoala.hpp"

class KoalaNurse
{
    int id;
    
    public:
        std::string readReport(std::string);
        KoalaNurse(int);
        ~KoalaNurse();
        void giveDrug(std::string, SickKoala *);
        void timeCheck();
        int getID();
};

#endif
