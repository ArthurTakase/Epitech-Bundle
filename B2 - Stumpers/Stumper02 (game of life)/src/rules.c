/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper2-arthur.decaen
** File description:
** rules
*/

#include "gameoflife.h"
#include "lib.h"

int is_ok(int x, int y, map_t *map)
{
    if (map == NULL)
        exit(84);
    if (x <= 0 || y <= 0)
        return 0;
    if (x >= map->col || y >= map->row)
        return 0;
    return 1;
}

int count_x(map_t *map, int x, int y)
{
    int count = 0;

    if (is_ok(x + 1, y, map) && map->current_map[y][x + 1] == 'X')
        count++;
    if (is_ok(x + 1, y + 1, map) && map->current_map[y + 1][x + 1] == 'X')
        count++;
    if (is_ok(x + 1, y - 1, map) && map->current_map[y - 1][x + 1] == 'X')
        count++;
    if (is_ok(x, y - 1, map) && map->current_map[y - 1][x] == 'X')
        count++;
    if (is_ok(x, y + 1, map) && map->current_map[y + 1][x] == 'X')
        count++;
    if (is_ok(x - 1, y - 1, map) && map->current_map[y - 1][x - 1] == 'X')
        count++;
    if (is_ok(x - 1, y, map) && map->current_map[y][x - 1] == 'X')
        count++;
    if (is_ok(x - 1, y + 1, map) && map->current_map[y + 1][x - 1] == 'X')
        count++;
    return count;
}

void point_rule(map_t *map, int x, int y, int nb_x)
{
    if (map == NULL)
        exit(84);
    map->next_map[y][x] = '.';
    if (nb_x == 3)
        map->next_map[y][x] = 'X';
}

void x_rule(map_t *map, int x, int y, int nb_x)
{
    if (map == NULL)
        exit(84);
    map->next_map[y][x] = 'X';
    if (nb_x <= 1)
        map->next_map[y][x] = '.';
    if (nb_x >= 4)
        map->next_map[y][x] = '.';
}

void set_generation(map_t *map)
{
    int nb_x;

    if (map == NULL)
        exit(84);
    for (int y = 0; map->current_map[y] != NULL; y++) {
        for (int x = 0; map->current_map[y][x] != '\0'; x++) {
            nb_x = count_x(map, x, y);
            if (map->current_map[y][x] == '.')
                point_rule(map, x, y, nb_x);
            else
                x_rule(map, x, y, nb_x);
        }
    }
}