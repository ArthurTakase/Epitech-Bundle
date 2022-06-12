/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD05-arthur.decaen
** File description:
** string_2
*/

#include "my.h"

int compare_s(const string_t *this, const string_t *str)
{
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    return strcmp(this->str, str);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    char *temp = strdup(s);
    s = malloc(sizeof(char) * (n + strlen(temp)));
    s = strcpy(s, temp);
    return strlen(s);
}

const char *c_str(const string_t *this)
{
    return this->str;
}

int empty(const string_t *this)
{
    if (this->str == NULL || this->str[0] == '\0')
        return 1;
    return 0;
}
