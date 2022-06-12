/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-nmobjdump-arthur.decaen
** File description:
** checker
*/

#include "objdump.h"

int check_char(char c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}

void add_space(int oct)
{
    for (unsigned int i = oct % 16; i < 16; i++) {
        printf("  ");
        if (i % 4 == 0)
            printf(" ");
    }
}
