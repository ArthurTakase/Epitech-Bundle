/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** calloc
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *new = NULL;

    if ((new = malloc(nmemb * size)))
        memset(new, 0, nmemb * size);
    return new;
}
