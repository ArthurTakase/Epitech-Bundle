/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** tools
*/

#include "rpg.h"
#include <stdlib.h>

void free_fight(rpg_t *rpg)
{
    ennemi_t *arr_e[3] = {rpg->fight->enn1, rpg->fight->enn2,
                        rpg->fight->enn3};

    for (int i = 0; i < 3; i++) {
        delet_sprite(arr_e[i]->attack);
        delet_sprite(arr_e[i]->idle);
        delet_sprite(arr_e[i]->dead);
        delet_sprite(arr_e[i]->hurt);
        sfText_destroy(arr_e[i]->life_txt->txt);
        sfFont_destroy(arr_e[i]->life_txt->font);
        free(arr_e[i]->life_txt);
        free(arr_e[i]);
    }
    free(rpg->fight);
    rpg->fight = NULL;
}

void update_hud(rpg_t *rpg)
{
    set_txt(rpg->player->life_txt, rpg->player->life);
    set_txt(rpg->fight->enn1->life_txt, rpg->fight->enn1->life);
    set_txt(rpg->fight->enn2->life_txt, rpg->fight->enn2->life);
    set_txt(rpg->fight->enn3->life_txt, rpg->fight->enn3->life);
}