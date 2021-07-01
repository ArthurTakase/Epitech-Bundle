/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** player_menu
*/

#include <stdlib.h>
#include "rpg.h"

void event_menu(rpg_t *rpg, int *cible)
{
    sprite_t *mouse = rpg->sprites->mouse;

    if (mouse->state == ATT) {
        *cible = 0;
        sfSprite_setPosition(mouse->sprite, (sfVector2f){670, 420});
        mouse->move.x = RandomFloat(-0.2, -0.7);
        rpg->fight->state = 1;
    } else
        run_fight(rpg);
}

void fight_menu(rpg_t *rpg, sfEvent *event)
{
    static int cible = 0;
    static int pos[2] = {300, 340};
    static int type[2] = {ATT, RUN};
    sprite_t *mouse = rpg->sprites->mouse;

    if (event->key.code == sfKeyUp)
        cible = 0;
    if (event->key.code == sfKeyDown)
        cible = 1;
    if (event->key.code == sfKeyUp || event->key.code == sfKeyDown)
        sfSound_play(rpg->sounds->hud->sound);
    sfSprite_setPosition(mouse->sprite, (sfVector2f){770, pos[cible]});
    mouse->state = type[cible];
    if (event->key.code == sfKeyReturn)
        event_menu(rpg, &cible);
}

int reset_menu(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->sprites->mouse->sprite, (sfVector2f){770, 300});
    rpg->sprites->mouse->state = ATT;
    rpg->fight->state = 0;
    rpg->sprites->mouse->move.x = 0;
    rpg->fight->turn = ENNEMI;
    return 0;
}

int select_ennemis_menu(rpg_t *rpg, sfEvent *event)
{
    ennemi_t *enn[3] = {rpg->fight->enn1, rpg->fight->enn2, rpg->fight->enn3};
    sfFloatRect mouse;
    sfFloatRect mob;
    int i = 0;

    if (event->key.code == sfKeyReturn) {
        for (; i != 3; i++) {
            mouse = sfSprite_getGlobalBounds(rpg->sprites->mouse->sprite);
            mob = sfSprite_getGlobalBounds(enn[i]->idle->sprite);
            if (sfFloatRect_intersects(&mouse, &mob, NULL) &&
                enn[i]->state != DEAD_ENN)
                attack(rpg, i);
        }
        return reset_menu(rpg);
    }
    return 0;
}