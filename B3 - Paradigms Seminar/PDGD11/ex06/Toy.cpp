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

bool Toy::speak(std::string statement)
{
    if (this->type == BUZZ)
        speakBegin = "BUZZ: ";
    if (this->type == WOODY)
        speakBegin = "WOODY: ";
    std::cout << speakBegin << name << " \"" << statement << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(std::string statement)
{
    if (type == BUZZ)
    {
        std::cout << "BUZZ: " << name << " senorita \"" << statement << "\" senorita" << std::endl;
        return true;
    }
    delete error;
    error = new Error("wrong mode", "speak_es", Error::SPEAK);
    return false;
}

Toy &Toy::operator<<(std::string data)
{
    picture.data = data;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Toy &toy)
{
    stream << toy.getName() << std::endl
           << toy.getAscii() << std::endl;
    return stream;
}

bool Toy::setAscii(std::string file)
{
    picture.data = "";
    if (picture.getPictureFromFile(file))
        return true;
    delete error;
    error = new Error("bad new illustration", "setAscii", Error::PICTURE);
    return false;
}