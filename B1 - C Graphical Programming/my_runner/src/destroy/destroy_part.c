/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** destroy_part
*/

#include "struct.h"

void destroy_sprite(run_t *run)
{
    sprite_t *arr_mv[25] = {run->bg->bg1, run->bg->bg1_b, run->bg->bg2,
            run->bg->bg2_b, run->bg->bg3, run->bg->bg3_b, run->bg->bg4,
            run->bg->bg4_b, run->bg->bg5, run->bg->bg5_b, run->bg->bg6,
            run->bg->bg6_b, run->cursor, run->menu->defeat_1, run->player,
            run->menu->cc_1, run->menu->cc_2, run->menu->level1,
            run->menu->level2, run->menu->level3, run->menu->level4,
            run->jauge->border, run->jauge->full, run->life, run->filtre};

    for (int i = 0; i < 25; ++i)
        sfSprite_destroy(arr_mv[i]->sprite);
}

void destroy_music(run_t *run)
{
    sfMusic_destroy(run->sound->music);
    sfSound_destroy(run->sound->footstep->sound);
    sfSound_destroy(run->sound->jump->sound);
    sfSound_destroy(run->sound->coin->sound);
    sfSound_destroy(run->sound->victory->sound);
    sfSound_destroy(run->sound->kill->sound);
    sfSound_destroy(run->sound->defeat->sound);
    sfSoundBuffer_destroy(run->sound->coin->buffer);
    sfSoundBuffer_destroy(run->sound->footstep->buffer);
    sfSoundBuffer_destroy(run->sound->jump->buffer);
    sfSoundBuffer_destroy(run->sound->defeat->buffer);
    sfSoundBuffer_destroy(run->sound->kill->buffer);
    sfSoundBuffer_destroy(run->sound->victory->buffer);
}

void clear_trap(run_t *run)
{
    trap_t temp = run->trap;

    while (temp != NULL) {
        sfSprite_destroy(temp->trap->sprite);
        temp = temp->next;
    }
}