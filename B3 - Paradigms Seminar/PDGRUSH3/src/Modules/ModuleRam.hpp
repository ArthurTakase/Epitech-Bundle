/*
** EPITECH PROJECT, 2022
** ModuleComputer.hpp
** File description:
** ModuleComputer
*/

#include <sys/utsname.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <unistd.h>
#include <math.h>
#include <sys/sysinfo.h>
#include "../IMonitorModule.hpp"

#ifndef MODULE_RAM_HPP_
#define MODULE_RAM_HPP_

class ModuleRam : public IMonitorModule
{
private:
    std::string totalMemory;
    std::string availableMemory;
    std::string useMemory;
    std::string useMemoryInPercent;

public:
    ModuleRam(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
    {
        refresh();
        _name = "RAM";    
    }

    void display()
    {
        printTitle((" "+ _name + " (r)  ").c_str());
        if (!_isDisplay) { return; }
        printStr("");
        printStr(totalMemory.c_str());
        printStr(availableMemory.c_str());
        printStr(useMemory.c_str());
        printStr("");
        printBottom();
    }

    void refresh()
    {
        struct sysinfo i;
        sysinfo(&i);
        totalMemory = "Total: " + std::to_string(i.totalram / pow(1024, 3)).substr(0, 5) + " Gb";
        availableMemory = "Available: " + std::to_string(i.freeram / pow(1024, 3)).substr(0, 5) + " Gb (";
        availableMemory += std::to_string(((i.freeram * 100) / i.totalram)).substr(0, 5) + " %%)";
        useMemory = "Used: " + std::to_string((i.totalram - i.freeram) / pow(1024, 3)).substr(0, 5) + " Gb";
    }

    std::string getContent()
    {
        refresh();
        return  totalMemory + "\n" +
                availableMemory + "\n" +
                useMemory + "\n" +
                useMemoryInPercent + "\n";
    }
    
    ~ModuleRam() {}
};

#endif /* !COMPUTER_HPP_ */
