/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** args
*/

#include "panoramix.h"

bool get_arguments(int ac, char **av)
{
    if (ac != 5)
        return false;
    pano.nb_villager = atoi(av[1]);
    pano.pot_size = atoi(av[2]);
    pano.nb_fight = atoi(av[3]);
    pano.nb_refills = atoi(av[4]);
    if (pano.nb_villager <= 0 || pano.pot_size <= 0 ||
        pano.nb_fight <= 0 || pano.nb_refills <= 0)
        return false;
    if ((pano.fights = malloc(sizeof(int) * pano.nb_villager)) == NULL)
        return false;
    for (int i = 0; i < pano.nb_villager; i++)
        pano.fights[i] = pano.nb_fight;
    pano.current_pot = pano.pot_size;
    pano.left = pano.nb_villager;
    return true;
}
