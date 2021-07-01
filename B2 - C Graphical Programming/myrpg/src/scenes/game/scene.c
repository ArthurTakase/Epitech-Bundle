/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"

void anime_player_map(rpg_t *rpg)
{
    sprite_t *idle[4] = {rpg->player_map->idle_down, rpg->player_map->idle_up,
                    rpg->player_map->idle_left, rpg->player_map->idle_right};
    sprite_t *walk[4] = {rpg->player_map->walk_down, rpg->player_map->walk_up,
                    rpg->player_map->walk_left, rpg->player_map->walk_right};

    if (anime(rpg->clocks->player_map)) {
        if (rpg->player_map->is_move == FALSE)
            anime_sprite(idle[rpg->player_map->state], 16, 96);
        else
            anime_sprite(walk[rpg->player_map->state], 16, 96);
    }
}

void draw_spr_player(rpg_t *rpg)
{
    sprite_t *idle[4] = {rpg->player_map->idle_down, rpg->player_map->idle_up,
                    rpg->player_map->idle_left, rpg->player_map->idle_right};
    sprite_t *walk[4] = {rpg->player_map->walk_down, rpg->player_map->walk_up,
                    rpg->player_map->walk_left, rpg->player_map->walk_right};

    if (rpg->player_map->is_move == FALSE)
        draw_sprite(rpg, idle[rpg->player_map->state]);
    else
        draw_sprite(rpg, walk[rpg->player_map->state]);
}

void game(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    draw_current_map(rpg);
    set_dtime(rpg);
    game_event(rpg);
    draw_spr_player(rpg);
    anime_player_map(rpg);
    sfClock_restart(rpg->clocks->dtime->clock);
    sfRenderWindow_display(rpg->window);
    manage_level(rpg);
}