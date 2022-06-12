/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Priest
*/

#include <iostream>
#include "Enchanter.hpp"

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

class Priest : virtual public Enchanter
{
public:
    Priest(std::string const &, int);
    ~Priest();
    void rest();
};

#endif /* !PRIEST_HPP_ */
