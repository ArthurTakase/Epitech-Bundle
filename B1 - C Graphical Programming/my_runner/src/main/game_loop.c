/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** game_loop
*/

#include "struct.h"

void game_loop(run_t *run)
{
    event_all(run);
    move_fps(run);
    animation(run);
    jump(run);
    draw_all(run);
    sfRenderWindow_drawText(run->window, run->score->txt, NULL);
    sfRenderWindow_drawSprite(run->window, run->life->sprite, NULL);
    sfRenderWindow_drawSprite(run->window, run->jauge->full->sprite, NULL);
    sfRenderWindow_drawSprite(run->window, run->jauge->border->sprite, NULL);
    check_score(run);
    check_coll(run);
    delet_trap(run);
    sfRenderWindow_drawSprite(run->window, run->filtre->sprite, NULL);
    sfRenderWindow_display(run->window);
}