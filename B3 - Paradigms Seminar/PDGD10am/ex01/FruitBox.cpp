/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD010am-arthur.decaen
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size) {}
FruitBox::~FruitBox() {}
int FruitBox::nbFruits() const { return _count; }
FruitNode *FruitBox::head() const { return _header; }

bool FruitBox::putFruit(Fruit *fruit)
{
    if (_count >= _size)
        return false;
    FruitNode *current = _header;
    FruitNode *node = new FruitNode();
    node->box = fruit;
    if (!_header)
    {
        _header = node;
        _count++;
        return true;
    }
    while (current->next)
    {
        if (current->box == fruit)
            return false;
        current = current->next;
    }
    current->next = node;
    _count++;
    return true;
}

Fruit *FruitBox::pickFruit()
{
    if (_count)
    {
        Fruit *fruit = _header->box;
        FruitNode *del = _header;
        _header = _header->next;
        delete del;
        _count--;
        return fruit;
    }
    return nullptr;
}
