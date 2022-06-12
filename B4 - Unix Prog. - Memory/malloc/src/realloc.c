/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** realloc
*/

#include "../include/malloc.h"

void *realloc(void *ptr, size_t size)
{
    t_block	block;
    void *new_block;

    if (!ptr)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    block = (t_block)(ptr - BLOCK_SIZE);
    if (block->free)
        return NULL;
    if (block->size >= SIZE(size))
        return ptr;
    if ((new_block = malloc(size)))
        memcpy(new_block, ptr, size);
    free(ptr);
    return new_block;
}
