/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** ICharacter
*/

#include <iostream>
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"
#include "HealthPotion.hpp"
#include "IPotion.hpp"

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

class ICharacter
{
public:
    virtual ~ICharacter() = default;
    virtual void setPower(int) = 0;
    virtual const std::string &getName() const = 0;
    virtual int getPower() const = 0;
    virtual int getHp() const = 0;
    virtual int attack() = 0;
    virtual int special() = 0;
    virtual void rest() = 0;
    virtual int checkTechnique(int) = 0;
    virtual void damage(int) = 0;
    virtual void drinkPotion(int, int, std::string) = 0;
    virtual void drink(const IPotion &) = 0;
    virtual void drink(const HealthPotion &) = 0;
    virtual void drink(const PowerPotion &) = 0;
    virtual void drink(const PoisonPotion &) = 0;
};

#endif /* !ICHARACTER_HPP_ */
