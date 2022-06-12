/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** LittleHand
*/

#include "FruitBox.hpp"
#include "Coconut.hpp"

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

class LittleHand
{
public:
    LittleHand(){};
    ~LittleHand(){};
    void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
    FruitBox *const *organizeCoconut(Coconut const *const *);

protected:
private:
};

#endif /* !LITTLEHAND_HPP_ */
