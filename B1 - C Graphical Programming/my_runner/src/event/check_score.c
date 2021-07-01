/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** check_score
*/

#include "struct.h"

void add_score_monster(run_t *run, trap_t temp)
{
    int score;
    float pos_x;
    sfVector2f full;

    temp->trap->is_jump = 1;
    edit_jauge(run);
    if (temp->trap->value == -1)
        return;
    run->score->score += 1;
    sfText_setString(run->score->txt, my_itos(run->score->score, 10));
    score = run->score->score;
    pos_x = DIM_X / 2 - my_strlen(my_itos(score, 10)) * 10;
    sfText_setPosition(run->score->txt, (sfVector2f){pos_x, 10});
}

void check_score(run_t *run)
{
    trap_t temp = run->trap;
    int trap_x;

    while (temp != NULL) {
        trap_x = sfSprite_getPosition(temp->trap->sprite).x;
        if (trap_x > 1200)
            break;
        if (trap_x  < 250 && temp->trap->value == 3) {
            sfSound_play(run->sound->victory->sound);
            run->is_over = VICTORY;
        }
        if (trap_x  < 250 && temp->trap->is_jump == 0
            && temp->trap->value != 4) {
            add_score_monster(run, temp);
        }
        temp = temp->next;
    }
}