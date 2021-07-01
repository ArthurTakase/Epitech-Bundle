/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** my_rand
*/

#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>

static int randomize_seed(FILE *in)
{
    unsigned int seed;

    if (!in)
        return 1;
    if (fread(&seed, sizeof(seed), 1, in) == 1) {
        fclose(in);
        srand(seed);
        return 0;
    }
    fclose(in);
    return 1;
}

int randomize(void)
{
    if (!randomize_seed(fopen("/dev/urandom", "r")) ||
        !randomize_seed(fopen("/dev/arandom", "r")) ||
        !randomize_seed(fopen("/dev/random", "r")))
        return 0;
    return 1;
}

int my_rand(void)
{
    randomize();
    return rand();
}