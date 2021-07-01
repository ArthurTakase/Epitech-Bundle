/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** ia
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "lib.h"
#include "need.h"

bool is_cleared(char **infos)
{
    if (len_array(infos) < STATUS)
        exit(84);
    if (!my_strcmp(infos[STATUS], "Track Cleared"))
        return true;
    return false;
}

void execute_cmd(char *cmd, char *sign, char *value)
{
    my_putstr(cmd);
    my_putstr(sign);
    my_putstr(value);
    my_putstr("\n");
    clean_stdin();
}

void free_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}

int ia(void)
{
    char **infos;

    execute_cmd(START, "", "");
    while (1) {
        infos = get_infos();
        if (is_cleared(infos)) {
            free_array(infos);
            break;
        }
        move_car(infos);
        free_array(infos);
    }
    execute_cmd(STOP, "", "");
    return 0;
}