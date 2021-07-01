/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** launch
*/

#include "rpg.h"

void launch_fight(rpg_t *rpg)
{
    rpg->fight = init_fight();
    sfSprite_setPosition(rpg->sprites->mouse->sprite, (sfVector2f){770, 300});
    sfSprite_setOrigin(rpg->fade->circle->sprite, (sfVector2f){960, 540});
    rpg->sprites->mouse->state = ATT;
    rpg->scene = FIGHT;
    rpg->player->state = IDLE;
    rpg->sprites->punch->state = 1;
    rpg->sprites->slash->state = 1;
    rpg->fight->state = 0;
    rpg->fade->in = 255;
    rpg->fade->out = 0;
    switch_music(rpg, "fight/music2.ogg");
    sfRenderWindow_display(rpg->window);
}