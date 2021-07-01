/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** init_sound
*/

#include "struct.h"

sfMusic *play_music(void)
{
    sfMusic *music = sfMusic_createFromFile("asset/sound/music.ogg");

    sfMusic_setVolume(music, 50.0);
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

void init_sound(run_t *run)
{
    all_sound_t *sound = malloc(sizeof(all_sound_t));

    sound->music = play_music();
    sound->jump = sound_create("asset/sound/Jump01.wav", 20.0);
    sound->footstep = sound_create("asset/sound/footstep.wav", 0.0);
    sound->coin = sound_create("asset/sound/coin-1.wav", 30.0);
    sound->button = sound_create("asset/sound/click1.ogg", 50.0);
    sound->defeat = sound_create("asset/sound/Death02.wav", 50.0);
    sound->kill = sound_create("asset/sound/hit-3.wav", 50.0);
    sound->victory = sound_create("asset/sound/win-8.wav", 50.0);
    run->sound = sound;
}