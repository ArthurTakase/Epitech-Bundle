/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sprites
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

sprite_t *new_sprite(char *file, sfIntRect rect, sfVector2f move,
                    sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    char *filepath = my_strcat("asset/img/", file);

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->move = move;
    sprite->pos = pos;
    sprite->state = 0;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    free(filepath);
    return sprite;
}

void init_sprites_p2(all_sprite_t *s)
{
    s->inventory = new_sprite("inventaire.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
}

all_sprite_t *init_sprites(void)
{
    all_sprite_t *s = malloc(sizeof(all_sprite_t));

    s->mouse = new_sprite("cursor.png", (sfIntRect){0, 0, 27, 28},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->ground = new_sprite("bg/ground.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->punch = new_sprite("attack/punch.png", (sfIntRect){0, 0, 64, 64},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->slash = new_sprite("attack/slash.png", (sfIntRect){0, 0, 64, 64},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->f_att = new_sprite("fight/attack.png", (sfIntRect){0, 0, 260, 74},
                        (sfVector2f){0, 0}, (sfVector2f){665, 280});
    s->f_run = new_sprite("fight/run.png", (sfIntRect){0, 0, 260, 74},
                        (sfVector2f){0, 0}, (sfVector2f){665, 320});
    s->chest = new_sprite("fight/chest.png", (sfIntRect){0, 0, 180, 180},
                        (sfVector2f){0, 0}, (sfVector2f){390, 180});
    init_sprites_p2(s);
    sfSprite_setScale(s->f_att->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(s->f_run->sprite, (sfVector2f){0.5, 0.5});
    return s;
}