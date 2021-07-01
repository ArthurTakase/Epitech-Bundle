/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** move_enn (sfVector2f){0.016, -0.008}
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

void delet_trap(defender_t *def)
{
    sfIntRect *rect = &def->sprites->life->rect;

    if (is_empty_list(def->trap))
        return;
    if (def->trap->trap->state >= 5) {
        if (def->trap->trap->is_kill == OFF) {
            def->life -= 1;
            rect->top += 41;
            set_wave_value(def);
            sfSprite_setTextureRect(def->sprites->life->sprite, *rect);
            if (def ->life == 0) {
                check_best(def);
                def->scene = END;
            }
        }
        sfSprite_destroy(def->trap->trap->sprite);
        def->trap = pop_front_list(def->trap);
    }
}

void anime_car(trap_t temp)
{
    switch (temp->trap->state) {
        case 0:
        case 4:
            temp->trap->rect.left = 0;
            break;
        case 1:
        case 3:
            temp->trap->rect.left = 96;
            break;
        case 2:
            temp->trap->rect.left = 64;
            break;
        case 5:
            return;
    }
    sfSprite_setTextureRect(temp->trap->sprite, temp->trap->rect);
}

void move_enn(defender_t *def)
{
    trap_t temp = def->trap;
    all_sprite_t *s = def->sprites;
    sprite_t *arr_s[5] = {s->check1, s->check2, s->check3, s->check4, s->end};
    sfFloatRect car;
    sfFloatRect check;

    while (temp != NULL) {
        car = sfSprite_getGlobalBounds(temp->trap->sprite);
        check = sfSprite_getGlobalBounds(arr_s[temp->trap->state]->sprite);
        if (sfFloatRect_intersects(&car, &check, NULL)) {
            temp->trap->state += 1;
            if (temp->trap->state != 5)
                temp->trap->move = def->arr_move[temp->trap->state];
            anime_car(temp);
        }
        temp = temp->next;
    }
}