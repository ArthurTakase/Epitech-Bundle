/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** malloc
*/

#include "../include/malloc.h"
#include <stdio.h>

void *malloc(size_t size)
{
    t_block block = NULL;
    size = SIZE(size);

    if (!find_empty_block(&block, size))
        extend_block(&block, size);
    if (!block)
        return NULL;
    return block + BLOCK_SIZE;
}
