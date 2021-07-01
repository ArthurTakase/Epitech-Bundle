/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** read
*/

#include "rpg.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

char *get_name_from_id(int id)
{
    char *name_arr[5] = {GASON, HERBE, P_FLEUR, SABLE, TERRE};

    return name_arr[id];
}

static map_t *fill_map(char *content, map_t *map, size_t len)
{
    int id = 0;
    int x = 0;
    int y = 0;

    for (size_t i = 0; i < len; i += 5) {
        id = (int)content[i];
        x |= (unsigned char)content[i + 2];
        x = x << 8;
        x |= (unsigned char)content[i + 1];
        y |= (unsigned char)content[i + 4];
        y = y << 8;
        y |= (unsigned char)content[i + 3];
        map->clone = create_tile(map->clone, get_name_from_id(id),
        (sfVector2f){(float)x, (float)y});
        x = 0;
        y = 0;
    }
    return map;
}

map_t *load_map(char *path, rpg_t *rpg)
{
    FILE *save = fopen(path, "r");
    char *content;
    size_t len = 0;
    map_t *map;

    len = getline(&content, &len, save);
    map = init_map(NULL, content[0]);
    map = fill_map(content, map, len);
    fclose(save);
    map->size = len / 5;
    rpg->is_load = 1;
    return map;
}