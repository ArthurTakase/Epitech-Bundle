/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string newName) : Toy()
{
    type = BUZZ;
    name = newName;
    picture.getPictureFromFile("buzz.txt");
}

Buzz::Buzz(std::string newName, std::string file) : Toy()
{
    type = BUZZ;
    name = newName;
    picture.getPictureFromFile(file);
}