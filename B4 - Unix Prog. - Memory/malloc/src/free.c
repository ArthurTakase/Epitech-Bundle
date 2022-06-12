/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** free
*/

#include "../include/malloc.h"

void free(void *ptr)
{
    t_block block = (t_block)((char *)ptr - BLOCK_SIZE);

    if (block->free == TRUE || !ptr)
        return;
    block->free = TRUE;
    if (current->free == TRUE) {
        head = current == head ? NULL : head;
        sbrk(-(current->size + BLOCK_SIZE));
    }
}