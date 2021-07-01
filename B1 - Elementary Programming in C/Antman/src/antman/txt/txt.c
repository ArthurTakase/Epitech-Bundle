/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** txt
*/

#include "antman.h"
#include "lib.h"
#include <stdlib.h>

void lzw_part(char txt, list_t *dict, list_t *result, char **p)
{
    char *temp_p;
    int index;
    char *temp;

    temp = strfromchar(txt);
    temp_p = my_strcat((*p), temp);
    free(temp);
    index = in_list(temp_p, (*dict));
    if (index >= 0) {
        free((*p));
        (*p) = temp_p;
    } else {
        (*result) = push_back_list_int((*result), in_list((*p), (*dict)));
        free((*p));
        (*dict) = push_back_list((*dict), temp_p);
        (*p) = strfromchar(txt);
    }
}

void lzw_compress(char *filepath)
{
    char *txt = load_file(filepath);
    list_t dict = init_list(txt);
    list_t result = new_list();
    char *p = strfromchar(txt[0]);
    int size = size_file(filepath);

    if (size > 72000)
        return;
    for (int i = 1; i != size; i++)
        lzw_part(txt[i], &dict, &result, &p);
    free(txt);
    result = push_back_list_int(result, in_list(p, dict));
    free(p);
    print_bin(result, dict);
}
