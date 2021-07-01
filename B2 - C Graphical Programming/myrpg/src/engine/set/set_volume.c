/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** volume
*/

#include "rpg.h"

void volume_off(rpg_t *rpg)
{
    all_sound_t *s = rpg->sounds;
    sound_t *arr_s[3] = {s->hud, s->knife, s->punch};

    for (int i = 0; i < 3; ++i)
        sfSound_setVolume(arr_s[i]->sound, 0);
    sfMusic_setVolume(s->music, 0);
}

void volume_on(rpg_t *rpg)
{
    sfMusic_setVolume(rpg->sounds->music, 50.0);
    sfSound_setVolume(rpg->sounds->hud->sound, 40);
    sfSound_setVolume(rpg->sounds->knife->sound, 30);
    sfSound_setVolume(rpg->sounds->punch->sound, 50);
}

void set_volume(rpg_t *rpg)
{
    if (rpg->settings->volume == TRUE) {
        volume_off(rpg);
        rpg->settings->volume = FALSE;
        sfText_setString(rpg->menu->txt_sound->txt, "NO");
    } else {
        volume_on(rpg);
        rpg->settings->volume = TRUE;
        sfText_setString(rpg->menu->txt_sound->txt, "YES");
    }
}