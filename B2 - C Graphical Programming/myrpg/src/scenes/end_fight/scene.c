/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"
#include <stdlib.h>

void reset_end(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    rpg->sprites->chest->state = 0;
    free(rpg->infos_fight);
    rpg->fade->in = 255;
    rpg->fade->out = 0;
    if (rpg->player->life > 0) {
        switch_music(rpg, "music.ogg");
        rpg->scene = GAME;
    } else {
        switch_music(rpg, "home_music.ogg");
        rpg->scene = HOME;
    }
}

void draw_victory(rpg_t *rpg)
{
    draw_sprite(rpg, rpg->sprites->chest);
    draw_txt(rpg, rpg->txts->fight_result);
    draw_txt(rpg, rpg->txts->fight_gains);
}

void draw_defeat(rpg_t *rpg)
{
    draw_txt(rpg, rpg->txts->fight_result);
}

void end_fight(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    if (rpg->infos_fight->state == VICTORY)
        draw_victory(rpg);
    else
        draw_defeat(rpg);
    if (rpg->sprites->chest->state == 1)
        if (fade_out(rpg))
            reset_end(rpg);
    anime_end(rpg);
    end_fight_event(rpg);
    set_dtime(rpg);
    sfClock_restart(rpg->clocks->dtime->clock);
    sfRenderWindow_display(rpg->window);
}