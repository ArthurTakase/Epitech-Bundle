/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Paladin
*/

#include <iostream>
#include "Peasant.hpp"
#include "Knight.hpp"
#include "Enchanter.hpp"
#include "Priest.hpp"

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

class Paladin : virtual public Knight, virtual public Priest
{
public:
    Paladin(std::string const &, int);
    ~Paladin();
    int attack();
    int special();
    void rest();
};

#endif /* !PALADIN_HPP_ */
