/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** block
*/

#include "../include/malloc.h"


t_block	head = NULL;
t_block	current = NULL;

void init_block(t_block block, size_t size)
{
    block->next = NULL;
    block->prev = current;
    block->size = size;
    block->free = FALSE;
    if (current)
        current->next = block;
    current = block;
}

t_block split_block(t_block temp, size_t size)
{
    t_block	new_block;

    if (temp->size - (size + BLOCK_SIZE) >= PAGE_SIZE) {
        new_block = (t_block)((char *)temp + BLOCK_SIZE + size);
        new_block->prev = temp;
        new_block->next = temp->next;
        new_block->size = temp->size - (size + BLOCK_SIZE);
        new_block->free = TRUE;
        if (temp->next)
            temp->next->prev = new_block;
        temp->next = new_block;
        temp->size = size;
        if (current == temp)
            current = new_block;
    }
    temp->free = FALSE;
    return temp;
}

int find_empty_block(t_block *block, size_t size)
{
    t_block temp = head;

    while (!block && temp) {
        if (temp->size >= size && temp->free)
            (*block) = split_block(temp, size);
        temp = temp->next;
    }
    head = (head == NULL) ? (*block) : head;
    return (*block) ? 1 : 0;
}

void extend_block(t_block *block, size_t size)
{
    size_t new_size = SIZE(BLOCK_SIZE + size);

    (*block) = sbrk(0);
    if (sbrk(new_size) == (void *)-1)
        *block = NULL;
    else {
        init_block(*block, size);
        (*block)->size = new_size - BLOCK_SIZE;
        (*block) = split_block(*block, size);
    }
}
