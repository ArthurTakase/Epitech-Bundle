/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** signal
*/

#include "struct.h"

// Toutes les actions de récupération des signaux
void handle_signal(int sig, siginfo_t *info, void *no)
{
    (void)no;
    global->pid_ad = info->si_pid;
    if (global->is_start == 0)
        global->is_start = 1;
    if (sig == SIGUSR1 && global->is_start)
        global->coord[global->index_coord]++;
    if (sig == SIGUSR2 && global->index_coord != 2)
        global->index_coord++;
    if (sig == SIGUSR2 && global->index_coord == 2)
        global->is_next = 1;
}

// Toutes les actions de réponse
void handle_response(int sig, siginfo_t *info, void *no)
{
    (void)info;
    (void)no;
    if (sig == SIGUSR1)
        global->is_hit = HIT;
    else
        global->is_hit = MISS;
}

//Attente de la connection du joueur 2
void wait_start(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
}

// Attente de la réponse de l'adversaire
void wait_response(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_response;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (global->is_hit == 0);
}

// Attente de coordonnée de l'adversaire
void wait_reception(void)
{
struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (global->is_next == 0);
}