/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** LittleHand
*/

#include <cmath>
#include "LittleHand.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
                              FruitBox &bananas, FruitBox &limes)
{
    FruitBox sorted(unsorted.nbFruit());

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

FruitBox *const *LittleHand::organizeCoconut(Coconut const *const *coconuts)
{
    int i = 0;
    int current = 0;

    for (; coconuts[i] != nullptr; i++)
        ;
    int nbBox = ceil(i / 6.0);
    FruitBox **arrayBox = new FruitBox *[nbBox];
    for (int j = 0; j != i; j++)
    {
        arrayBox[current] = new FruitBox(6);
        if (!arrayBox[current]->putFruit(new Coconut))
        {
            current++;
            arrayBox[current]->putFruit(new Coconut);
        }
    }
    return arrayBox;
}