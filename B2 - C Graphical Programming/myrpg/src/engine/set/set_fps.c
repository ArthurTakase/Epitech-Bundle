/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** set_fps
*/

#include "rpg.h"

void set_fps(rpg_t *rpg, int step, char type)
{
    if (type == 'm' && rpg->settings->fps - step >= MIN_FPS)
        rpg->settings->fps -= step;
    if (type == 'p' && rpg->settings->fps + step <= MAX_FPS)
        rpg->settings->fps += step;
    set_txt(rpg->menu->txt_frame, rpg->settings->fps);
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->settings->fps);
}