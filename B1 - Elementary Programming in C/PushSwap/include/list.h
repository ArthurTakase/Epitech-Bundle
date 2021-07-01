/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#ifndef __list__H__
#define __list__H__

#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct list_element
{
    int value;
    struct list_element *next;
} list_element_t, *list_t;

typedef struct all_list
{
    list_t la;
    list_t lb;
} all_list_t;

list_t new_list(void);
bool is_empty_list(list_t li);
int list_length(list_t li);
list_t push_back_list(list_t li, int value);
list_t push_front_list(list_t li, int value);
list_t pop_back_list(list_t li);
list_t pop_front_list(list_t li);
int get_min(list_t li);
all_list_t *move_pb(all_list_t *list);
list_t move_ra(list_t li);
list_t move_rra(list_t li);
int my_getnbr(char const *str);
void my_putstr(char const *str);
int check_order(all_list_t *list);
all_list_t *init_list(int argc, char **argv);
void print_pa(list_t lb);
int main_criterion(int argc, char **argv);

#endif