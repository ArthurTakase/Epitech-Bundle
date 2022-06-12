/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** Skat
*/

#include <iostream>

#ifndef SKAT_HPP_
#define SKAT_HPP_

class Skat
{
    int _nbStrimpacks = 15;
    std::string _name = "bob";

public:
    Skat(const std::string &name, int stimPaks);
    Skat();
    ~Skat();
    int &stimPaks();
    int &stimPaks(int);
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();
};

#endif /* !SKAT_HPP_ */
