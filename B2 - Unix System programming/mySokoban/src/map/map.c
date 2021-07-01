/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** map
*/

#include "proto.h"
#include "lib.h"
#include <stdlib.h>

sizemap_t *get_size(char *map, soko_t *soko)
{
    sizemap_t *size = malloc(sizeof(sizemap_t));
    int temp_col = 0;

    size->col = 0;
    size->row = 1;
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            size->row += 1;
            if (size->col < temp_col)
                size->col = temp_col;
            temp_col = 0;
        } else
            temp_col += 1;
    }
    soko->size = size;
    return size;
}

char **malloc_map(sizemap_t *size)
{
    char **new_map = malloc(sizeof(char *) * (size->row + 1));

    for (int i = 0; i < size->row; i++)
        new_map[i] = malloc(sizeof(char) * (size->col + 1));
    return new_map;
}

void add_src_point(soko_t *soko, int x, int y)
{
    static int i = 0;

    if (i >= soko->nb_box)
        return;
    soko->end_x[i] = x;
    soko->end_y[i] = y;
    i++;
}

void create_map_part(soko_t *soko, map_t *map_all, int j)
{
    if (map_all->map[j] == '\n') {
        while (map_all->x < map_all->size->col) {
            map_all->new_map[map_all->y][map_all->x] = ' ';
            map_all->x += 1;
        }
        map_all->y += 1;
        map_all->x = 0;
    } else {
        if (map_all->map[j] == 'P') {
            set_player(map_all->x, map_all->y, soko);
            map_all->map[j] = ' ';
        }
        if (map_all->map[j] == 'O')
            add_src_point(soko, map_all->x, map_all->y);
        map_all->new_map[map_all->y][map_all->x] = map_all->map[j];
        map_all->x += 1;
    }
}

char **create_map(char *map, soko_t *soko)
{
    map_t *map_all = malloc(sizeof(map_t));
    map_all->map = map;
    map_all->size = get_size(map, soko);
    map_all->new_map = malloc_map(map_all->size);
    map_all->y = 0;
    map_all->x = 0;

    for (int j = 0; map[j] != '\0'; j++) {
        create_map_part(soko, map_all, j);
    }
    return map_all->new_map;
}