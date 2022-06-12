/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** print
*/

#include "print.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int lenght = strlen(str);
    for (int i = lenght - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; i != strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*funct[4])(const char *) = {print_normal, print_reverse,
                                      print_upper, print_42};
    if (action < PRINT_COUNT)
        (*funct[action])(str);
}

int main(void)
{
    const char *str = "So long , and thanks for all the fish .";
    do_action(PRINT_NORMAL, str);
    do_action(PRINT_REVERSE, str);
    do_action(PRINT_UPPER, str);
    do_action(PRINT_42, str);
    return (0);
}