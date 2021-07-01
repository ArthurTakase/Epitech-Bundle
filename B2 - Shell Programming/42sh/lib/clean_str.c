/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** clean_str
*/

#include "lib.h"
#include <stdlib.h>

char *clean_str(char *argv)
{
    int nb_space = 0;
    int index = 0;
    char *result = malloc(sizeof(char) * (my_strlen(argv) + 1));

    for (int i = 0; argv[i] != '\0'; i++) {
        if (argv[i] == '\t' || argv[i] == ' ') {
            nb_space++;
        } else {
            if (nb_space != 0 && i - nb_space != 0) {
                result[index] = ' ';
                index++;
            }
            result[index] = argv[i];
            nb_space = 0;
            index++;
        }
    }
    result[index] = '\0';
    return result;
}