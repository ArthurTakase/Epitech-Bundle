/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** ToyStory
*/

#include "Toy.hpp"

#ifndef TOYSTORY_HPP_
#define TOYSTORY_HPP_

class ToyStory
{
public:
    ToyStory(){};
    ~ToyStory(){};
    void static tellMeAStory(std::string file,
                             Toy toy1, bool (Toy::*func1)(std::string),
                             Toy toy2, bool (Toy::*func2)(std::string));
};

#endif /* !TOYSTORY_HPP_ */