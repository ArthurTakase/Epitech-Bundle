/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
    std::string name;

    public:
        KoalaDoctor(std::string);
        ~KoalaDoctor();
        void diagnose(SickKoala *);
        void timeCheck();
        std::string getName();
};

#endif /* !KOALADOCTOR_HPP_ */
