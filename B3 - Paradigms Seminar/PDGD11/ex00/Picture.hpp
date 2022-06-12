/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Picture
*/

#include <iostream>

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

class Picture
{
public:
    std::string data;

public:
    Picture();
    Picture(const std ::string &);
    ~Picture();
    bool getPictureFromFile(const std::string &);
};

#endif /* !PICTURE_HPP_ */
