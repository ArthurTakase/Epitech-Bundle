/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 02
*/

#pragma once

# include "list.h"

typedef list_t stack_t;

/* informations */

unsigned int    stack_get_size(stack_t stack);
bool            stack_is_empty(stack_t stack);

/* Modification */

bool    stack_push(stack_t *stack_ptr, void *elem);
bool    stack_pop(stack_t *stack_ptr);
void    stack_clear(stack_t *stack_ptr);

/* Access */

void    *stack_top(stack_t stack);
