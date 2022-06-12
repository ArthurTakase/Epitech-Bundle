/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** FruitNode
*/

#include "Fruit.hpp"

#ifndef FRUITNODE_HPP_
#define FRUITNODE_HPP_

class FruitNode
{
public:
    FruitNode *next;
    Fruit *box;

public:
    FruitNode(){};
    ~FruitNode(){};
};

#endif /* !FRUITNODE_HPP_ */