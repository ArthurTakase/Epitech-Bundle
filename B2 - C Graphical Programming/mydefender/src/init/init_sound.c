/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sound
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

sfMusic *play_music(char const *file, float vol)
{
    char *filepath = my_strcat("asset/sound/", file);
    sfMusic *music = sfMusic_createFromFile(filepath);

    sfMusic_setVolume(music, vol);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    free(filepath);
    return music;
}

sound_t *create_sound(char const *file, float vol)
{
    sound_t *sound = malloc(sizeof(sound_t));
    char *filepath = my_strcat("asset/sound/", file);
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(filepath);
    sfSound *audio = sfSound_create();

    sfSound_setBuffer(audio, buff);
    sfSound_setVolume(audio, vol);
    sound->buff = buff;
    sound->sound = audio;
    free(filepath);
    return sound;
}

void init_sounds(defender_t *def)
{
    all_sound_t *sounds = malloc(sizeof(all_sound_t));

    sounds->build = create_sound("build.ogg", 100.0);
    sounds->click = create_sound("click.ogg", 100.0);
    sounds->music = play_music("music.ogg", 50.0);
    def->sounds = sounds;
}