/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Peasant
*/

#include <iostream>
#include "ICharacter.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"
#include "HealthPotion.hpp"
#include "IPotion.hpp"

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

class Peasant : public ICharacter
{
protected:
    const std::string _name;
    int _power;
    int _health = 100;

public:
    Peasant(const std::string &, int);
    ~Peasant();
    void setPower(int);
    void setHp(int);
    const std::string &getName() const;
    int getPower() const;
    int getHp() const;
    int attack();
    int special();
    void rest();
    int checkTechnique(int);
    void damage(int);
    void drinkPotion(int, int, std::string);
    void drink(const IPotion &);
    void drink(const HealthPotion &);
    void drink(const PowerPotion &);
    void drink(const PoisonPotion &);
};

#endif /* !PEASANT_HPP_ */
