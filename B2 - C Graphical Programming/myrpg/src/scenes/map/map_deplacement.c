/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map_deplacement
*/

#include "rpg.h"

void map_deplacement(rpg_t *rpg, map_t *m, sfVector2f mov, char type)
{
    tile_t *tmp = m->clone;
    sfVector2f new;

    while (tmp->next != NULL) {
        if (type == 'm')
            sfSprite_move(tmp->s->sprite, mov);
        else {
            new.x = mov.x * rpg->dtime;
            new.y = mov.y * rpg->dtime;
            sfSprite_move(tmp->s->sprite, new);
        }
        tmp = tmp->next;
    }
    sfSprite_move(tmp->s->sprite, mov);
}

void movement(rpg_t *rpg, sfKeyEvent *e, map_t *m)
{
    float movement = 48;
    switch (e->code) {
        case sfKeyLeft:
            map_deplacement(rpg, m, (sfVector2f){movement, 0}, 'm');
            break;
        case sfKeyRight:
            map_deplacement(rpg, m, (sfVector2f){-movement, 0}, 'm');
            break;
        case sfKeyUp:
            map_deplacement(rpg, m, (sfVector2f){0, movement}, 'm');
            break;
        case sfKeyDown:
            map_deplacement(rpg, m, (sfVector2f){0, -movement}, 'm');
            break;
        default:
            break;
    }
}