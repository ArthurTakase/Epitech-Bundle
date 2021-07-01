/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** txt
*/

#include <stdlib.h>
#include "lib.h"
#include "giantman.h"

void compress_part(list_t *dict, list_t *number, char **old, char **c)
{
    int new;
    char *temp;
    char *s = (*old);

    new = get(number);
    temp = in_list_int(new, (*dict));
    if (temp == NULL)
        s = my_strcat((*old), (*c));
    else
        s = temp;
    my_putstr(s);
    free((*c));
    (*c) = strfromchar(s[0]);
    (*dict) = push_back_list((*dict), my_strcat((*old), (*c)));
    if (temp == NULL)
        (*old) = in_list_int(new, (*dict));
    else
        (*old) = temp;
}

void txt_function(char *filepath)
{
    char *txt = load_file(filepath);
    list_t dict = init_list(txt);
    list_t number = get_all_number(txt, filepath);
    char *old = strfromchar(get(&number));
    char *c = strfromchar(old[0]);

    if (size_file(filepath) > 72000)
        return;
    free(txt);
    my_putstr(old);
    while (number != NULL)
        compress_part(&dict, &number, &old, &c);
    free(c);
    clear_list(number, 0);
    clear_list(dict, 1);
}