/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** jump
*/

#include "struct.h"

void jump(run_t *run)
{
    static int x = 0;
    sfVector2f pos;

    if (run->player->is_jump) {
        pos.x = run->player->pos.x;
        pos.y = run->player->pos.y + 0.56 * x * (x - 27);
        sfSprite_setPosition(run->player->sprite, pos);
        if (x == 27) {
            x = 0;
            run->player->is_jump = 0;
        }
        x++;
    }
}