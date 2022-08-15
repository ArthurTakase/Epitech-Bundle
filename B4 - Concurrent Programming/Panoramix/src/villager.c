/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** villager
*/

#include "lines.h"
#include "panoramix.h"

bool drink_potion(int index) {
    if (pano.current_pot > 0) {
        pano.current_pot--;
        UNLOCK;
        pano.fights[index] -= 1;
        printf(ATTACK(index, pano.fights[index]));
        return false;
    }
    return true;
}

bool villager_action(int index)
{
    LOCK;
    printf(NEED_DRINK(index, pano.current_pot));
    if (!drink_potion(index))
        return false;
    if (pano.nb_refills > 0) {
        printf(PANO(index));
        POST_DRUID;
        WAIT_VILLAGER;
        if (!drink_potion(index))
            return false;
    }
    UNLOCK;
    return true;
}

void *villager(void *param)
{
    int index = (long)param;

    printf(BATTLE(index));
    while (pano.fights[index] != 0) {
        if (villager_action(index))
            break;
    }
    printf(END(index));
    return 0;
}
