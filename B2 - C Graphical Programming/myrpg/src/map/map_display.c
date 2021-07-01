/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** map_display
*/

#include "rpg.h"
#include "lib.h"

void display_map(rpg_t *r, map_t *m)
{
    tile_t *tmp = m->clone;
    sbtn_t *b_tmp = m->b;

    while (tmp->next != NULL) {
        draw_sprite(r, tmp->s);
        tmp = tmp->next;
    }
    while (b_tmp->next != NULL) {
        draw_sprite(r, b_tmp->s);
        b_tmp = b_tmp->next;
    }
    draw_sprite(r, tmp->s);
    draw_sprite(r, b_tmp->s);
    draw_sprite(r, m->save_button->s);
}

void draw_current_map(rpg_t *rpg)
{
    tile_t *tmp = rpg->map->clone;

    while (tmp->next != NULL) {
        draw_sprite(rpg, tmp->s);
        tmp = tmp->next;
    }
}