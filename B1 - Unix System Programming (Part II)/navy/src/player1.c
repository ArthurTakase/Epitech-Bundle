/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** player1
*/

#include "struct.h"

// Attente de la connection du joueur 2
void start_p1(void)
{
    my_printf("my_pid: %d\nwaiting for enemy connexion...\n", getpid());
    wait_start();
    my_printf("\nenemy connected\n");
}

// Boucle de jeu du joueur 1
void loop_p1(void)
{
    char *buff;

    reset();
    show_all();
    buff = get_send_line();
    wait_response();
    my_printf("%c%c: %s", buff[0], buff[1], is_touch(buff));
    my_printf("\nwaiting for enemy's attack...\n");
    reset();
    wait_reception();
    my_printf("%c%c: ", global->coord[0], global->coord[1]);
    edit_tab();
    global->is_next = 0;
    global->index_coord = 0;
}

// Fonction principale du joueur 1
int player1(char *filepath)
{
    set_boat(load_file(filepath));
    start_p1();
    while (left(1) != 0 && left(2) != 0)
        loop_p1();
    show_all();
    return 0;
}