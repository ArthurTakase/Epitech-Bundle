/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** UserInterface
*/

#include "../include/UserInterface.hpp"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void simulate_func(NanoTekSpice &nano)
{
    nano.simulateAll();
}

void display_func(NanoTekSpice &nano)
{
    nano.displayAll();
}

void dump_func(NanoTekSpice &nano)
{
    nano.dumpAll();
}

void loop_func(NanoTekSpice &nano)
{
    nano.loop();
}

void setValue_func(std::string &cmd, NanoTekSpice &nano)
{
    std::vector<std::string> split;

    splitStr(cmd, "=", &split);
    if (split.size() < 2 || (split[1] != "1" && split[1] != "U" && split[1] != "0")) return;
    std::array<std::string, 2> arr = { split[0], split[1] };
    nano.pushAssignation(arr);
}

void UserInterface::loop(NanoTekSpice &nano)
{
    std::string                                     cmd;
    std::map<std::string, void (*)(NanoTekSpice &)> my_map = { { "simulate", &simulate_func },
                                                               { "display", &display_func },
                                                               { "loop", &loop_func },
                                                               { "dump", &dump_func } };

    nano.simulateAll();
    do {
        std::cout << "> ";
        std::getline(std::cin, cmd);

        if (std::cin.fail() || std::cin.eof()) break;

        if (my_map[cmd]) my_map[cmd](nano);
        else if (cmd.find("=") != std::string::npos)
            setValue_func(cmd, nano);
    } while (cmd != "exit");
}
