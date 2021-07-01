/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** sokoban
*/

#include "proto.h"
#include "lib.h"
#include <stdlib.h>
#include <unistd.h>

void init_sokoban(soko_t *soko)
{
    char *map = load_file(soko->original_map);
    int nb_src = how_many('O', map);

    soko->end_y = malloc(sizeof(int) * (nb_src + 1));
    soko->end_x = malloc(sizeof(int) * (nb_src + 1));
    soko->nb_box = nb_src;
    soko->map = create_map(map, soko);
    soko->map_save = clone_2d(soko->map);
    soko->end_x[nb_src] = -1;
    soko->end_y[nb_src] = -1;
    move_player(0, soko);
}

void new_sokoban(soko_t *soko)
{
    char *map = load_file(soko->original_map);

    free(soko->map);
    free(soko->map_save);
    soko->map = create_map(map, soko);
    soko->map_save = clone_2d(soko->map);
    move_player(0, soko);
}

void too_little(void)
{
    clear();
    mvprintw(LINES / 2, COLS / 2 + 6, "Trop petit");
    refresh();
}

int sokoban(int argc, char **argv)
{
    soko_t soko;

    usage(argc, argv);
    if (get_error(argc, argv))
        return 84;
    soko.original_map = argv[1];
    init_sokoban(&soko);
    initscr();
    while (victory(&soko) != VICTORY && defeat(&soko) == NO_VICTORY) {
        if (soko.size->col > COLS || soko.size->row > LINES)
            too_little();
        else {
            print_soko(&soko);
            move_player(getch(), &soko);
        }
    }
    print_soko(&soko);
    usleep(99999);
    endwin();
    return soko.end_value;
}