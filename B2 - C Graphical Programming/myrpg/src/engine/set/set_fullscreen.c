/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** fullscreen
*/

#include "rpg.h"

void set_fullscreen(rpg_t *rpg)
{
    switch (rpg->settings->fullscreen) {
        case TRUE:
            rpg->settings->fullscreen = FALSE;
            break;
        case FALSE:
            rpg->settings->fullscreen = TRUE;
            break;
    }
    sfRenderWindow_destroy(rpg->window);
    init_window(rpg);
}