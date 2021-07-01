/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** new_particles
*/

#include "rpg.h"
#include <stdlib.h>

dlist_t new_particle(dlist_t list, part_param_t param)
{
    list = push_back_dlist(list, new_sprite(param.shape,
                    (sfIntRect){0, 0, 10, 10}, param.move, param.origin));
    sfSprite_setColor(list->end->particle->sprite, param.color);
    list->end->particle->state = 255;
    return list;
}

int update_particle(rpg_t *rpg, sprite_t *particle)
{
    sfVector2f new;
    sfColor color = sfSprite_getColor(particle->sprite);

    new.x = particle->move.x * rpg->dtime;
    new.y = particle->move.y * rpg->dtime;
    sfSprite_move(particle->sprite, new);
    if (particle->state <= 0)
        return 1;
    particle->state -= 1;
    color.a = particle->state;
    sfSprite_setColor(particle->sprite, color);
    return 0;
}

dlist_t show_particles(rpg_t *rpg, dlist_t particles)
{
    dlistnode_t temp;

    if (is_empty_dlist(particles))
        return new_dlist();
    temp = *(particles->begin);
    while (temp.next != NULL) {
        draw_sprite(rpg, temp.particle);
        if (update_particle(rpg, temp.particle))
            particles = pop_front_dlist(particles);
        temp = *(temp.next);
    }
    return particles;
}