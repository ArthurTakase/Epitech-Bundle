/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
                              FruitBox &bananas, FruitBox &limes)
{
    FruitBox sorted(unsorted.nbFruits());

    for (FruitNode *temp = unsorted.head(); temp; temp = temp->next)
    {
        if (temp->box->getName() == "lemon")
        {
            if (lemons.putFruit(temp->box))
                sorted.putFruit(temp->box);
        }
        if (temp->box->getName() == "banana")
        {
            if (bananas.putFruit(temp->box))
                sorted.putFruit(temp->box);
        }
        if (temp->box->getName() == "lime")
        {
            if (limes.putFruit(temp->box))
                sorted.putFruit(temp->box);
        }
    }
    unsorted = sorted;
}