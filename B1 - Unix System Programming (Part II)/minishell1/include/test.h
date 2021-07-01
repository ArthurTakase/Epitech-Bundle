/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** test
*/

/*
** Ce fichier est utilisé pour les tests Criterion.
** Il contient les prototypes de toutes les fonctions du programme
*/

#ifndef TEST_H_
#define TEST_H_

#include "minishell.h"

// LIB
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

// arg.c
char *clonestr(char *txt);
int get_word(char *txt);
char **split(char *txt);
char **get_command(void);

// exe.c
void execute_command(shell_t *shell);

// minishell.c
int minishell(int argc, char **argv, char **env);

#endif