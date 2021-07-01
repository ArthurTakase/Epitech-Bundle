/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** .h principal au programme
*/

#ifndef PROTO_H_
#define PROTO_H_

#define MOVE_BOX 1
#define NO_BOX 2
#define BLOCK_BOX 3
#define VICTORY 4
#define NO_VICTORY 5
#define DEFEAT 6

#include <ncurses.h>

typedef struct s_sizemap
{
    int col;
    int row;
} sizemap_t;

typedef struct s_player
{
    int x;
    int y;
} player_t;

typedef struct s_map
{
    char *map;
    char **new_map;
    sizemap_t *size;
    int x;
    int y;
} map_t;

typedef struct s_soko
{
    char **map;
    char **map_save;
    char *original_map;
    int *end_x;
    int *end_y;
    int end_value;
    int nb_box;
    sizemap_t *size;
    player_t *player;
} soko_t;

int sokoban(int argc, char **argv);
int get_error(int argc, char **argv);
char **create_map(char *map, soko_t *soko);
int move_player(int key, soko_t *soko);
void print_soko(soko_t *soko);
char **clone_2d(char **src);
void set_player(int x, int y, soko_t *soko);
int check_coll(int x, int y, soko_t *soko);
void up(soko_t *soko);
void down(soko_t *soko);
void left(soko_t *soko);
void right(soko_t *soko);
int is_box_good(soko_t *soko, int x, int y);
void move_box(soko_t *soko, int x, int y);
int usage(int argc, char **argv);
int how_many(char letter, char *src);
int victory(soko_t *soko);
int defeat(soko_t *soko);
void new_sokoban(soko_t *soko);

#endif