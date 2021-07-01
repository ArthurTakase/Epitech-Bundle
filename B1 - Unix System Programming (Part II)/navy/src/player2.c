/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** player2
*/

#include "struct.h"

void loop_p2(void)
{
    char *coord;

    reset();
    show_all();
    my_printf("\nwaiting for enemy's attack...\n");
    wait_reception();
    my_printf("%c%c: ", global->coord[0], global->coord[1]);
    edit_tab();
    global->is_next = 0;
    global->index_coord = 0;
    reset();
    coord = get_send_line();
    wait_response();
    my_printf("%c%c: %s", coord[0], coord[1], is_touch(coord));
}

// Fonction principale du joueur 2
int player2(char *filepath, char *pid)
{
    set_boat(load_file(filepath));
    global->pid_ad = my_getnbr(pid);
    if (kill(global->pid_ad, SIGUSR1) == -1)
        return 84;
    my_printf("my_pid: %d\nsuccessfully connected\n", getpid());
    while (left(1) != 0 && left(2) != 0)
        loop_p2();
    show_all();
    return 0;
}