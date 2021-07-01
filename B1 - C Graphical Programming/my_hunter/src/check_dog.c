/*
** EPITECH PROJECT, 2020
** myhunter
** File description:
** check_dog
*/

#include "../include/csfml.h"

void check_dog_colider(data_t *data)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f dog_pos = sfSprite_getPosition(data->dog->sprite);

    if (mouse_pos.x < dog_pos.x + 110 && mouse_pos.y < dog_pos.y + 100 &&
        mouse_pos.x > dog_pos.x && mouse_pos.y > dog_pos.y
        && data->tv->rect.left != 2880) {
        sfSound_play(data->sound->dog_hit->sound);
        sfRenderWindow_drawSprite(data->window, data->white->sprite, NULL);
        data->tv->rect.left = 2880;
        sfSprite_setTextureRect(data->tv->sprite, data->tv->rect);
    }
}