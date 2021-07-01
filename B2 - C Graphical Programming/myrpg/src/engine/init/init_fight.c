/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** init_ennemis
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void set_scale_ennemis(fight_t *fight)
{
    ennemi_t *arr[3] = {fight->enn1, fight->enn2, fight->enn3};
    int arrx[3] = {200, 340, 490};

    for (int i = 0; i != 3; i++) {
        arr[i]->life_txt = new_txt((sfVector2f){arrx[i], 500}, "3", 20, 0);
        sfText_setColor(arr[i]->life_txt->txt, (sfColor){255, 255, 255, 35});
        sfSprite_setScale(arr[i]->idle->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(arr[i]->attack->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(arr[i]->hurt->sprite, (sfVector2f){2, 2});
        sfSprite_setScale(arr[i]->dead->sprite, (sfVector2f){2, 2});
    }
}

fight_t *init_fight(void)
{
    fight_t *fight = malloc(sizeof(fight_t));
    ennemi_t *(*create_enn[4])(int) = {viking, null, pirate, ninja};
    int *enn_id = malloc(sizeof(int) * 3);

    if ((enn_id[0] = rand() % 4) == EMPTY &&
        (enn_id[1] = rand() % 4) == EMPTY &&
        (enn_id[2] = rand() % 4) == EMPTY)
        enn_id[1] = (rand() % 3) + 1;
    fight->enn1 = create_enn[enn_id[0]](1);
    fight->enn2 = create_enn[enn_id[1]](2);
    fight->enn3 = create_enn[enn_id[2]](3);
    set_scale_ennemis(fight);
    fight->state = 0;
    fight->turn = PLAYER;
    return fight;
}