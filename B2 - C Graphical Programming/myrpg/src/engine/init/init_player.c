/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sprites
*/

#include "rpg.h"
#include <stdlib.h>

void init_anime_player(player_t *s)
{
    s->idle = new_sprite("chara/idle.png", (sfIntRect){0, 0, 88, 78},
                        (sfVector2f){0, 0}, (sfVector2f){630, 342});
    s->idle2 = new_sprite("chara/idle2.png", (sfIntRect){0, 0, 88, 78},
                        (sfVector2f){0, 0}, (sfVector2f){630, 342});
    s->attack = new_sprite("chara/attack1.png", (sfIntRect){0, 0, 88, 78},
                        (sfVector2f){0, 0}, (sfVector2f){630, 342});
    s->attack2 = new_sprite("chara/attack2.png", (sfIntRect){0, 0, 120, 100},
                        (sfVector2f){0, 0}, (sfVector2f){588, 298});
    s->dead = new_sprite("chara/dead.png", (sfIntRect){0, 0, 88, 78},
                        (sfVector2f){0, 0}, (sfVector2f){630, 342});
    s->hurt = new_sprite("chara/hurt.png", (sfIntRect){0, 0, 88, 78},
                        (sfVector2f){0, 0}, (sfVector2f){630, 342});
    s->run = new_sprite("chara/run.png", (sfIntRect){0, 0, 64, 64},
                        (sfVector2f){0, 0}, (sfVector2f){640, 366});
}

void set_scale_player(player_t *s)
{
    sfSprite_setScale(s->idle->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->idle2->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->attack->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->attack2->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->hurt->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->dead->sprite, (sfVector2f){2, 2});
    sfSprite_setScale(s->run->sprite, (sfVector2f){2, 2});
}

player_t *init_player(void)
{
    player_t *s = malloc(sizeof(player_t));

    s->att = START_ATT;
    s->life = START_HP;
    s->max_life = START_HP;
    s->lvl = START_LVL;
    s->state = IDLE;
    s->life_txt = new_txt((sfVector2f){720, 500}, "25", 20, 0);
    s->xp = 0;
    s->gold = START_GOLD;
    s->key = START_KEY;
    s->potion = START_POTION;
    init_anime_player(s);
    set_scale_player(s);
    return s;
}