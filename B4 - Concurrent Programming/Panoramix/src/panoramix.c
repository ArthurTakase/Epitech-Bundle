/*
** EPITECH PROJECT, 2022
** B-CCP-400-BDX-4-1-panoramix-arthur.decaen
** File description:
** main
*/

#include "panoramix.h"

t_panoramix pano;
pthread_mutex_t mutex;
sem_t sem_druid;
sem_t sem_villagers;

int launch_threads(void)
{
    pthread_t *threads = malloc(sizeof(pthread_t) * (pano.nb_villager + 2));

    if (threads == NULL)
        return 84;
    pthread_create(&threads[pano.nb_villager], NULL, druid, NULL);
    for (long i = 0; i < pano.nb_villager; i++)
        if (pthread_create(&threads[i], NULL, villager, (void *)i))
            printf("Error: failed to create thread\n");
    for (int i = 0; i < pano.nb_villager; i++)
        if (pthread_join(threads[i], NULL))
            printf("Error: failed to join thread\n");
    pthread_cancel(threads[pano.nb_villager]);
    free(threads);
    return 0;
}

int main(int argc, char **argv)
{
    int return_value = 0;

    if (!get_arguments(argc, argv)) {
        printf("Wrong arguments\n");
        return 84;
    }
    sem_init(&sem_druid, 0, 0);
    sem_init(&sem_villagers, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    return_value = launch_threads();
    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem_druid);
    sem_destroy(&sem_villagers);
    free(pano.fights);
    return return_value;
}
