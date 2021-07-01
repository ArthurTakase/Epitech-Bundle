/*
** EPITECH PROJECT, 2020
** get error
** File description:
** get error from bistro
*/

#include "../include/my.h"
#include "../include/eval.h"
#include <stdlib.h>

// Detecte si un opérateur se trouve dans la base
int base_op(char **argv)
{
    for (int i = 0; argv[2][i] != '\0'; i++)
        if (my_in(argv[2][i], argv[1]))
            return 1;
    return 0;
}

// Detecte si deux char identiques dans un str
int multiple_infos(char *argv)
{
    for (int i = 0; argv[i] != '\0'; i++)
        if (argv[i] == argv[i + 1])
            return 1;
    return 0;
}

// Check le nombre de () est bon
int check_parent(char *buff)
{
    int open = 0;
    int close = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '(')
            open++;
        if (buff[i] == ')')
            close++;
    }
    if (open != close)
        return 1;
    return 0;
}

// Check si les éléments du calcul existent
int check_exist(char *buff, char **argv)
{
    for (int i = 0; i < my_strlen(buff) - 1; i++)
        if (my_in(buff[i], argv[1]) == 0 && my_in(buff[i], argv[2]) == 0)
            return 1;
    return 0;
}

// Gestion des erreurs
void get_error(char *buff, int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        exit_error(USAGE_MSG);
    if (argc != 4)
        exit_error(SYNTAX_ERROR_MSG);
    if (my_strlen(buff) == 1)
        exit_error(SYNTAX_ERROR_MSG);
    if (my_strlen(argv[2]) != 7)
        exit_error(SYNTAX_ERROR_MSG);
    if (base_op(argv))
        exit_error(SYNTAX_ERROR_MSG);
    if (multiple_infos(argv[1]) || multiple_infos(argv[2]))
        exit_error(SYNTAX_ERROR_MSG);
    if (check_parent(buff))
        exit_error(SYNTAX_ERROR_MSG);
    if (check_exist(buff, argv))
        exit_error(SYNTAX_ERROR_MSG);
}
