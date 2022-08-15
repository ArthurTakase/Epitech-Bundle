/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** panoramix
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #define LOCK pthread_mutex_lock(&mutex)
    #define UNLOCK pthread_mutex_unlock(&mutex)
    #define WAIT_DRUID sem_wait(&sem_druid);
    #define WAIT_VILLAGER sem_wait(&sem_villagers);
    #define POST_DRUID sem_post(&sem_druid);
    #define POST_VILLAGER sem_post(&sem_villagers);

typedef struct s_panoramix {
    int nb_villager;
    int left;
    int pot_size;
    int nb_fight;
    int nb_refills;
    int current_pot;
    int *fights;
} t_panoramix;

extern t_panoramix pano;
extern pthread_mutex_t mutex;
extern sem_t sem_druid;
extern sem_t sem_villagers;

bool get_arguments(int ac, char **av);
void *villager(void *param);
void *druid(void *param);

#endif
