/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main
*/

// #include "../include/NanoTekSpice.hpp"
#include "../include/Parser.hpp"
#include "../include/UserInterface.hpp"
#include <signal.h>

void siginthandler(int param)
{
    (void)param;
    exit(0);
}

int main(int argc, char **argv)
{
    Parser        parser;
    UserInterface interface;
    NanoTekSpice  nano;

    signal(SIGINT, siginthandler);

    if (argc != 2) { return 84; }

    try {
        parser.getDataFromFile(std::string(argv[1]));
        parser.parseInto(nano.getComponents());
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 0;
    }

    try {
        interface.loop(nano);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }

    return 0;
}
