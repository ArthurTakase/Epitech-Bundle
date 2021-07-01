/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_window
*/

#include "rpg.h"

void init_window(rpg_t *rpg)
{
    sfVideoMode mode;

    if (rpg->settings->fullscreen == FALSE) {
        mode = (sfVideoMode){960, 540, 32};
        rpg->window = sfRenderWindow_create(mode, "My_RPG", 7, NULL);
    } else {
        mode = (sfVideoMode){1920, 1080, 32};
        rpg->window = sfRenderWindow_create(mode, "My_RPG", 8, NULL);
    }
    sfRenderWindow_setFramerateLimit(rpg->window, FPS);
    sfRenderWindow_setMouseCursorVisible(rpg->window, sfFalse);
}