/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#define HOME 0
#define GAME 1
#define PAUSE 2
#define TOWER 3
#define EXIT 4
#define SETTINGS 5
#define HOW 6
#define END 7

#define MOVE1 0.05
#define MOVE2 -0.025

#define FPS 60
#define ON 1
#define OFF 0

#define RANGE 65.0
#define MONEY_BASE 20
#define REWARD 5
#define LIFE 5
#define TIME_MONEY 1
#define TIME_REWARD 1
#define CAR_TIMER 1.5

typedef struct s_clock
{
    sfClock *clock;
    float limit;
} clocks_t;

typedef struct all_clock
{
    clocks_t *dt_game;
    clocks_t *dt_pause;
    clocks_t *dt_home;
    clocks_t *btn;
    clocks_t *car;
    clocks_t *money;
} all_clock_t;

typedef struct s_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f move;
    sfVector2f pos;
    sfIntRect rect;
    clocks_t *timer;
    int state;
    float life;
    float speed;
    int att;
    int is_kill;
} sprite_t;

typedef struct s_all_sprites
{
    sprite_t *mouse;
    sprite_t *btn_exit;
    sprite_t *btn_menu;
    sprite_t *btn_start;
    sprite_t *pause;
    sprite_t *map;
    sprite_t *home;
    sprite_t *sett;
    sprite_t *how;
    sprite_t *screen;
    sprite_t *sound;
    sprite_t *check1;
    sprite_t *check2;
    sprite_t *check3;
    sprite_t *check4;
    sprite_t *end;
    sprite_t *hud;
    sprite_t *ui;
    sprite_t *life;
    sprite_t *lose;
    sprite_t *win;
    sprite_t *wave;
    sprite_t *infos;
} all_sprite_t;

typedef struct s_zones
{
    sprite_t *zone1;
    sprite_t *zone2;
    sprite_t *zone3;
    sprite_t *zone4;
    sprite_t *zone5;
    sprite_t *zone6;
} zone_t;

typedef struct s_txt
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    int value;
    char *txt_char;
} txt_t;

typedef struct s_button
{
    int x;
    int y;
    int width;
    int height;
} btn_t;

typedef struct list_trap_t
{
    sprite_t *trap;
    struct list_trap_t *next;
} list_trap_t, *trap_t;

typedef struct s_coord
{
    int x;
    int y;
} coord_t;

typedef struct s_stat
{
    float att;
    float life;
    float speed;
    float timer;
} stat_t;

typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buff;
} sound_t;

typedef struct s_all_sound
{
    sfMusic *music;
    sound_t *build;
    sound_t *click;
} all_sound_t;

typedef struct s_waves
{
    int ennemies;
    int spawned;
    int alive;
} waves_t;

typedef struct s_defender
{
    int scene;
    int is_vol;
    int is_full;
    int life;
    int best;
    txt_t *money;
    txt_t *fps;
    txt_t *score;
    txt_t *enn_left;
    sfRenderWindow *window;
    all_clock_t *clocks;
    all_sprite_t *sprites;
    all_sound_t *sounds;
    zone_t *zones;
    sprite_t **arr_z;
    int current_zone;
    trap_t trap;
    trap_t tower;
    waves_t *waves;
    int current_wave;
    sfVector2f *arr_move;
} defender_t;

int help(void);
void init(defender_t *defender);
void init_window(defender_t *defender);
txt_t *init_txt(sfVector2f pos, char *txt, int size, int value);
void init_all_clock(defender_t *defender);
void init_sprites(defender_t *defender);
void init_zones(defender_t *def);
void init_sounds(defender_t *def);
waves_t *init_wave(defender_t *def);
clocks_t *init_clock(float limit);
sprite_t *new_sprite(char *file, sfIntRect rect,
                    sfVector2f move, sfVector2f pos);
int gameloop(defender_t *defender);
void home(defender_t *defender);
void game(defender_t *defender);
void s_pause(defender_t *defender);
void tower(defender_t *defender);
void settings(defender_t *def);
void how(defender_t *def);
void draw_all(defender_t *def);
void move_cursor(defender_t *def);
void move_all(defender_t *def);
int check_button(defender_t *defender, btn_t coord);
void restart_other_clock(defender_t *def);
void destroy(defender_t *def);
trap_t new_list(void);
int is_empty_list(trap_t li);
int list_length(trap_t li);
trap_t push_back_list(trap_t li, sprite_t *value);
trap_t push_front_list(trap_t li, sprite_t *value);
trap_t pop_back_list(trap_t li);
trap_t pop_front_list(trap_t li);
trap_t clear_list(trap_t li);
trap_t pop_index_list(trap_t li, trap_t element);
void animation(defender_t *def);
void move_enn(defender_t *def);
void delet_trap(defender_t *def);
void go_to(defender_t *def, int scene);
void end(defender_t *def);
void set_fps(defender_t *def);
void set_volume(defender_t *def);
void set_fullscreen(defender_t *def);
void check_hover(defender_t *def, sfSprite *sprite, btn_t coords);
void check_click(sprite_t *sprite, int rect);
int anime(clocks_t *clock);
void collider(defender_t *def);
void set_money(defender_t *def, int new);
void set_wave_value(defender_t *def);
void draw_sprite(defender_t *def, sprite_t *sprite);
void check_best(defender_t *def);
void hover_tower(defender_t *def);

#endif