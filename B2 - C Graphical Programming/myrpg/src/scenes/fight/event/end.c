/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** end
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void reset_fight(rpg_t *rpg)
{
    free_fight(rpg);
    if (rpg->infos_fight->state == VICTORY)
        switch_music(rpg, "fight/victory.ogg");
    else
        switch_music(rpg, "fight/defeat.ogg");
    sfMusic_setLoop(rpg->sounds->music, sfFalse);
    rpg->fade->circle_fade = 10;
    rpg->fade->in = 255;
    rpg->fade->out = 0;
    rpg->scene = END_FIGHT;
}

void set_string_gains(rpg_t *rpg)
{
    int gold = ((rand() % 20) + 5) * rpg->infos_fight->nb_win;
    int xp = ((rand() % 20) + 5) * rpg->infos_fight->nb_win;
    char *gold_str = my_itos(gold, 10);
    char *xp_str = my_itos(xp, 10);
    char *part_un = my_strcat(gold_str, "G, ");
    char *part_deux = my_strcat(part_un, xp_str);
    char *part_trois = my_strcat(part_deux, "xp");

    sfText_setString(rpg->txts->fight_gains->txt, part_trois);
    free(gold_str);
    free(xp_str);
    free(part_un);
    free(part_deux);
    free(part_trois);
    rpg->player->gold += gold;
    rpg->player->xp += xp;
}

void get_infos_fight(rpg_t *rpg, int value)
{
    infos_fight_t *infos = malloc(sizeof(infos_fight_t));
    ennemi_t *enn[3] = {rpg->fight->enn1, rpg->fight->enn2, rpg->fight->enn3};

    infos->state = value;
    infos->nb_win = 0;
    for (int i = 0; i != 3; i++) {
        if (enn[i]->type != EMPTY && enn[i]->state == DEAD_ENN)
            infos->nb_win += 1;
    }
    rpg->infos_fight = infos;
    set_string_gains(rpg);
}

void transition(rpg_t *rpg, int value)
{
    int step = circle_animation(rpg);

    if (step == 1 && fade_out(rpg)) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        get_infos_fight(rpg, value);
        reset_fight(rpg);
    }
    draw_sprite(rpg, rpg->fade->circle);
}

void fight_end(rpg_t *rpg)
{
    if (rpg->fight->enn1->state == DEAD_ENN &&
        rpg->fight->enn2->state == DEAD_ENN &&
        rpg->fight->enn3->state == DEAD_ENN) {
        sfText_setString(rpg->txts->fight_result->txt, "VICTORY !");
        transition(rpg, VICTORY);
    } else if (rpg->player->state == DEAD) {
        sfText_setString(rpg->txts->fight_result->txt, "DEFEAT...");
        transition(rpg, DEFEAT);
    }
}