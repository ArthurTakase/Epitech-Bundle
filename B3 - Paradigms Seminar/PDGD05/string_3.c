/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD05-arthur.decaen
** File description:
** string_3
*/

#include "my.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *temp = strstr(this->str + pos, str);
    if (strlen(str) > strlen(this->str) || temp == NULL)
        return -1;
    return strlen(this->str) - strlen(temp);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}
