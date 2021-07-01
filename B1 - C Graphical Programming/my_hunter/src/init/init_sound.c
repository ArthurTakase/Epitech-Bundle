/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** init_sound
*/

#include "../../include/csfml.h"
#include "../../include/my.h"

sfMusic *play_music(void)
{
    sfMusic *music = sfMusic_createFromFile("asset/music/music.ogg");

    sfMusic_setVolume(music, 7.0);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return music;
}

sound_t *sound_create(char const *link, float volume)
{
    sound_t *sound_param = malloc(sizeof(sound_t));
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(link);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    sfSound_setVolume(sound, volume);
    sound_param->buffer = buffer;
    sound_param->sound = sound;
    return sound_param;
}

void init_sound(data_t *data)
{
    all_sound_t *sound = malloc(sizeof(all_sound_t));

    sound->music = play_music();
    sound->duck_hit = sound_create("asset/sound/duck_hit.ogg", 100.0);
    sound->duck = sound_create("asset/sound/duck.ogg", 100.0);
    sound->dog_hit = sound_create("asset/sound/dog_sad.ogg", 100.0);
    sound->dog = sound_create("asset/sound/dog.ogg", 100.0);
    sound->shot = sound_create("asset/sound/shot.ogg", 50.0);
    data->sound = sound;
}