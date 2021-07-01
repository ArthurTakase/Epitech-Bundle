/*
** EPITECH PROJECT, 2020
** Bootstrap BSQ
** File description:
** step1.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/error.h"

char *fs_cat_x_bytes(char const *filepath, int x);

// Stores the data of a file in a char *
char *load_file_in_mem(char const *filepath)
{
    struct stat *buf;

    buf = malloc(sizeof(struct stat));
    stat(filepath, buf);
    if (buf->st_size == 0) {
        exit(ERROR);
    }
    return fs_cat_x_bytes(filepath, buf->st_size);
}