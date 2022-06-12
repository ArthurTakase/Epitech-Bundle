/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Enchanter
*/

#include <iostream>
#include "Peasant.hpp"

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

class Enchanter : virtual public Peasant
{
public:
    Enchanter(std::string const &, int);
    ~Enchanter();
    int attack();
    int special();
    void rest();
};

#endif /* !ENCHANTER_HPP_ */
