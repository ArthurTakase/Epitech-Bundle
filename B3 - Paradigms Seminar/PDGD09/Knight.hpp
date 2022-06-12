/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Knight
*/

#include "Peasant.hpp"

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

class Knight : virtual public Peasant
{
public:
    Knight(std::string const &, int);
    ~Knight();
    int attack();
    int special();
    void rest();
};

#endif /* !KNIGHT_HPP_ */
