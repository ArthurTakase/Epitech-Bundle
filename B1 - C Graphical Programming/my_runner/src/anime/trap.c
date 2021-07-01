/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** trap
*/

#include "struct.h"

void trap_h(trap_t temp, int forward, int limit, int base)
{
    sfIntRect rect = temp->trap->rect;
    temp->trap->rect.left += forward;
    if (temp->trap->rect.left >= limit)
        temp->trap->rect.left = base;
    sfSprite_setTextureRect(temp->trap->sprite, rect);
}

void trap_v(trap_t temp, int forward, int limit, int base)
{
    sfIntRect rect = temp->trap->rect;
    temp->trap->rect.top += forward;
    if (temp->trap->rect.top >= limit)
        temp->trap->rect.top = base;
    sfSprite_setTextureRect(temp->trap->sprite, rect);
}

void anime_trap(run_t *run, int value)
{
    trap_t temp = run->trap;

    while (temp != NULL) {
        if (temp->trap->value == 0 && value == 0)
            trap_h(temp, 36, 216, 0);
        if (temp->trap->value == 1 && value == 1)
            trap_h(temp, 21, 464, 401);
        if (temp->trap->value == 2 && value == 2)
            trap_h(temp, 21, 483, 441);
        if (temp->trap->value == 3 && value == 3)
            trap_v(temp, 21, 250, 210);
        if (temp->trap->value == 4 && value == 4)
            trap_h(temp, 32, 1024, 0);
        temp = temp->next;
    }
}