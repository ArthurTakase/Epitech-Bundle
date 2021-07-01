/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** ennemis
*/

#include "rpg.h"
#include <stdlib.h>

void ennemis_event_part(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
}

void end_ennemis(int *ennemi, rpg_t *rpg)
{
    if (*ennemi == 3) {
        *ennemi = 0;
        rpg->fight->turn = PLAYER;
    }
}

void attack_ennemis(int *ennemi, rpg_t *rpg)
{
    ennemi_t *arr[3] = {rpg->fight->enn1, rpg->fight->enn2, rpg->fight->enn3};
    int arr_att[4] = {0, ATT, ATT2, ATT2};
    sound_t *arr_s[4] = {NULL, rpg->sounds->punch, rpg->sounds->knife,
                        rpg->sounds->knife};

    if (arr[*ennemi]->state != DEAD_ENN && rpg->player->state != DEAD) {
        if (rand() % 100 > arr[*ennemi]->miss) {
            sfSound_play(arr_s[arr[*ennemi]->type]->sound);
            anime_hurt(rpg, arr_att[arr[*ennemi]->type], 3);
            arr[*ennemi]->state = ATT_ENN;
            rpg->player->state = HURT;
            if ((rpg->player->life -= arr[*ennemi]->att) <= 0)
                rpg->player->state = DEAD;
        } else
            arr[*ennemi]->state = ATT_ENN;
    }
    *ennemi += 1;
    end_ennemis(ennemi, rpg);
}

void ennemis_event(rpg_t *rpg)
{
    sfEvent event;
    static int ennemi = 0;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        ennemis_event_part(rpg, &event);
    if (anime(rpg->clocks->ennemi) && rpg->player->state == IDLE)
        attack_ennemis(&ennemi, rpg);
}