/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"

void draw_menu(rpg_t *rpg)
{
    sprite_t *arr_spr[4] = {rpg->menu->bg, rpg->menu->play, rpg->menu->exit,
                            rpg->menu->param};

    for (int i = 0; i != 4; i++)
        draw_sprite(rpg, arr_spr[i]);
}

void set_opacity_menu(rpg_t *rpg, int scene)
{
    sfSprite *arr_bt[3] = {rpg->menu->play->sprite, rpg->menu->param->sprite,
                            rpg->menu->exit->sprite};

    for (int i = 0; i != 3; i++) {
        if (i == scene)
            sfSprite_setColor(arr_bt[i], (sfColor){255, 255, 255, 255});
        else
            sfSprite_setColor(arr_bt[i], (sfColor){255, 255, 255, 100});
    }
}

void home(rpg_t *rpg)
{
    int scene = get_buttons_home(rpg);

    home_event(rpg, scene);
    set_opacity_menu(rpg, scene);
    draw_menu(rpg);
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