/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** destroy_all
*/

#include "struct.h"

void destroy(run_t *run)
{
    destroy_sprite(run);
    clear_trap(run);
    destroy_music(run);
    sfRenderWindow_destroy(run->window);
}