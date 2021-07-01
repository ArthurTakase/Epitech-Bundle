/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** check_jauge
*/

#include "struct.h"

void edit_jauge(run_t *run)
{
    int value = -1024 + (1024 / run->trap_max) * (run->len_trap - 1);
    run->jauge->full->rect.width = value;
    run->len_trap--;
    sfSprite_setTextureRect(run->jauge->full->sprite, run->jauge->full->rect);
}