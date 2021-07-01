/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_zones
*/

#include "defender.h"
#include <stdlib.h>

void init_zone_arr(defender_t *def)
{
    def->arr_z = malloc(sizeof(sprite_t) * 6);
    def->arr_z[0] = def->zones->zone1;
    def->arr_z[1] = def->zones->zone2;
    def->arr_z[2] = def->zones->zone3;
    def->arr_z[3] = def->zones->zone4;
    def->arr_z[4] = def->zones->zone5;
    def->arr_z[5] = def->zones->zone6;
}

void init_zones(defender_t *def)
{
    zone_t *zones = malloc(sizeof(zone_t));

    zones->zone1 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){419, 221});
    zones->zone2 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){515, 335});
    zones->zone3 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){582, 238});
    zones->zone4 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){485, 195});
    zones->zone5 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){293, 225});
    zones->zone6 = new_sprite("zone.png", (sfIntRect){0, 0, 54, 28},
                            (sfVector2f){0, 0}, (sfVector2f){643, 271});
    def->zones = zones;
    init_zone_arr(def);
}