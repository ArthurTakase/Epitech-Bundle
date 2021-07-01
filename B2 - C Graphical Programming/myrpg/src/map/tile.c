/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** tile
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

int len_tiles(tile_t *tiles)
{
    tile_t *tmp =  tiles;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

char *no_png(char *path)
{
    char *result = clonestr(path + 6);
    int len = my_strlen(result);

    result[len - 4] = '\0';
    return result;
}

tile_t *create_tile(tile_t *t, char *path, sfVector2f pos)
{
    tile_t *new = malloc(sizeof(tile_t));

    sfIntRect rect = {0, 0, 16, 16};
    sfVector2f move = {0, 0};
    new->pos = pos;
    new->s = new_sprite(path, rect, move, pos);
    new->id = no_png(path);
    sfSprite_setScale(new->s->sprite, (sfVector2f){3, 3});
    if (t == NULL)
        new->next = NULL;
    else
        new->next = t;
    return new;
}

void destroy_tile(map_t **m, int pos)
{
    int length = len_tiles((*m)->clone);

    if (pos > 0 && pos < length) {
        delete_middle((*m)->clone, pos);
    }
    else if (pos == 0) {
        delete_first(&(*m)->clone);
    }
}

void destroy_tiles(rpg_t *rpg)
{
    tile_t *tiles = rpg->tiles;
    tile_t *tmp = tiles;

    while (tiles != NULL) {
        tmp = tiles->next;
        delet_sprite(tiles->s);
        free(tiles);
        tiles = tmp;
    }
}