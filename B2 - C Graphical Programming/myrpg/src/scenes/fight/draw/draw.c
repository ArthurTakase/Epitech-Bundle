/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** draw
*/

#include "rpg.h"
#include "lib.h"

void draw_ennemis(rpg_t *rpg)
{
    ennemi_t *enn1 = rpg->fight->enn1;
    sprite_t *arr_1[4] = {enn1->idle, enn1->attack, enn1->hurt, enn1->dead};
    ennemi_t *enn2 = rpg->fight->enn2;
    sprite_t *arr_2[4] = {enn2->idle, enn2->attack, enn2->hurt, enn2->dead};
    ennemi_t *enn3 = rpg->fight->enn3;
    sprite_t *arr_3[4] = {enn3->idle, enn3->attack, enn3->hurt, enn3->dead};

    if (enn1->type != EMPTY)
        draw_sprite(rpg, arr_1[enn1->state]);
    if (enn2->type != EMPTY)
        draw_sprite(rpg, arr_2[enn2->state]);
    if (enn3->type != EMPTY)
        draw_sprite(rpg, arr_3[enn3->state]);
}

void draw_hud(rpg_t *rpg)
{
    ennemi_t *arr[3] = {rpg->fight->enn1, rpg->fight->enn2, rpg->fight->enn3};

    update_hud(rpg);
    for (int i = 0; i != 3; i++)
        if (arr[i]->state != DEAD_ENN)
            draw_txt(rpg, arr[i]->life_txt);
    if (rpg->player->state != DEAD)
        draw_txt(rpg, rpg->player->life_txt);
    if (rpg->fight->turn == ENNEMI)
        sfText_setString(rpg->txts->fight_turn->txt, "ENNEMI's turn");
    else
        sfText_setString(rpg->txts->fight_turn->txt, "PLAYER's turn");
    draw_txt(rpg, rpg->txts->fight_turn);
}

void draw_att(rpg_t *rpg)
{
    if (rpg->sprites->punch->state == 0)
        draw_sprite(rpg, rpg->sprites->punch);
    if (rpg->sprites->slash->state == 0)
        draw_sprite(rpg, rpg->sprites->slash);
}

void fight_draw(rpg_t *rpg)
{
    player_t *p = rpg->player;
    sprite_t *arr_p[7] = {p->idle, p->idle2, p->attack, p->attack2, p->hurt,
                        p->dead, p->run};

    draw_parallax(rpg);
    draw_sprite(rpg, arr_p[rpg->player->state]);
    draw_ennemis(rpg);
    draw_sprite(rpg, rpg->sprites->ground);
    draw_att(rpg);
    if (rpg->fight->turn == PLAYER && rpg->player->state == IDLE) {
        if (rpg->fight->state == 0) {
            draw_sprite(rpg, rpg->sprites->f_run);
            draw_sprite(rpg, rpg->sprites->f_att);
        }
        draw_sprite(rpg, rpg->sprites->mouse);
    }
    draw_hud(rpg);
}