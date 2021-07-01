/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** new_way
*/

#include "generator.h"
#include "lib.h"
#include <stdlib.h>
#include <time.h>

void new_way(gen_t *gen, pos_t *pos)
{
    if (((gen->col / 2) - 1) * 2 == 0 || ((gen->line / 2) - 1) * 2 == 0)
        return;
    pos->x = (rand() % ((gen->col / 2) - 1)) * 2;
    pos->y = (rand() % ((gen->line / 2) - 1)) * 2;
    while (check_every_dir(gen, pos) || gen->map[pos->y][pos->x] != '1') {
        pos->x += 2;
        if (pos->x > gen->col - 1) {
            pos->x = 0;
            pos->y += 1;
        }
        if (pos->y > gen->line - 1)
            pos->y = 0;
    }
}