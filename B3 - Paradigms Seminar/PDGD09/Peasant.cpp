/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD09-arthur.decaen
** File description:
** Peasant
*/

#include "Peasant.hpp"

Peasant::Peasant(std::string const &name, int power) : _name(name), _power(power)
{
    std::cout << _name << " goes for an adventure." << std::endl;
}

Peasant::~Peasant()
{
    std::cout << _name << " is back to his crops." << std::endl;
}

void Peasant::setPower(int power) { _power = power; }
void Peasant::setHp(int health) { _health = health; }
const std::string &Peasant::getName() const { return _name; }
int Peasant::getPower() const { return _power; }
int Peasant::getHp() const { return _health; }

int Peasant::checkTechnique(int cost)
{
    if (this->_health <= 0)
    {
        std::cout << this->_name << " is out of combat." << std::endl;
        return false;
    }
    if (this->_power - cost < 0)
    {
        std::cout << this->_name << " is out of power." << std::endl;
        return false;
    }
    return true;
}

int Peasant::attack()
{
    if (!checkTechnique(10))
    {
        return 0;
    }
    _power -= 10;
    std::cout << _name << " tosses a stone." << std::endl;
    return 5;
}

int Peasant::special()
{
    if (!checkTechnique(0))
    {
        return 0;
    }
    std::cout << _name << " doesn't know any special move." << std::endl;
    return 0;
}

void Peasant::rest()
{
    if (checkTechnique(0))
    {
        if ((_power += 30) > 100)
            _power = 100;
        std::cout << _name << " takes a nap." << std::endl;
    }
}

void Peasant::damage(int damage)
{
    _health -= damage;
    if (_health <= 0)
    {
        std::cout << _name << " is out of combat." << std::endl;
        _health = 0;
    }
    else
        std::cout << _name << " takes " << damage << " damage." << std::endl;
}

void Peasant::drinkPotion(int health, int power, std::string str)
{
    if ((_health += health) > 100)
        _health = 100;
    if ((_power += power) > 100)
        _power = 100;
    std::cout << _name << str << std::endl;
}

void Peasant::drink(const IPotion &potion) { drinkPotion(potion.getHp(), potion.getPower(), " drinks a mysterious potion."); }
void Peasant::drink(const HealthPotion &potion) { drinkPotion(potion.getHp(), potion.getPower(), potion.getStr()); }
void Peasant::drink(const PowerPotion &potion) { drinkPotion(potion.getHp(), potion.getPower(), potion.getStr()); }
void Peasant::drink(const PoisonPotion &potion) { drinkPotion(potion.getHp(), potion.getPower(), potion.getStr()); }