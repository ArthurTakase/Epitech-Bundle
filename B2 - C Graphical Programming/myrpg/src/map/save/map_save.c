/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** map_save
*/

#include "rpg.h"
#include "lib.h"
#include <unistd.h>

int get_id_from_name(char *name)
{
    char *name_arr[5] = {"gason", "herbe", "petites_fleurs", "sable", "terre"};

    for (int i = 0; i != 5; i++) {
        if (!my_strcmp(name, name_arr[i]))
            return i;
    }
    return -1;
}

void save_map(map_t *map)
{
    tile_t *temp = map->clone;
    int get_id;
    sfVector2f pos;
    short x;
    short y;

    for (; temp != NULL; temp = temp->next) {
        get_id = get_id_from_name(temp->id);
        pos = sfSprite_getPosition(temp->s->sprite);
        x = (short)pos.x;
        y = (short)pos.y;
        write(1, &get_id, 1);
        write(1, &x, 2);
        write(1, &y, 2);
    }
}