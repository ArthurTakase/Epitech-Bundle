/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** UserInterface
*/

#include "../include/NanoTekSpice.hpp"
#include <iostream>

#ifndef USERINTERFACE_HPP_
#define USERINTERFACE_HPP_

class UserInterface {
public:
    UserInterface();
    ~UserInterface();
    void loop(NanoTekSpice &);
};

#endif /* !USERINTERFACE_HPP_ */
