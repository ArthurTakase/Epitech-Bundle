/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** volume
*/

#include "defender.h"

void volume_off(defender_t *def)
{
    all_sound_t *s = def->sounds;
    sound_t *arr_s[2] = {s->build, s->click};
    sfIntRect sound_r = def->sprites->sound->rect;

    for (int i = 0; i < 2; ++i)
        sfSound_setVolume(arr_s[i]->sound, 0);
    sfMusic_setVolume(def->sounds->music, 0);
    sound_r.left = 39;
    sfSprite_setTextureRect(def->sprites->sound->sprite, sound_r);
}

void volume_on(defender_t *def)
{
    sfIntRect sound_r = def->sprites->sound->rect;

    sfSound_setVolume(def->sounds->build->sound, 100.0);
    sfSound_setVolume(def->sounds->click->sound, 100.0);
    sfMusic_setVolume(def->sounds->music, 50.0);
    sound_r.left = 0;
    sfSprite_setTextureRect(def->sprites->sound->sprite, sound_r);
}

void set_volume(defender_t *def)
{
    if (def->is_vol == ON) {
        volume_off(def);
        def->is_vol = OFF;
    } else {
        volume_on(def);
        def->is_vol = ON;
    }
}