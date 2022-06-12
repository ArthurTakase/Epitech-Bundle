/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Buzz
*/

#include "Toy.hpp"

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

class Buzz : public Toy
{
public:
    Buzz(std::string);
    Buzz(std::string, std::string);
    ~Buzz() {}
};

#endif /* !BUZZ_HPP_ */