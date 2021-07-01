/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

settings_t *init_settings(void)
{
    settings_t *sett = malloc(sizeof(settings_t));

    sett->fullscreen = FALSE;
    sett->volume  = TRUE;
    sett->fps = FPS;
    return sett;
}

int set_scene(int argc, char **argv)
{
    int scene;

    if (argc != 2 || !my_str_isnum(argv[1]))
        return HOME;
    scene = my_getnbr(argv[1]);
    if (scene < 0 || scene > NB_SCENE - 1)
        return HOME;
    if (scene == FIGHT || scene == END_FIGHT) {
        my_putstr("Scene indisponible pour un lancement rapide\n");
        return HOME;
    }
    return scene;
}

void init(rpg_t *rpg, int argc, char **argv)
{
    rpg->scene = set_scene(argc, argv);
    rpg->fight = NULL;
    rpg->is_load = 0;
    rpg->clocks = init_all_clock();
    rpg->settings = init_settings();
    rpg->sounds = init_sounds();
    rpg->sprites = init_sprites();
    rpg->player = init_player();
    rpg->player_map = init_player_map();
    rpg->bg = init_background();
    rpg->txts = init_txt();
    rpg->particle = new_dlist();
    rpg->fade = init_fade();
    rpg->current_map = FIRST_MAP;
    rpg->menu = init_menu();
    switch_map(rpg, "save/map1.save");
    init_window(rpg);
}