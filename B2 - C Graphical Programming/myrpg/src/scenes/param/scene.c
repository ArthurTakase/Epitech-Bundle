/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** scene
*/

#include "rpg.h"

void set_opacity_param(rpg_t *rpg, int param)
{
    sfSprite *arr_bt[2] = {rpg->menu->sound->sprite, rpg->menu->frame->sprite};

    for (int i = 0; i != 2; i++) {
        if (i == param)
            sfSprite_setColor(arr_bt[i], (sfColor){255, 255, 255, 255});
        else
            sfSprite_setColor(arr_bt[i], (sfColor){255, 255, 255, 100});
    }
}

void draw_param(rpg_t *rpg)
{
    sprite_t *arr_spr[3] = {rpg->menu->bg, rpg->menu->frame, rpg->menu->sound};

    for (int i = 0; i != 3; i++)
        draw_sprite(rpg, arr_spr[i]);
    draw_txt(rpg, rpg->menu->txt_frame);
    draw_txt(rpg, rpg->menu->txt_sound);
}

void param(rpg_t *rpg)
{
    int param = get_buttons_param(rpg);

    param_event(rpg, param);
    set_opacity_param(rpg, param);
    draw_param(rpg);
    set_dtime(rpg);
    if (anime(rpg->clocks->particule))
        rpg->particle = new_particle(rpg->particle,
            (part_param_t){get_mouse_2f(rpg), sfWhite,
            (sfVector2f){RandomFloat(-0.01, 0.01), RandomFloat(-0.05, -0.01)},
            "particle.png"});
    rpg->particle = show_particles(rpg, rpg->particle);
    move_cursor(rpg);
    sfRenderWindow_display(rpg->window);
    sfClock_restart(rpg->clocks->dtime->clock);
}