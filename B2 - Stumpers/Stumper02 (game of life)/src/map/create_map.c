/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper2-arthur.decaen
** File description:
** create_map
*/

#include "gameoflife.h"
#include "lib.h"
#include <string.h>

char **malloc_map(map_t *size)
{
    char **new_map = malloc(sizeof(char *) * (size->row + 1));

    if (size == NULL || new_map == NULL)
        exit (84);
    for (int i = 0; i < size->row; i++) {
        new_map[i] = malloc(sizeof(char) * (size->col + 1));
        if (new_map[i] == NULL)
            exit(84);
    }
    return new_map;
}

int check_map(char *file, map_t *size)
{
    int temp_col = 0;
    char is_ok[3] = {'X', '.', '\n'};

    for (int i = 0; file[i] != '\0'; i++) {
        if (!my_in(file[i], is_ok))
            return 1;
        if (file[i] != '\n') {
            if (size->row == 0)
                size->col += 1;
            else
                temp_col++;
        } else {
            if (size->row != 0 && size->col != temp_col)
                return 1;
            size->row += 1;
            temp_col = 0;
        }
    }
    return 0;
}

void fill_map(char *file, map_t *map)
{
    int x = 0;
    int y = 0;

    if (file == NULL || map == NULL)
        exit(84);
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n') {
            map->current_map[y][x] = '\0';
            y++;
            x = 0;
            continue;
        }
        map->current_map[y][x] = file[i];
        x++;
    }
    map->current_map[y] = NULL;
}

void create_map(map_t *map, char *filepath)
{
    char *file;
    
    if (map == NULL || filepath == NULL)
        exit(84);
    file = load_file(filepath);
    map->col = 0;
    map->row = 0;
    if (check_map(file, map) || file[strlen(file) - 1] != '\n') {
        free(file);
        exit(84);
    }
    map->current_map = malloc_map(map);
    map->next_map = malloc_map(map);
    fill_map(file, map);
}