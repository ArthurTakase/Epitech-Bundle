/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** destroy
*/

#include "defender.h"
#include <stdlib.h>

void destroy_sprite(defender_t *def)
{
    all_sprite_t *spr = def->sprites;
    zone_t *spr2 = def->zones;
    sprite_t *arr_spr[25] = {spr->btn_exit, spr->btn_menu, spr->btn_start,
            spr->home, spr->map, spr->mouse, spr->pause, spr->check1,
            spr->check2, spr->check3, spr->check4, spr->end, spr->hud,
            spr->ui, spr2->zone1, spr2->zone2, spr2->zone3, spr->life,
            spr->lose, spr->win, spr->wave, spr->infos, spr2->zone4,
            spr2->zone5, spr2->zone6};

    for (int i = 0; i < 25; ++i) {
        sfSprite_destroy(arr_spr[i]->sprite);
        sfTexture_destroy(arr_spr[i]->texture);
        free(arr_spr[i]);
    }
    free(def->sprites);
    free(def->zones);
}

void destroy_clock(defender_t *def)
{
    all_clock_t *c = def->clocks;
    clocks_t *arr_c[5] = {c->car, c->dt_game, c->dt_home,
                            c->dt_pause, c->money};

    for (int i = 0; i < 5; ++i) {
        sfClock_destroy(arr_c[i]->clock);
        free(arr_c[i]);
    }
    free(def->clocks);
}

void destroy_audio(defender_t *def)
{
    all_sound_t *s = def->sounds;
    sound_t *arr_s[2] = {s->build, s->click};

    for (int i = 0; i < 2; ++i) {
        sfSound_destroy(arr_s[i]->sound);
        sfSoundBuffer_destroy(arr_s[i]->buff);
        free(arr_s[i]);
    }
    sfMusic_destroy(def->sounds->music);
    free(def->sounds);
}

void destroy_txt(defender_t *def)
{
    txt_t *arr_t[4] = {def->money, def->enn_left, def->fps, def->score};

    for (int i = 0; i != 4; i++) {
        sfText_destroy(arr_t[i]->txt);
        sfFont_destroy(arr_t[i]->font);
        free(arr_t[i]);
    }
}

void destroy(defender_t *def)
{
    def->trap = clear_list(def->trap);
    def->tower = clear_list(def->tower);
    destroy_sprite(def);
    destroy_clock(def);
    destroy_audio(def);
    destroy_txt(def);
    free(def->arr_z);
    free(def->waves);
}