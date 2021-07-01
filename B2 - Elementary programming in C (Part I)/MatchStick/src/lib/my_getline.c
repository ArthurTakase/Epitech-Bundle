/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** my_getline
*/

#include "match.h"
#include "lib.h"
#include <stdio.h>

int my_getline(match_t *match)
{
    size_t n = 0;
    char *buff = NULL;
    int len;

    if (getline(&buff, &n, stdin) == -1) {
        match->winner = 0;
        return 1;
    }
    len = my_strlen(buff);
    if (buff[len - 1] == '\n')
        buff[len - 1] = '\0';
    match->get_line = clonestr(buff);
    free(buff);
    return 0;
}