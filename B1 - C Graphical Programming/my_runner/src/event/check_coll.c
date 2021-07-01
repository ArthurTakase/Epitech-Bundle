/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** check_coll
*/

#include "struct.h"

void what_if_else(run_t *run, trap_t temp)
{
    static int over_value[4] = {-1, -1, -1, 1};

    if (run->life->value != 0 && temp->trap->value != 3) {
        run->life->value--;
        temp->trap->jump_height = 1;
        run->life->rect.left += 21;
        sfSprite_setScale(temp->trap->sprite, (sfVector2f){0, 0});
        sfSound_play(run->sound->kill->sound);
        sfSprite_setTextureRect(run->life->sprite, run->life->rect);
    } else {
        if (over_value[temp->trap->value] == -1)
            sfSound_play(run->sound->defeat->sound);
        else
            sfSound_play(run->sound->victory->sound);
        run->is_over = over_value[temp->trap->value];
    }
}

void what_if(run_t *run, trap_t temp)
{
    if (temp->trap->value == 4) {
        sfSound_play(run->sound->coin->sound);
        run->score->score += 3;
        sfText_setString(run->score->txt, my_itos(run->score->score, 10));
        sfSprite_setScale(temp->trap->sprite, (sfVector2f){0, 0});
    } else
        what_if_else(run, temp);
}

void check_coll(run_t *run)
{
    trap_t temp = run->trap;
    sfFloatRect player;
    sfFloatRect trap;

    while (temp != NULL) {
        if (sfSprite_getPosition(temp->trap->sprite).x > 500)
            break;
        player = sfSprite_getGlobalBounds(run->player->sprite);
        trap = sfSprite_getGlobalBounds(temp->trap->sprite);
        if (sfFloatRect_intersects(&player, &trap, NULL))
            what_if(run, temp);
        temp = temp->next;
    }
}