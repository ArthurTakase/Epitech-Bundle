/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** struct
*/

#ifndef __STRUCT__H__
#define __STRUCT__H__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define ONE_SPD -1
#define TWO_SPD -3
#define THREE_SPD -5
#define FOUR_SPD -7
#define FIVE_SPD -9
#define SIX_SPD -11
#define DIM_X 1024
#define DIM_Y 512
#define VICTORY 1
#define DEFEAT -1
#define MENU 8
#define GAME 0
#define PAUSE -8

typedef struct s_option
{
    char *level;
    int fps;
} option_t;

typedef struct s_sprite
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f move;
    sfIntRect rect;
    sfVector2f pos;
    int is_jump;
    float jump_height;
    int value;
} sprite_t;

typedef struct s_bg
{
    sprite_t *bg1;
    sprite_t *bg2;
    sprite_t *bg3;
    sprite_t *bg4;
    sprite_t *bg5;
    sprite_t *bg6;
    sprite_t *bg1_b;
    sprite_t *bg2_b;
    sprite_t *bg3_b;
    sprite_t *bg4_b;
    sprite_t *bg5_b;
    sprite_t *bg6_b;
} bg_t;

typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buffer;
} sound_t;

typedef struct s_all_sound
{
    sound_t *footstep;
    sfMusic *music;
    sound_t *jump;
    sound_t *coin;
    sound_t *button;
    sound_t *kill;
    sound_t *victory;
    sound_t *defeat;
} all_sound_t;

typedef struct s_clock
{
    sfClock *clock;
    float limit;
} clocks_t;

typedef struct all_clock
{
    clocks_t *footstep;
    clocks_t *player;
    clocks_t *slime;
    clocks_t *trap;
    clocks_t *bird;
    clocks_t *flag;
    clocks_t *fps;
    clocks_t *coin;
} all_clock_t;

typedef struct s_score
{
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    int score;
} score_t;

typedef struct list_trap_t
{
    sprite_t *trap;
    struct list_trap_t *next;
} list_trap_t, *trap_t;

typedef struct s_button
{
    int x;
    int y;
    int height;
    int width;
} button_t;

typedef struct s_menu
{
    sprite_t *cc_1;
    sprite_t *cc_2;
    score_t *pause;
    sprite_t *win_1;
    sprite_t *level1;
    sprite_t *level2;
    sprite_t *level3;
    sprite_t *level4;
    sprite_t *defeat_1;
    sfSprite *current_bg;
    sfSprite *current_fps;
} menu_t;

typedef struct s_jauge
{
    sprite_t *border;
    sprite_t *full;
} jauge_t;

typedef struct s_run
{
    bg_t *bg;
    char *map;
    int is_over;
    int len_trap;
    int trap_max;
    trap_t trap;
    menu_t *menu;
    score_t *best;
    jauge_t *jauge;
    score_t *score;
    sprite_t *life;
    sprite_t *player;
    sprite_t *cursor;
    sprite_t *filtre;
    option_t *option;
    all_sound_t *sound;
    all_clock_t *clock;
    sfRenderWindow *window;
} run_t;

//----- PROTO -----

void init_window(run_t *run);
void init_background(run_t *run);
void event_all(run_t *run);
void move_all(run_t *run);
void draw_all(run_t *run);
void init_char(run_t *run);
void animation(run_t *run);
void init_sound(run_t *run);
void jump(run_t *run);
void init_all_clock(run_t *run);
void anime_player(run_t *run);
void my_putstr(char const *str);
void footstep(run_t *run);
void anime_trap(run_t *run, int value);
void check_coll(run_t *run);
void delet_trap(run_t *run);
void move_fps(run_t *run);
void init_score(run_t *run);
void check_score(run_t *run);
void init_cursor(run_t *run);
void move_cursor(run_t *run);
void new_trap(run_t *run, char value, int start);
void place_level(run_t *run, char *level);
void init(run_t *run);
void destroy_sprite(run_t *run);
void destroy(run_t *run);
void end_game(run_t *run);
void level_event(run_t *run);
void destroy_no_background(run_t *run);
void destroy_music(run_t *run);
void game_loop(run_t *run);
void button(run_t *run, button_t coord, char *filepath, int index);
void pause_game(run_t *run);
void to_trente(run_t *run, button_t coord);
void to_soixante(run_t *run, button_t coord);
void start_game(run_t *run, button_t coord, int where);
void init_filtre(run_t *run);
void clear_trap(run_t *run);
void init_ui(run_t *run);
void init_jauge(run_t *run);
void edit_jauge(run_t *run);
trap_t clear_list(trap_t li);
trap_t pop_front_list(trap_t li);
trap_t pop_back_list(trap_t li);
trap_t push_front_list(trap_t li, sprite_t *value);
trap_t push_back_list(trap_t li, sprite_t *value);
trap_t new_list(void);
sprite_t *init_void(int pos_x);
sprite_t *init_trap_1(int pos_x);
sprite_t *init_trap_2(int pos_x);
sprite_t *init_trap_3(int pos_x);
sprite_t *init_flag(int pos_x);
sprite_t *init_trap_coin(int pos_x);
sprite_t *init_menu_img(char *filepath);
menu_t *init_menu(run_t *run);
score_t *init_txt(run_t *run, sfVector2f pos, char *script, int size);
clocks_t *init_clock(float limit);
int is_empty_list(trap_t li);
int list_length(trap_t li);
int my_strcmp(char const *s1, char const *s2);
int game(run_t *run);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int options(char **argv);
int get_error(char *filepath);
int check_file(char *argv);
int help(void);
int anime(clocks_t *clock);
int level_menu(run_t *run);
int check_button(run_t *run, button_t coord);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_itos(int value, int base);
char *load_file(char const *filepath);
char *fs_cat_x_bytes(char const *filepath, int x);

//----- PROTO EN COURS -----

void check_best(run_t *run);
void init_best(run_t *run);

#endif