/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** druid
*/

#include "lines.h"
#include "panoramix.h"

bool druid_refill(void)
{
    if (pano.current_pot == 0) {
        pano.nb_refills--;
        pano.current_pot = pano.pot_size;
        printf(REFILL(pano.nb_refills));
        POST_VILLAGER;
        if (pano.nb_refills == 0)
            return true;
    }
    return false;
}

void *druid(void *param)
{
    (void)param;

    printf(DRUID);
    while (1) {
        WAIT_DRUID;
        if (pano.nb_refills == 0)
            break;
        if (druid_refill())
            break;
    }
    printf(DRUID_END);
    return 0;
}
