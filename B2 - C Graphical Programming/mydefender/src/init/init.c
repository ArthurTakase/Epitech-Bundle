/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

void init_p2(defender_t *defender)
{
    init_sprites(defender);
    init_all_clock(defender);
    init_zones(defender);
    init_sounds(defender);
    defender->trap = new_list();
    defender->tower = new_list();
    defender->arr_move = malloc(sizeof(sfVector2f) * 5);
    defender->arr_move[0] = (sfVector2f){MOVE1, MOVE2};
    defender->arr_move[1] = (sfVector2f){MOVE1, -MOVE2};
    defender->arr_move[2] = (sfVector2f){-MOVE1, -MOVE2};
    defender->arr_move[3] = (sfVector2f){MOVE1, -MOVE2};
    defender->arr_move[4] = (sfVector2f){MOVE1, MOVE2};
    defender->current_wave = 0;
    defender->waves = init_wave(defender);
}

void init(defender_t *defender)
{
    char *txt = my_itos(MONEY_BASE, 10);
    char *wave = my_itos(3, 10);
    char *fps = my_itos(FPS, 10);

    defender->is_full = OFF;
    defender->life = 3;
    defender->best = 0;
    init_window(defender);
    defender->scene = HOME;
    defender->money = init_txt((sfVector2f){38, 11}, txt, 20, MONEY_BASE);
    defender->fps = init_txt((sfVector2f){458, 195}, fps, 30, FPS);
    defender->score = init_txt((sfVector2f){467, 275}, "0", 22, 0);
    defender->enn_left = init_txt((sfVector2f){140, 11}, wave, 20, 0);
    defender->is_vol = ON;
    sfText_setColor(defender->fps->txt, sfBlack);
    free(txt);
    free(fps);
    init_p2(defender);
}