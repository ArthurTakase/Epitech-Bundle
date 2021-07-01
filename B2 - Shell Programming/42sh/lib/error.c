/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen-master
** File description:
** error
*/

#include "lib.h"
#include <unistd.h>

int errormsg(int value, char *msg)
{
    write(2, msg, my_strlen(msg) + 1);
    return value;
}