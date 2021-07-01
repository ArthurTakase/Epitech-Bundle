/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** destroy
*/

#include "rpg.h"
#include <stdlib.h>

void destroy_sprite(rpg_t *rpg)
{
    all_sprite_t *spr = rpg->sprites;
    player_t *spr2 = rpg->player;
    bg_t *bg = rpg->bg;
    sprite_t *arr_spr[23] = {spr2->idle, spr2->idle2, spr2->attack,
        spr2->attack2, spr2->hurt, spr2->dead, spr->mouse, spr->ground,
        bg->bg1, bg->bg1_b, bg->bg2, bg->bg2_b, bg->bg3, bg->bg3_b, spr2->run,
        spr->punch, spr->slash, spr->f_att, spr->f_run, spr->chest,
        rpg->fade->fade_in, rpg->fade->fade_out, rpg->fade->circle};

    for (int i = 0; i < 23; ++i)
        delet_sprite(arr_spr[i]);
    free(rpg->sprites);
    free(rpg->fade);
}

void destroy_clock(rpg_t *rpg)
{
    all_clock_t *c = rpg->clocks;
    clocks_t *arr_c[6] = {c->player, c->dtime, c->particule, c->ennemi,
                        c->fade, c->player_map};

    for (int i = 0; i < 6; ++i) {
        sfClock_destroy(arr_c[i]->clock);
        free(arr_c[i]);
    }
    free(rpg->clocks);
}

void destroy_audio(rpg_t *rpg)
{
    all_sound_t *s = rpg->sounds;
    sound_t *arr_s[3] = {s->hud, s->knife, s->punch};

    for (int i = 0; i < 3; ++i) {
        sfSound_destroy(arr_s[i]->sound);
        sfSoundBuffer_destroy(arr_s[i]->buff);
        free(arr_s[i]);
    }
    sfMusic_destroy(rpg->sounds->music);
    free(rpg->sounds);
}

void destroy_txt(rpg_t *rpg)
{
    txt_t *arr_t[12] = {rpg->txts->fight_turn, rpg->txts->fight_result,
        rpg->txts->fight_gains, rpg->player->life_txt, rpg->txts->att,
        rpg->txts->gold, rpg->txts->key, rpg->txts->lvl, rpg->txts->max_life,
        rpg->txts->potion, rpg->txts->slash, rpg->txts->life};

    for (int i = 0; i < 12; i++) {
        sfText_destroy(arr_t[i]->txt);
        sfFont_destroy(arr_t[i]->font);
        free(arr_t[i]);
    }
}

void destroy(rpg_t *rpg)
{
    destroy_sprite(rpg);
    destroy_clock(rpg);
    destroy_audio(rpg);
    destroy_txt(rpg);
    if (rpg->fight != NULL)
        free_fight(rpg);
    free(rpg->player);
    clear_dlist(rpg->particle);
    free(rpg->settings);
}