/*
** EPITECH PROJECT, 2022
** B-PSU-400-BDX-4-1-malloc-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <string.h>

#define BLOCK_SIZE sizeof(struct s_block)
#define PAGE_SIZE 8
#define SIZE(x) ((((x-1)/PAGE_SIZE)*PAGE_SIZE)+PAGE_SIZE)
#define TRUE 1
#define FALSE 0

typedef struct s_block {
    struct s_block *next;
    struct s_block *prev;
    size_t size;
    int free;
} *t_block;

extern t_block head;
extern t_block current;

// __________ ALLOC FUNCTIONS __________
void *malloc(size_t size);
void *calloc(size_t nmemb, size_t size);
void free(void *ptr);

// __________ BLOCKS FUNCTIONS __________
void init_block(t_block ptr, size_t size);
t_block split_block(t_block tmp, size_t size);
void extend_block(t_block *block, size_t size);
int find_empty_block(t_block *block, size_t size);

#endif
