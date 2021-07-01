/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sprites
*/

#include "rpg.h"
#include <stdlib.h>

void init_sprite_player_map(player_map_t *s)
{
    s->walk_up = new_sprite("chara_map/walk_up.png",
                    (sfIntRect){0, 0, 16, 17}, (sfVector2f){0, 0}, s->pos);
    s->walk_down = new_sprite("chara_map/walk_down.png",
                    (sfIntRect){0, 0, 16, 17}, (sfVector2f){0, 0}, s->pos);
    s->walk_left = new_sprite("chara_map/walk_left.png",
                    (sfIntRect){0, 0, 16, 17}, (sfVector2f){0, 0}, s->pos);
    s->walk_right = new_sprite("chara_map/walk_right.png",
                    (sfIntRect){0, 0, 16, 17}, (sfVector2f){0, 0}, s->pos);
    s->idle_down = new_sprite("chara_map/idle_down.png",
                    (sfIntRect){0, 0, 16, 16}, (sfVector2f){0, 0}, s->pos);
    s->idle_up = new_sprite("chara_map/idle_up.png",
                    (sfIntRect){0, 0, 16, 16}, (sfVector2f){0, 0}, s->pos);
    s->idle_left = new_sprite("chara_map/idle_left.png",
                    (sfIntRect){0, 0, 16, 16}, (sfVector2f){0, 0}, s->pos);
    s->idle_right = new_sprite("chara_map/idle_right.png",
                    (sfIntRect){0, 0, 16, 16}, (sfVector2f){0, 0}, s->pos);
}

void set_scale_player_map(player_map_t *s)
{
    sprite_t *arr_spr[8] = {s->idle_down, s->idle_left, s->idle_up,
                        s->idle_right, s->walk_down, s->walk_left,
                        s->walk_right, s->walk_up};

    for (int i = 0; i != 8; i++)
        sfSprite_setScale(arr_spr[i]->sprite, (sfVector2f){3, 3});
}

player_map_t *init_player_map(void)
{
    player_map_t *s = malloc(sizeof(player_map_t));

    s->nxt_lvl = 30;
    s->up = sfKeyUp;
    s->down = sfKeyDown;
    s->left = sfKeyLeft;
    s->right = sfKeyRight;
    s->move = PLAYER_SPD;
    s->state = FACE;
    s->is_move = FALSE;
    s->pos = (sfVector2f){WIN_W / 2 - 16, WIN_H / 2 - 16};
    init_sprite_player_map(s);
    set_scale_player_map(s);
    return s;
}