/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** init_menu
*/

#include "rpg.h"
#include <stdlib.h>

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->bg = new_sprite("menu/bg.png",
        (sfIntRect){0, 0, 960, 540}, (sfVector2f){0, 0}, (sfVector2f){0, 0});
    menu->play = new_sprite("menu/jouer_off.png",
        (sfIntRect){0, 0, 225, 50}, (sfVector2f){0, 0}, (sfVector2f){0, 250});
    menu->exit = new_sprite("menu/quitter_off.png",
        (sfIntRect){0, 0, 225, 50}, (sfVector2f){0, 0}, (sfVector2f){0, 400});
    menu->param = new_sprite("menu/param_off.png",
        (sfIntRect){0, 0, 225, 50}, (sfVector2f){0, 0}, (sfVector2f){0, 325});
    menu->sound =  new_sprite("menu/sound.png",
        (sfIntRect){0, 0, 225, 50}, (sfVector2f){0, 0}, (sfVector2f){0, 250});
    menu->frame =  new_sprite("menu/frame.png",
        (sfIntRect){0, 0, 225, 50}, (sfVector2f){0, 0}, (sfVector2f){0, 325});
    menu->txt_frame = new_txt((sfVector2f){200, 340}, "60", 18, 0);
    menu->txt_sound = new_txt((sfVector2f){200, 265}, "YES", 18, 0);
    set_txt(menu->txt_frame, FPS);
    return menu;
}