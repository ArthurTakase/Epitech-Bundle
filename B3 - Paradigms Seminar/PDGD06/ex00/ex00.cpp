/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** ex00
*/

#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    char c;

    if (argc == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]\n";
        return 84;
    }
    for (int i = 1; i != argc; i++) {
        std::ifstream file (argv[i]);
        if (file.is_open()) {
            c = file.get();
            for (; file.good(); c = file.get())
                std::cout << c;
        } else {
            std::cerr << "my_cat: " << argv[i] << ": No such file or directory";
            return 84;
        }
    }
    return 0;
}