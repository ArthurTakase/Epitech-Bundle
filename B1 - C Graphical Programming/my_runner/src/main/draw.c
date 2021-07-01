/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** draw
*/

#include "struct.h"

void set_parallax(run_t *run)
{
    int arr_mv[6] = {ONE_SPD, TWO_SPD, THREE_SPD, FOUR_SPD, FIVE_SPD, SIX_SPD};
    sprite_t *arr_bg[6] = {run->bg->bg1, run->bg->bg2, run->bg->bg3,
                            run->bg->bg4, run->bg->bg5, run->bg->bg6};
    sprite_t *arr_bg2[6] = {run->bg->bg1_b, run->bg->bg2_b, run->bg->bg3_b,
                            run->bg->bg4_b, run->bg->bg5_b, run->bg->bg6_b};

    for (int i = 0; i < 6; ++i)
        if (sfSprite_getPosition(arr_bg[i]->sprite).x + arr_mv[i] < -DIM_X)
            sfSprite_setPosition(arr_bg[i]->sprite, arr_bg[i]->pos);
    for (int i = 0; i < 6; ++i)
        if (sfSprite_getPosition(arr_bg2[i]->sprite).x + arr_mv[i] < 0)
            sfSprite_setPosition(arr_bg2[i]->sprite, arr_bg2[i]->pos);
}

void move_fps(run_t *run)
{
    sfTime time;

    time = sfClock_getElapsedTime(run->clock->fps->clock);
    if (sfTime_asSeconds(time) > run->clock->fps->limit) {
        move_all(run);
        sfClock_restart(run->clock->fps->clock);
    }
}

void move_all(run_t *run)
{
    sprite_t *arr_mv[12] = {run->bg->bg1, run->bg->bg1_b, run->bg->bg2,
            run->bg->bg2_b, run->bg->bg3, run->bg->bg3_b, run->bg->bg4,
            run->bg->bg4_b, run->bg->bg5, run->bg->bg5_b, run->bg->bg6,
            run->bg->bg6_b};
    trap_t temp = run->trap;

    set_parallax(run);
    for (int i = 0; i < 12; ++i)
        sfSprite_move(arr_mv[i]->sprite, arr_mv[i]->move);
    while (temp != NULL) {
        sfSprite_move(temp->trap->sprite, temp->trap->move);
        temp = temp->next;
    }
}

void draw_all(run_t *run)
{
    sfRenderWindow *window = run->window;
    sprite_t *arr_sprt[13] = {run->bg->bg1, run->bg->bg1_b, run->bg->bg2,
            run->bg->bg2_b, run->bg->bg3, run->bg->bg3_b, run->bg->bg4,
            run->bg->bg4_b, run->bg->bg5, run->bg->bg5_b, run->player,
            run->bg->bg6, run->bg->bg6_b};
    trap_t temp = run->trap;

    for (int i = 0; i < 11; ++i)
        sfRenderWindow_drawSprite(window, arr_sprt[i]->sprite, NULL);
    while (temp != NULL) {
        if (sfSprite_getPosition(temp->trap->sprite).x > 1200)
            break;
        sfRenderWindow_drawSprite(run->window, temp->trap->sprite, NULL);
        temp = temp->next;
    }
    for (int i = 11; i < 13; ++i)
        sfRenderWindow_drawSprite(window, arr_sprt[i]->sprite, NULL);
    move_cursor(run);
}