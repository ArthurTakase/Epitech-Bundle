/*
** EPITECH PROJECT, 2022
** ModuleComputer.hpp
** File description:
** ModuleComputer
*/

#include <sys/utsname.h>
#include <limits.h>
#include <time.h>
#include "../IMonitorModule.hpp"

#ifndef MODULE_TIME_HPP_
#define MODULE_TIME_HPP_

class ModuleTime : public IMonitorModule
{
private:
    std::string _currentTime;

public:
    ModuleTime(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
    {
        refresh();
        _name = "TIME";
    }

    void display()
    {
        printTitle((" "+ _name + " (t) ").c_str());
        if (!_isDisplay) { return; }
        printStr("");
        printStr(_currentTime.c_str());
        printStr("");
        printBottom();
    }

    void refresh()
    {
        time_t givemetime = time(NULL);
        _currentTime = ctime(&givemetime);
    }

    std::string getContent()
    {
        refresh();
        return _currentTime;
    }

    ~ModuleTime() {}
};

#endif /* !COMPUTER_HPP_ */
