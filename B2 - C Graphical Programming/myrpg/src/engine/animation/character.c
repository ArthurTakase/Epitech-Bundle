/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** player
*/

#include "rpg.h"

void anime_ennemis_part(ennemi_t *enn, anime_t limit_l, anime_t step_l)
{
    sprite_t *arr_enn[4] = {enn->idle, enn->attack, enn->hurt, enn->dead};
    int i = enn->state;
    int reset = 0;

    switch (enn->state) {
        case IDLE_ENN:
            reset = anime_sprite(arr_enn[i], step_l.idle, limit_l.idle);
            break;
        case ATT_ENN:
            reset = anime_sprite(arr_enn[i], step_l.att, limit_l.att);
            break;
        case HURT_ENN:
            reset = anime_sprite(arr_enn[i], step_l.hurt, limit_l.hurt);
            break;
        case DEAD_ENN:
            anime_sprite(arr_enn[i], step_l.dead, limit_l.dead);
            break;
    }
    if (reset)
        enn->state = IDLE_ENN;
}

void anime_ennemis(rpg_t *rpg)
{
    anime_t limit[4] = {(anime_t){0, 0, 0, 0}, (anime_t){256, 273, 312, 0},
                    (anime_t){372, 279, 318, 0}, (anime_t){256, 210, 192, 0}};
    anime_t step[4] = {(anime_t){0, 0, 0, 0}, (anime_t){64, 91, 104, 0},
                    (anime_t){93, 93, 106, 0}, (anime_t){64, 70, 64, 0}};

    anime_ennemis_part(rpg->fight->enn1, limit[rpg->fight->enn1->type],
                        step[rpg->fight->enn1->type]);
    anime_ennemis_part(rpg->fight->enn2, limit[rpg->fight->enn2->type],
                        step[rpg->fight->enn2->type]);
    anime_ennemis_part(rpg->fight->enn3, limit[rpg->fight->enn3->type],
                        step[rpg->fight->enn3->type]);
}

void anime_player(rpg_t *rpg)
{
    player_t *p = rpg->player;
    sprite_t *arr_p[7] = {p->idle, p->idle2, p->attack, p->attack2, p->hurt,
                        p->dead, p->run};
    int limit[7] = {352, 352, 264, 360, 264, 88, 256};
    int step[7] = {88, 88, 88, 120, 88, 88, 64};
    int i = rpg->player->state;

    if (anime_sprite(arr_p[i], step[i], limit[i])) {
        if (i != DEAD)
            rpg->player->state = IDLE;
    }
}