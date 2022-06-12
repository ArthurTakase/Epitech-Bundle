/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** Parts
*/

#include <iostream>

#ifndef PARTS_HPP_
#define PARTS_HPP_

class Arms
{
    std::string _serial = "A-01";
    bool _functional = true;

public:
    Arms();
    Arms(std::string, bool);
    ~Arms();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};

class Legs
{
    std::string _serial = "L-01";
    bool _functional = true;

public:
    Legs();
    Legs(std::string, bool);
    ~Legs();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};

class Head
{
    std::string _serial = "H-01";
    bool _functional = true;

public:
    Head();
    Head(std::string, bool);
    ~Head();
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};

#endif
