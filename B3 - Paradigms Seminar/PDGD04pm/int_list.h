/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 00
*/

#pragma once

/*
** Types
*/

#include <stdbool.h>

typedef struct int_node_s
{
    int                 value;
    struct int_node_s   *next;
}   int_node_t;

typedef int_node_t *int_list_t;

/*
** Functions
*/

/* Informations */

unsigned int    int_list_get_size(int_list_t list);
bool            int_list_is_empty(int_list_t list);
void            int_list_dump(int_list_t list);

/* Modification */

bool    int_list_add_elem_at_front(int_list_t *front_ptr, int elem);
bool    int_list_add_elem_at_back(int_list_t *front_ptr, int elem);
bool    int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
             unsigned int position);

bool    int_list_del_elem_at_front(int_list_t *front_ptr);
bool    int_list_del_elem_at_back(int_list_t *front_ptr);
bool    int_list_del_elem_at_position(int_list_t *front_ptr,
            unsigned int position);

void    int_list_clear(int_list_t *front_ptr);

/* Value Access */

int     int_list_get_elem_at_front(int_list_t list);
int     int_list_get_elem_at_back(int_list_t list);
int     int_list_get_elem_at_position(int_list_t list,
            unsigned int position);
