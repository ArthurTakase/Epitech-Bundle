/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** infos_ennemis
*/

#include "rpg.h"
#include <stdlib.h>

ennemi_t *null(int i)
{
    ennemi_t *enn = malloc(sizeof(ennemi_t));

    i = i;
    enn->att = 0;
    enn->life = 0;
    enn->state = DEAD_ENN;
    enn->type = EMPTY;
    enn->miss = 100;
    enn->idle = new_sprite("viking/idle.png", (sfIntRect){0, 0, 0, 0},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    enn->attack = new_sprite("viking/attack.png", (sfIntRect){0, 0, 0, 0},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    enn->hurt = new_sprite("viking/hurt.png", (sfIntRect){0, 0, 0, 0},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    enn->dead = new_sprite("viking/dead.png", (sfIntRect){0, 0, 0, 0},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    return enn;
}

ennemi_t *ninja(int i)
{
    ennemi_t *enn = malloc(sizeof(ennemi_t));

    enn->att = 2;
    enn->life = 2;
    enn->state = IDLE_ENN;
    enn->type = NINJA;
    enn->miss = 10;
    enn->idle = new_sprite("ninja/idle.png", (sfIntRect){0, 0, 64, 64},
                    (sfVector2f){0, 0}, (sfVector2f){(141 * i), 368});
    enn->attack = new_sprite("ninja/attack.png", (sfIntRect){0, 0, 70, 64},
                    (sfVector2f){0, 0}, (sfVector2f){(141 * i), 368});
    enn->hurt = new_sprite("ninja/hurt.png", (sfIntRect){0, 0, 64, 64},
                    (sfVector2f){0, 0}, (sfVector2f){(130 * i), 360});
    enn->dead = new_sprite("ninja/dead.png", (sfIntRect){0, 0, 64, 64},
                    (sfVector2f){0, 0}, (sfVector2f){(135 * i), 368});
    return enn;
}

ennemi_t *pirate(int i)
{
    ennemi_t *enn = malloc(sizeof(ennemi_t));

    enn->att = 1;
    enn->life = 4;
    enn->state = IDLE_ENN;
    enn->type = PIRATE;
    enn->miss = 20;
    enn->idle = new_sprite("pirate/idle.png", (sfIntRect){0, 0, 93, 93},
                    (sfVector2f){0, 0}, (sfVector2f){(130 * i), 312});
    enn->attack = new_sprite("pirate/attack.png", (sfIntRect){0, 0, 93, 93},
                    (sfVector2f){0, 0}, (sfVector2f){(136 * i), 312});
    enn->hurt = new_sprite("pirate/hurt.png", (sfIntRect){0, 0, 106, 96},
                    (sfVector2f){0, 0}, (sfVector2f){(120 * i), 303});
    enn->dead = new_sprite("pirate/dead.png", (sfIntRect){0, 0, 106, 96},
                    (sfVector2f){0, 0}, (sfVector2f){(90 * i), 307});
    return enn;
}

ennemi_t *viking(int i)
{
    ennemi_t *enn = malloc(sizeof(ennemi_t));

    enn->att = 1;
    enn->life = 3;
    enn->state = IDLE_ENN;
    enn->type = VIKING;
    enn->miss = 5;
    enn->idle = new_sprite("viking/idle.png", (sfIntRect){0, 0, 64, 78},
                    (sfVector2f){0, 0}, (sfVector2f){(141 * i), 342});
    enn->attack = new_sprite("viking/attack.png", (sfIntRect){0, 0, 91, 90},
                    (sfVector2f){0, 0}, (sfVector2f){(129 * i), 317});
    enn->hurt = new_sprite("viking/hurt.png", (sfIntRect){0, 0, 104, 96},
                    (sfVector2f){0, 0}, (sfVector2f){(115 * i), 292});
    enn->dead = new_sprite("viking/dead.png", (sfIntRect){0, 0, 141, 75},
                    (sfVector2f){0, 0}, (sfVector2f){(90 * i), 349});
    return enn;
}