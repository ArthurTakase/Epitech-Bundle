/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** tail_part
*/

#include "proto.h"
#include "lib.h"
#include <unistd.h>

int tail_c(tail_t *tail, char *buffer)
{
    int len;

    if (buffer == NULL || tail == NULL)
        return 1;
    my_putstr("\n");
    if (tail->signe == '+')
        my_putstr(buffer + tail->n - 1);
    else {
        len = my_strlen(buffer);
        buffer = my_revstr(buffer);
        for (int i = 0; i != tail->n + 1 && len - i + 1 > 0; i++) {
            write(1, &buffer[len - i], 1);
        }
    }
    return 0;
}

int tail_n_part(tail_t *tail, char *buffer)
{
    int nb_line = 0;
    int nb_line_total = 0;

    if (buffer == NULL || tail == NULL)
        return 1;
    for (int j = 0; buffer[j] != '\0'; j++)
        if (buffer[j] == '\n')
            nb_line_total++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_line++;
        if (nb_line_total - nb_line < tail->n)
            write(1, &buffer[i], 1);
    }
    return 0;
}

int tail_n(tail_t *tail, char *buffer)
{
    int nb_line = 0;

    if (buffer == NULL || tail == NULL)
        return 1;
    if (tail->signe == '+') {
        nb_line = 2;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (nb_line > tail->n)
                write(1, &buffer[i], 1);
            if (buffer[i] == '\n')
                nb_line++;
        }
    } else
        tail_n_part(tail, buffer);
    return 0;
}

int tail_all(tail_t *tail, char *buffer)
{
    if (buffer == NULL || tail == NULL)
        return 1;
    if (tail->letter == 'c')
        return tail_c(tail, buffer);
    if (tail->letter == 'n')
        return tail_n(tail, buffer);
    return 1;
}