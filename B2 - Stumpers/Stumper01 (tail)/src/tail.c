/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** tail
*/

#include "proto.h"
#include "lib.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *fs_cat_x_bytes(char const *filepath, unsigned long int x)
{
    char *buffer = malloc(sizeof(char) * x + 1);
    if (buffer == NULL || filepath == NULL)
        return NULL;
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, x);
    close(fd);
    return buffer;
}

void prompt(int q, char *file)
{
    if (file == NULL)
        return;
    if (q == 1) {
        my_putstr("==> ");
        my_putstr(file);
        my_putstr(" <==");
    }
}

int tail_function(tail_t *tail)
{
    char *buffer;
    file_t temp;
    
    if (tail == NULL)
        return 84;
    temp = tail->files;
    while (temp != NULL) {
        buffer = fs_cat_x_bytes(temp->file, BUFFER);
        if (buffer[0] == '\0') {
            my_putstr("tail: impossible d'ouvrir '");
            my_putstr(temp->file);
            my_putstr("'\n");
        } else {
            prompt(tail->q, temp->file);
            tail_all(tail, buffer);
        }
        free(buffer);
        temp = temp->next;
    }
    return 0;
}