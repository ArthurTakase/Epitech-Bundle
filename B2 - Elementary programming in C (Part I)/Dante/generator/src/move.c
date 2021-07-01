/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** move
*/

#include "generator.h"
#include "dante.h"
#include "lib.h"
#include <stdlib.h>
#include <time.h>

int is_outside(gen_t *gen, pos_t *pos, int dir)
{
    if (dir == UP && pos->y - 2 < 0)
        return TRUE;
    if (dir == RIGHT && pos->x + 2 >= gen->col)
        return TRUE;
    if (dir == DOWN && pos->y + 2 >= gen->line)
        return TRUE;
    if (dir == LEFT && pos->x - 2 < 0)
        return TRUE;
    return FALSE;
}

int check_move(gen_t *gen, pos_t *pos, int dir)
{
    int movey[4] = {-2, 0, 2, 0};
    int movex[4] = {0, 2, 0, -2};

    if (is_outside(gen, pos, dir))
        return FALSE;
    if (gen->map[pos->y + movey[dir]][pos->x + movex[dir]] == '0')
        return TRUE;
    return FALSE;
}

int move_dir(gen_t *gen, pos_t *pos, int dir)
{
    int newx[4] = {0, 2, 0, -2};
    int newy[4] = {-2, 0, 2, 0};
    int movex[4] = {0, -1, 0, 1};
    int movey[4] = {1, 0, -1, 0};

    pos->x += newx[dir];
    pos->y += newy[dir];
    gen->map[pos->y][pos->x] = '1';
    gen->map[pos->y + movey[dir]][pos->x + movex[dir]] = '1';
    return 1;
}

void move(gen_t *gen, pos_t *pos)
{
    int choice;
    int move_ok = 0;

    while (!move_ok) {
        choice = rand() % 4;
        if (check_move(gen, pos, choice))
            move_ok = move_dir(gen, pos, choice);
    }
    gen->nb_zero -= 1;
}