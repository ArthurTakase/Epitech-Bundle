/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** print_array
*/

#include "lib.h"
#include "minishell.h"

void print_2darray(char **array)
{
    my_putstr("[");
    for (int i = 0; array[i] != 0; i++) {
        my_putstr(array[i]);
        my_putstr(", ");
    }
    my_putstr("END]");
}

void print_3darray(char ***array)
{
    char *color[7] = {RED, GREEN, YELLLOW, BLUE, CYAN, MAGENTA, WHITE};

    my_putstr("[");
    for (int i = 0; array[i] != 0; i++) {
        my_putstr(color[i % 7]);
        print_2darray(array[i]);
        my_putstr(RESET ", ");
    }
    my_putstr("END]");
}

void print_dlist(dlist_t cmd)
{
    char *color[7] = {RED, GREEN, YELLLOW, BLUE, CYAN, MAGENTA, WHITE};
    dlistnode_t *temp = cmd->begin;

    my_putstr("[");
    for (int i = 0; temp != NULL; i++) {
        my_putstr(color[i % 7]);
        print_2darray(temp->infos->cmd);
        my_putstr(RESET ", ");
        temp = temp->next;
    }
    my_putstr("END]\n");
}