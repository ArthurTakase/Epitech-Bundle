/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** arcade
*/

#include "Core.hpp"
#include <signal.h>
#include <unistd.h>
// #include <stdlib.h>
#include <execinfo.h>
#include <stdio.h>

/**
 * @brief Affiche les informations d'un segfault.
 * DEBUG ONLY
 *
 * @param sig
 */
void handler(int sig)
{
    void  *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

/**
 * @brief Création d'un nouveau Core et lancement de l'Arcade
 *
 * @param argc Nombre d'arguments
 * @param argv Liste des arguments
 * @return int Retour du programme
 */
int main(int argc, char **argv)
{
    // signal(SIGSEGV, handler);

    if (argc != 2) {
        std::cerr << CYN << "Arcade 🕹" << NC << std::endl;
        std::cerr << "\tL'Arcade permet de lancer de nombreux jeux à travers de nombreuses ";
        std::cerr << "librairies graphiques, et ce en temp réel !" << std::endl;
        std::cerr << CYN << "Utitlisation 🔍" << NC << std::endl;
        std::cerr << "\t./arcade [librairie par défaut]" << std::endl;
        std::cerr << CYN << "Inclus par défaut 📂" << NC << std::endl;
        std::cerr << "\tlib/arcade_ncurses.so " << GRN << "(LIB)" << NC << std::endl;
        std::cerr << "\tlib/arcade_sdl2.so " << GRN << "(LIB)" << NC << std::endl;
        std::cerr << "\tlib/arcade_sfml.so " << GRN << "(LIB)" << NC << std::endl;
        std::cerr << "\tlib/arcade_nibbler.so " << RED << "(GAME)" << NC << std::endl;
        std::cerr << "\tlib/arcade_solarfox.so " << RED << "(GAME)" << NC << std::endl;
        return 84;
    }

    std::srand(std::time(nullptr));

    std::string           arg(argv[1]);
    std::unique_ptr<Core> my_core = std::make_unique<Core>("lib/", arg);

    if (my_core->isExit) return 84;

    my_core->loop();

    return 0;
}
