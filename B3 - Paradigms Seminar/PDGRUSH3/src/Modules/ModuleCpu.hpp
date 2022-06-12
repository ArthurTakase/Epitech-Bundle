/*
** EPITECH PROJECT, 2022
** ModuleComputer.hpp
** File description:
** ModuleComputer
*/

#include <fstream>
#include <iostream>
#include <type_traits>
#include "../IMonitorModule.hpp"

#ifndef MODULE_CPU_HPP_
#define MODULE_CPU_HPP_


class ModuleCpu : public IMonitorModule
{
    private:
        std::string _data[5];

    public: 
        ModuleCpu(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
        {
            _name = "CPU";
            fillData();
        }

        void fillData()
        {
            std::string cpy;
            std::ifstream ifs("/proc/cpuinfo");
            std::string names[5] = {"model name", "cpu MHz",  "stepping", "vendor_id", "sibling"};
            int nb_get = 0;

            if (!ifs.is_open()) return;
            while (getline(ifs, cpy, '\n') && nb_get != 5) {
                for (int i = 0; i < 5; i++)
                    if (!cpy.find(names[i])) {
                        _data[nb_get] = removeTab(cpy);
                        nb_get++;
                    }
            }
        }

        void display()
        {
            printTitle((" "+ _name + " (p)  ").c_str());
            if (!_isDisplay) {return;}
            printStr("");
            printStr(_data[0].c_str());
            printStr(_data[1].c_str());
            printStr(_data[2].c_str());
            printStr(_data[3].c_str());
            printStr(_data[4].c_str());
            printStr("");
            printBottom();
        }

        std::string removeTab(std::string cpy)
        {
            size_t pos = 0;

            while (pos != -1) {
                pos = cpy.find("\t", pos);
                if (pos != -1)
                    cpy = cpy.replace(pos, 1, " ");
            }
            return cpy;
        }

        std::string getContent()
        {
            return  _data[0] + "\n" +
                    _data[1] + "\n" +
                    _data[2] + "\n" +
                    _data[3] + "\n" +
                    _data[4] + "\n";
        }

        ~ModuleCpu() {}
        void refresh() {}
};

#endif /* !COMPUTER_HPP_ */
