/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** main
*/

#include "../include/init.h"
#include "../include/my.h"

void init(data_t *data)
{
    data->isStart = 0;
    init_window(data);
    init_cursor(data);
    init_background(data);
    init_duck(data, 10);
    init_tv(data);
    init_score(data);
    init_dog(data);
    init_flash(data);
    init_menu(data);
    init_sound(data);
}

void destroy(data_t *data)
{
    sfSound_destroy(data->sound->dog->sound);
    sfSound_destroy(data->sound->dog_hit->sound);
    sfSound_destroy(data->sound->duck->sound);
    sfSound_destroy(data->sound->duck_hit->sound);
    sfSound_destroy(data->sound->shot->sound);
    sfSoundBuffer_destroy(data->sound->dog->buffer);
    sfSoundBuffer_destroy(data->sound->dog_hit->buffer);
    sfSoundBuffer_destroy(data->sound->duck->buffer);
    sfSoundBuffer_destroy(data->sound->duck_hit->buffer);
    sfSoundBuffer_destroy(data->sound->shot->buffer);
    sfMusic_destroy(data->sound->music);
    sfSprite_destroy(data->duck->sprite);
    sfSprite_destroy(data->background->sprite);
    sfSprite_destroy(data->tv->sprite);
    sfSprite_destroy(data->game_over->sprite);
    sfSprite_destroy(data->cursor->sprite);
    sfSprite_destroy(data->white->sprite);
    sfSprite_destroy(data->menu->sprite);
    sfRenderWindow_destroy(data->window);
}

int main(int argc, char **argv)
{
    data_t *data = malloc(sizeof(data_t));

    if (argc == 1) {
        init(data);
        game(data);
        destroy(data);
    } else if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h')
            my_printf("%s", HELP_STRING);
    }
    return 0;
}