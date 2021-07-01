/*
** EPITECH PROJECT, 2020
** exit with error message
** File description:
** affiche un message d'erreur puis ferme le programme
*/

#include <stdlib.h>

int my_putstr(char const *str);

void exit_error(char const *str)
{
    my_putstr(str);
    exit(84);
}
