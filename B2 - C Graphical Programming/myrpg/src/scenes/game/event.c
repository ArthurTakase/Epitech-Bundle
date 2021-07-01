/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"
#include <stdlib.h>

void move_player(rpg_t *rpg, int dir)
{
    float move = rpg->player_map->move;
    sfVector2f arr_v[4] = {(sfVector2f){0, -move}, (sfVector2f){0, move},
                        (sfVector2f){move, 0}, (sfVector2f){-move, 0}};

    rpg->player_map->state = dir;
    rpg->player_map->is_move = TRUE;
    map_deplacement(rpg, rpg->map, arr_v[rpg->player_map->state], 'p');
    if (rand() % SPAWN_FIGHT == 0)
        launch_fight(rpg);
}

void get_pressed_key(rpg_t *rpg, sfEvent *event)
{
    sfKeyCode key_move[4] = {rpg->player_map->down, rpg->player_map->up,
                            rpg->player_map->left, rpg->player_map->right};

    for (int i = 0; i < 4; i++)
        if (event->key.code == key_move[i])
            move_player(rpg, i);
}

void game_event_part(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyEscape)
            go_to_inventory(rpg);
        else
            get_pressed_key(rpg, event);
    }
    if (event->type == sfEvtKeyReleased)
        rpg->player_map->is_move = FALSE;
}

void game_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        game_event_part(rpg, &event);
}