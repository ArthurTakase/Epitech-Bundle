/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** IPotion
*/

#include <iostream>

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

class IPotion
{
protected:
    int _health;
    int _power;
    std::string _str;

public:
    virtual ~IPotion() = default;
    int getHp() const { return _health; }
    int getPower() const { return _power; }
    std::string getStr() const { return _str; }
};

#endif /* !IPOTION_HPP_ */
