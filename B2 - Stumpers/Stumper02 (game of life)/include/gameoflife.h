/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** .h principal au programme
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    char **current_map;
    char **next_map;
    int gen;
    int col;
    int row;
} map_t;

int gameoflife(int argc, char **argv);
void create_map(map_t *map, char *filepath);
int check_errors(int argc, char **argv);
void set_generation(map_t *map);
char **malloc_map(map_t *size);

#endif