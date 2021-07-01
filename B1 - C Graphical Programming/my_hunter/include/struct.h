/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct s_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f move;
} sprite_t;

typedef struct s_score
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int scr;
} score_t;

typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct s_all_sound
{
    sound_t *duck;
    sound_t *duck_hit;
    sound_t *dog;
    sound_t *dog_hit;
    sound_t *shot;
    sfMusic *music;
} all_sound_t;

typedef struct s_data
{
    sprite_t *duck;
    sprite_t *background;
    sprite_t *tv;
    sprite_t *game_over;
    sprite_t *cursor;
    sprite_t *white;
    sprite_t *menu;
    sprite_t *dog;
    score_t *score;
    all_sound_t *sound;
    sfRenderWindow *window;
    int isStart;
} data_t;