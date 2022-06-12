/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <iostream>

bool Picture::getPictureFromFile(const std::string &file)
{
    char c;
    std::ifstream content(file.c_str());

    if (content.is_open())
    {
        c = content.get();
        for (; content.good(); c = content.get())
            data.push_back(c);
        return true;
    }
    data = "ERROR";
    return false;
}

Picture::Picture() : data("") {}
Picture::Picture(const std::string &file) { getPictureFromFile(file); }
Picture::Picture(Picture const &other) : data(other.data) {}
Picture::~Picture() {}

Picture &Picture::operator=(Picture const &other)
{
    data = other.data;
    return *this;
}