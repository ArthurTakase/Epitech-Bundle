/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** FruitBox
*/

#include "Fruit.hpp"
#include "FruitNode.hpp"

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

class FruitBox
{
    int _size;
    FruitNode *_header = nullptr;
    int _count = 0;

public:
    FruitBox(int);
    ~FruitBox();
    int nbFruits() const;
    bool putFruit(Fruit *);
    Fruit *pickFruit();
    FruitNode *head() const;
};

#endif /* !FRUITBOX_HPP_ */
