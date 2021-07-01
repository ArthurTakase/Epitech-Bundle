/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** gamelopp
*/

#include "rpg.h"
#include "lib.h"

int gameloop(rpg_t *rpg)
{
    static void (*scene_display[7])(rpg_t *) = {home, game, fight, end_fight,
                                                map, inventory, param};

    while (sfRenderWindow_isOpen(rpg->window))
        scene_display[rpg->scene](rpg);
    destroy(rpg);
    sfRenderWindow_destroy(rpg->window);
    return 0;
}