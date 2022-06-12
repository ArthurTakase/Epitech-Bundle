/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD05-arthur.decaen
** File description:
** string
*/

#include "my.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_c = &find_c;
    this->find_s = &find_s;
}

void string_destroy(string_t *this)
{
    free(this->str);
    this->str = NULL;
}

void clear(string_t *this)
{
    if (this->str != NULL) {
        free(this->str);
        this->str = strdup("");
    } else
        this->str = strdup("");
}

int length(const string_t *this)
{
    if (this->str == NULL)
        return -1;
    return strlen(this->str);
}
