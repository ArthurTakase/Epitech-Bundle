/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Woody
*/

#include "Toy.hpp"

#ifndef WOODY_HPP_
#define WOODY_HPP_

class Woody : virtual public Toy
{
public:
    Woody(std::string);
    Woody(std::string, std::string);
    ~Woody(){};
};

#endif /* !WOODY_HPP_ */
