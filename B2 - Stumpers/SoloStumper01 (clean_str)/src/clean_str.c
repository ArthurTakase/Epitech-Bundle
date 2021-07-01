/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-solostumper01-arthur.decaen
** File description:
** main
*/

#include <stdlib.h>
#include "lib.h"

// ********** Main loop **********
void loop(char *argv)
{
    int nb_space = 0;

    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] == '\t' || argv[i] == ' ') {
            nb_space++;
        } else {
            if (nb_space != 0 && i - nb_space != 0)
                my_putchar(' ');
            my_putchar(argv[i]);
            nb_space = 0;
        }
    }
}

// ********** Check if enough arg **********
int get_error(int argc)
{
    if (argc == 1) {
        my_putchar('\n');
        return 1;
    }
    return 0;
}

// ********** Launch other funcitons **********
int main_function(int argc, char *argv)
{
    if (get_error(argc))
        return 0;
    loop(argv);
    my_putchar('\n');
    return 0;
}