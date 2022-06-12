/*
** EPITECH PROJECT, 2022
** ModuleUser.hpp
** File description:
** ModuleUser
*/

#include <ncurses.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "../IMonitorModule.hpp"

#ifndef USER_HPP_
#define USER_HPP_

class ModuleUser : public IMonitorModule
{
    private:
        char _hostname[HOST_NAME_MAX];
        char _username[LOGIN_NAME_MAX];

    public:
        ModuleUser(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
        {
            gethostname(_hostname, HOST_NAME_MAX);
            getlogin_r(_username, LOGIN_NAME_MAX);
            _name = "USER";
        }

        void display()
        {
            printTitle((" "+ _name + " (u) ").c_str());
            if (!_isDisplay) {return;}
            printStr("");
            printStr(_hostname);
            printStr(_username);
            printStr("");
            printBottom();
        }

        std::string getContent()
        {
            return  std::string(_hostname) + "\n" +
                    std::string(_username) + "\n";
        }

        ~ModuleUser() {}
};

#endif /* !USER_HPP_ */
