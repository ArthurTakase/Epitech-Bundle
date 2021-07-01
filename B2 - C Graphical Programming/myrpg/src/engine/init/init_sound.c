/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_sound
*/

#include "rpg.h"
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

void switch_music(rpg_t *rpg, char *music)
{
    sfMusic_destroy(rpg->sounds->music);
    rpg->sounds->music = play_music(music, 50);
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

all_sound_t *init_sounds(void)
{
    all_sound_t *sounds = malloc(sizeof(all_sound_t));

    sounds->music = play_music("home_music.ogg", 50.0);
    sounds->hud = create_sound("fight/hud.ogg", 40);
    sounds->knife = create_sound("fight/knife.flac", 30);
    sounds->punch = create_sound("fight/punch.wav", 50);
    return sounds;
}