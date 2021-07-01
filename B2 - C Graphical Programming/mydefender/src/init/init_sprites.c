/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sprites
*/

#include "defender.h"
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
    sprite->life = LIFE;
    sprite->is_kill = OFF;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    free(filepath);
    return sprite;
}

void init_sprites3(all_sprite_t *s)
{
    s->sound = new_sprite("sound.png", (sfIntRect){0, 0, 39, 34},
                        (sfVector2f){0, 0}, (sfVector2f){461, 274});
    s->screen = new_sprite("screen.png", (sfIntRect){0, 0, 38, 36},
                        (sfVector2f){0, 0}, (sfVector2f){460, 353});
    s->life = new_sprite("heart.png", (sfIntRect){0, 0, 141, 41},
                        (sfVector2f){0, 0}, (sfVector2f){809, 7});
    s->lose = new_sprite("gameover.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->win = new_sprite("victory.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->wave = new_sprite("wave.png", (sfIntRect){0, 0, 271, 36},
                        (sfVector2f){0, 0}, (sfVector2f){344, 50});
    s->infos = new_sprite("info.png", (sfIntRect){0, 0, 126, 40},
                        (sfVector2f){0, 0}, (sfVector2f){409, 398});
}

void init_sprites2(all_sprite_t *s)
{
    s->check1 = new_sprite("car1.png", (sfIntRect){0, 0, 32, 26},
                        (sfVector2f){0, 0}, (sfVector2f){464, 189});
    s->check2 = new_sprite("car1.png", (sfIntRect){0, 0, 32, 26},
                        (sfVector2f){0, 0}, (sfVector2f){588, 278});
    s->check3 = new_sprite("car1.png", (sfIntRect){0, 0, 32, 26},
                        (sfVector2f){0, 0}, (sfVector2f){436, 325});
    s->check4 = new_sprite("car1.png", (sfIntRect){0, 0, 32, 26},
                        (sfVector2f){0, 0}, (sfVector2f){525, 342});
    s->end = new_sprite("car1.png", (sfIntRect){0, 0, 32, 26},
                        (sfVector2f){0, 0}, (sfVector2f){685, 216});
    s->hud = new_sprite("hud.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->ui = new_sprite("ui.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->how = new_sprite("how_to.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->sett = new_sprite("settings.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    init_sprites3(s);
}

void init_sprites(defender_t *defender)
{
    all_sprite_t *s = malloc(sizeof(all_sprite_t));

    s->mouse = new_sprite("cursor.png", (sfIntRect){0, 0, 27, 28},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->pause = new_sprite("pause.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->home = new_sprite("home.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->map = new_sprite("map.png", (sfIntRect){0, 0, 960, 540},
                        (sfVector2f){0, 0}, (sfVector2f){0, 0});
    s->btn_exit = new_sprite("exit.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){0, 0}, (sfVector2f){404, 284});
    s->btn_menu = new_sprite("menu.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){0, 0}, (sfVector2f){404, 231});
    s->btn_start = new_sprite("start.png", (sfIntRect){0, 0, 152, 39},
                        (sfVector2f){0, 0}, (sfVector2f){398, 406});
    init_sprites2(s);
    defender->sprites = s;
}