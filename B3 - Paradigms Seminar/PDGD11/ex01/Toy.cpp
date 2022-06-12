/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType newType, std::string newName, std::string file)
{
    picture.getPictureFromFile(file);
    type = newType;
    name = newName;
}

Toy &Toy::operator=(Toy const &other)
{
    type = other.getType();
    name = other.getName();
    picture = other.picture;
    return *this;
}

Toy::Toy(Toy const &other) : type(other.getType()), name(other.getName()), picture(other.picture) {}