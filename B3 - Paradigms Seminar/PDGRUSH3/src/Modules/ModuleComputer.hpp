/*
** EPITECH PROJECT, 2022
** ModuleComputer.hpp
** File description:
** ModuleComputer
*/

#include <sys/utsname.h>
#include <limits.h>
#include "../IMonitorModule.hpp"

#ifndef MODULE_COMPUTER_HPP_
#define MODULE_COMPUTER_HPP_

class ModuleComputer : public IMonitorModule
{
public:
    std::string _sysname;
    std::string _release;

public:
    ModuleComputer(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
    {
        struct utsname unameData;

        uname(&unameData);
        _sysname = unameData.sysname;
        _release = unameData.release;
        _name = "COMPUTER";
    }

    void display()
    {
        printTitle((" "+ _name + " (c) ").c_str());
        if (!_isDisplay)
        {
            return;
        }
        printStr("");
        printStr(_sysname.c_str());
        printStr(_release.c_str());
        printStr("");
        printBottom();
    }

    std::string getContent() { return _sysname + "\n" + _release; }

    ~ModuleComputer() {}
};

#endif /* !COMPUTER_HPP_ */
