/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen-master
** File description:
** run
*/

#include <stdlib.h>
#include "rpg.h"

void run_fight(rpg_t *rpg)
{
    int fuite = rand() % FLY;

    if (fuite == 0) {
        switch_music(rpg, "music.ogg");
        rpg->scene = GAME;
    } else
        rpg->fight->turn = ENNEMI;
}