/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** scene
*/

#include "rpg.h"
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void switch_map(rpg_t *rpg, char *map)
{
    if (!rpg->is_load || my_strcmp(map, rpg->current_map)) {
        rpg->current_map = map;
        rpg->map = load_map(rpg->current_map, rpg);
    }
}