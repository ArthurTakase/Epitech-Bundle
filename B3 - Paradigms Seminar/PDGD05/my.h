/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD05-arthur.decaen
** File description:
** my
*/

#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct string_t {
    char *str;
    void (*assign_c)(struct string_t *this, const char *s);
    void (*assign_s)(struct string_t *this, const struct string_t *str);
    void (*append_s)(struct string_t *this, const struct string_t *ap);
    void (*append_c)(struct string_t *this, const char *ap);
    char (*at)(const struct string_t *this, size_t pos);
    void (*clear)(struct string_t *this);
    int (*length)(const struct string_t *this);
    int (*compare_s)(const struct string_t *this, const struct string_t *str);
    int (*compare_c)(const struct string_t *this, const char *str);
    size_t (*copy)(const struct string_t *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_t *this);
    int (*empty)(const struct string_t *this);
    int (*find_c)(const struct string_t *this, const char *str, size_t pos);
    int (*find_s)(const struct string_t *this, const struct string_t *str,
                size_t pos);
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
int find_s(const string_t *this, const string_t *str, size_t pos);

#endif
