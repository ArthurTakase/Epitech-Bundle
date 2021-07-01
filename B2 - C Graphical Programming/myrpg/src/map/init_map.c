/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_map
*/

#include "rpg.h"
#include "lib.h"
#include <dirent.h>
#include <stdlib.h>

void init_buttons(map_t *m)
{
    DIR *tile = opendir("asset/img/tiles/");
    struct dirent *dir = readdir(tile);
    char *path = NULL;

    sfIntRect rect = {0, 0, 16, 16};
    sfVector2f pos = {(90 * WIN_W) / 100, (5 * WIN_H) / 100};
    m->b = NULL;
    while (dir != NULL) {
        if (my_strcmp(dir->d_name, "..") != 0 &&
        my_strcmp(dir->d_name, ".") != 0) {
            path = my_strcat("tiles/", dir->d_name);
            m->b = new_button(rect, path, pos, m->b);
            pos.y += (20 * WIN_H) / 100;
        }
        dir = readdir(tile);
    }
    closedir(tile);
}

map_t *init_map(tile_t *t, int tex_id)
{
    map_t *new = malloc(sizeof(map_t));

    new->type = TERRE;
    new->clone = t;
    new->state = 1;
    new->size = 0;
    new->pos = (sfVector2f){0, 0};
    new->clone = create_tile(NULL, get_name_from_id(tex_id), new->pos);
    new->save_button = init_simple_button((sfVector2f){100, 100}, "tamere.png");
    init_buttons(new);
    return new;
}