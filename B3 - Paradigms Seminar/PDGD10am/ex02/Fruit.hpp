/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** Fruit
*/

#include <iostream>

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

class Fruit
{
public:
    Fruit();
    ~Fruit();
    int getVitamins() const { return _vitamins; };
    std::string getName() const { return _name; };

protected:
    std::string _name;
    int _vitamins;
};

#endif /* !FRUIT_HPP_ */
