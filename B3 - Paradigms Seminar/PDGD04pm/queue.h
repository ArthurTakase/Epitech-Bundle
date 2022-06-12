/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 03
*/

#pragma once

#include "list.h"

typedef list_t queue_t;

/* informations */

unsigned int    queue_get_size(queue_t queue);
bool            queue_is_empty(queue_t queue);

/* Modification */

bool    queue_push(queue_t *queue_ptr, void *elem);
bool    queue_pop(queue_t *queue_ptr);
void    queue_clear(queue_t *queue_ptr);

/* Access */

void    *queue_front(queue_t queue);
