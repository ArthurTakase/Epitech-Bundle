/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** eventps2
*/

#include "rpg.h"
#include <stdlib.h>

void anime_hurt(rpg_t *rpg, int state, int cible)
{
    sprite_t *att = rpg->sprites->slash;
    sfSprite *atts;

    if (state == ATT)
        att = rpg->sprites->punch;
    atts = att->sprite;
    att->state = 0;
    if (cible != 3) {
        sfSprite_setScale(atts, (sfVector2f){-2, 2});
        sfSprite_setPosition(atts, (sfVector2f){140 * (cible + 2), 350});
    } else {
        sfSprite_setScale(atts, (sfVector2f){2, 2});
        sfSprite_setPosition(atts, (sfVector2f){650, 350});
    }
}

void attack(rpg_t *rpg, int cible)
{
    ennemi_t *arr[3] = {rpg->fight->enn1, rpg->fight->enn2, rpg->fight->enn3};
    int anim[2] = {ATT, ATT2};
    sound_t *arr_s[2] = {rpg->sounds->punch, rpg->sounds->knife};
    int type = rand() % 2;

    if (arr[cible]->type != EMPTY && rpg->player->state == IDLE
        && arr[cible]->state != DEAD_ENN) {
        sfSound_play(arr_s[type]->sound);
        rpg->player->state = anim[type];
        anime_hurt(rpg, rpg->player->state, cible);
        arr[cible]->state = HURT_ENN;
        if ((arr[cible]->life -= rpg->player->att) <= 0)
            arr[cible]->state = DEAD_ENN;
        rpg->fight->turn = ENNEMI;
    }
}