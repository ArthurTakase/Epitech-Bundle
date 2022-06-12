/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** IMonitorDisplay
*/

#include "Modules/ModuleUser.hpp"
#include "Modules/ModuleComputer.hpp"
#include "Modules/ModuleTime.hpp"
#include "Modules/ModuleCpu.hpp"
#include "Modules/ModuleRam.hpp"
#include "Modules/ModuleNetwork.hpp"

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
    protected:
        bool            _rainbow = false;
        ModuleUser      *_user;
        ModuleComputer  *_computer;
        ModuleTime      *_time;
        ModuleCpu       *_cpu;
        ModuleRam       *_ram;
        ModuleNetwork   *_network;

    public:
        IMonitorDisplay(int ac, char **av) 
        {
            checkHelp(ac, av);
        }
        
        int help()
        {
            std::cout << "HELP" << std::endl;
            std::cout << "./MyGkrellm [options] (by default show all)" << std::endl;
            std::cout << "__SFML__" << std::endl;
            std::cout << "\t-g\t\tLaunch in graphical Mode" << std::endl;
            std::cout << "__NCURSES__" << std::endl;
            std::cout << "\t-t\t\tShow Time" << std::endl;
            std::cout << "\t-c\t\tShow Computer" << std::endl;
            std::cout << "\t-p\t\tShow Processor" << std::endl;
            std::cout << "\t-u\t\tShow User" << std::endl;
            std::cout << "\t-r\t\tShow Ram" << std::endl;
            std::cout << "\t-n\t\tShow Network" << std::endl;
            std::cout << "\t--rainbow\trainbow ☆*: .｡. o(≧▽≦)o .｡.:*☆" << std::endl;
            std::cout << "\t--color\t\tAdd color to modules" << std::endl;
            return 0;
        }

        void checkHelp(int ac, char **av) 
        {
            if (ac < 1) return;
            for (int i = 1; i < ac; i++)
                if (!strcmp(av[i], "-h") || !strcmp(av[i], "--help")) { exit(help()); }
        }
        
        ~IMonitorDisplay() {}
        bool display() {return true;}
        void refreshData() {}
        bool getUserEntry() {return true;}
        int  setRainbow() { _rainbow = !_rainbow; return 0; };
};

#endif /* !IMONITORDISPLAY_HPP_ */
