/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** lines
*/

#ifndef LINES_H_
    #define LINES_H_

    #define BATTLE(id) "Villager %d: Going into battle!\n", id
    #define NEED_DRINK(id, left) "Villager %d: I need a drink... \
I see %d servings left.\n", id, left
    #define ATTACK(id, left) "Villager %d: Take that roman scum! \
Only %d left.\n", id, left
    #define PANO(id) "Villager %d: Hey Pano wake up! \
We need more potion.\n", id
    #define END(id) "Villager %d: I'm goind to sleep now.\n", id
    #define DRUID "Druid: I'm ready... but sleepy...\n"
    #define DRUID_END "Druid: I'm out of viscum. I'm going back to... zZz\n"
    #define REFILL(left) "Druid: Ah! Yes, yes. I'm awake! Working on it! \
Beware I can only make %d more refills after this one.\n", left

#endif
