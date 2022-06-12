/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD05-arthur.decaen
** File description:
** string_1
*/

#include "my.h"

void append_c(string_t *this, const char *ap)
{
    this->str = realloc(this->str, strlen(this->str) + strlen(ap) + 1);
    this->str = strcat(this->str, ap);
}

void append_s(string_t *this, const string_t *ap)
{
    return append_c(this, ap->str);
}

void assign_c(string_t *this, const char *s)
{
    free(this->str);
    this->str = strdup(s);
}

void assign_s(string_t *this, const string_t *str)
{
    assign_c(this, str->str);
}

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) - 1 < pos || pos < 0)
        return -1;
    return this->str[(int)pos];
}
