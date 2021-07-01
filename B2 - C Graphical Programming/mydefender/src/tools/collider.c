/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** collider
*/

#include "defender.h"

#include <math.h>

void check_victory(defender_t *def)
{
    if (def->waves->alive == 0 && def->current_wave == 6) {
        def->scene = END;
        check_best(def);
    }
}

float distance(sprite_t *car, sprite_t *tower)
{
    sfVector2f c_tower = {tower->pos.x + (tower->rect.width / 2),
                        tower->pos.y + (tower->rect.height / 2)};
    sfVector2f pos_car = sfSprite_getPosition(car->sprite);
    sfVector2f c_car = {pos_car.x + (car->rect.width / 2),
                        pos_car.y + (car->rect.height / 2)};
    int cal_p1 = (c_tower.x - c_car.x) * (c_tower.x - c_car.x);
    int cal_p2 = (c_tower.y - c_car.y) * (c_tower.y - c_car.y);

    return sqrt(cal_p1 + cal_p2);
}

void check_car_collider(sprite_t *car, sprite_t *tower, defender_t *def)
{
    float r_car = car->rect.width / 2;

    if (distance(car, tower) < r_car + RANGE) {
        if (anime(tower->timer)) {
            car->life -= tower->att;
            if (car->life <= 0) {
                car->is_kill = ON;
                set_money(def, REWARD);
                set_wave_value(def);
                check_victory(def);
            }
        }
        sfSprite_setColor(car->sprite, (sfColor){255, 255, 255, 125});
        car->move.x = def->arr_move[car->state].x * tower->speed; 
        car->move.y = def->arr_move[car->state].y * tower->speed;
    } else {
        car->move = def->arr_move[car->state];
        sfSprite_setColor(car->sprite, (sfColor){255, 255, 255, 255});
    }
}

void check_collider(defender_t *def, sprite_t *tower)
{
    trap_t car = def->trap;

    while (car != NULL) {
        if (car->trap->state < 5) {
            if (car->trap->is_kill == OFF)
                check_car_collider(car->trap, tower, def);
        }
        car = car->next;
    }
}

void collider(defender_t *def)
{
    trap_t tower = def->tower;

    while (tower != NULL) {
        check_collider(def, tower->trap);
        tower = tower->next;
    }
}