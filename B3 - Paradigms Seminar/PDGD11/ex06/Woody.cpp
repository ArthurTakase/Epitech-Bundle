/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string newName)
{
    picture.getPictureFromFile("woody.txt");
    type = WOODY;
    name = newName;
    speakBegin = "WOODY: ";
}

Woody::Woody(std::string newName, std::string file)
{
    type = WOODY;
    name = newName;
    picture.getPictureFromFile(file);
    speakBegin = "WOODY: ";
}