/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** ToyStory
*/

#include "ToyStory.hpp"
#include <fstream>

bool action(std::string str,
            Toy toy1, bool (Toy::*func1)(std::string),
            Toy toy2, bool (Toy::*func2)(std::string))
{
    static bool isToy1 = true;

    if (str.find("picture:") == 0)
    {
        if (!(isToy1 ? toy1.setAscii(str.erase(0, 8)) : toy2.setAscii(str.erase(0, 8))))
        {
            std::cout << (isToy1 ? toy1.getLastError().where() : toy2.getLastError().where()) << ": ";
            std::cout << (isToy1 ? toy1.getLastError().what() : toy2.getLastError().what()) << std::endl;
            return false;
        }
        std::cout << (isToy1 ? toy1.getAscii() : toy2.getAscii()) << std::endl;
    }
    else if (isToy1)
    {
        if (!(toy1.*func1)(str))
        {
            std::cout << (isToy1 ? toy1.getLastError().where() : toy2.getLastError().where()) << ": ";
            std::cout << (isToy1 ? toy1.getLastError().what() : toy2.getLastError().what()) << std::endl;
            return false;
        }

        isToy1 = !isToy1;
    }
    else
    {
        (toy2.*func2)(str);
        isToy1 = !isToy1;
    }
    return true;
}

void ToyStory::tellMeAStory(std::string file,
                            Toy toy1, bool (Toy::*func1)(std::string),
                            Toy toy2, bool (Toy::*func2)(std::string))
{
    char c;
    std::string data = "";
    std::ifstream content(file.c_str());

    if (!content.is_open())
    {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    c = content.get();
    for (; content.good(); c = content.get())
    {
        if (c == '\n')
        {
            if (!action(data, toy1, func1, toy2, func2))
                return;
            data = "";
        }
        else
            data.push_back(c);
    }
}