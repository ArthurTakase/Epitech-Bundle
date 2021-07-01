/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** send_get
*/

#include "struct.h"

// Boucles envois signaux à l'adversaire pour créer la coordonnée
void send_value(char *coord)
{
    for (int i = 0; i != coord[0] - 'A'; i++) {
        kill(global->pid_ad, SIGUSR1);
        usleep(10);
    }
    kill(global->pid_ad, SIGUSR2);
    for (int j = 0; j != coord[1] - '0'; j++) {
        kill(global->pid_ad, SIGUSR1);
        usleep(10);
    }
    kill(global->pid_ad, SIGUSR2);
}

// Récupère l'entrée utilisateur et lance la fonciton d'envois
char *get_send_line(void)
{
    size_t n = 1024;
    char *buffer;
    char lettre[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char nombre[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    while (1) {
        buffer = malloc(n);
        my_printf("\nattack: ");
        getline(&buffer, &n, stdin);
        if (my_in(buffer[0], lettre) && my_in(buffer[1], nombre))
            break;
        free(buffer);
        my_printf("wrong position");
    }
    send_value(buffer);
    return buffer;
}

// Regarde le signal de réponse et change la case du tableau adverse
char *is_touch(char *coord)
{
    if (global->is_hit == HIT)
        global->tab_ad[coord[1] - '0' - 1][coord[0] - 'A'] = 'x';
    if (global->tab_ad[coord[1] - '0' - 1][coord[0] - 'A'] != 'x')
        global->tab_ad[coord[1] - '0' - 1][coord[0] - 'A'] = 'o';
    return global->is_hit == HIT ? "hit\n" : "missed\n";
}