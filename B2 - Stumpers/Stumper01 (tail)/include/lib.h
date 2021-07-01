/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** Proto des lib utilisées dans le programme
*/

#ifndef LIB_H_
#define LIB_H_

void my_putstr(char const *str);
int my_strlen(char const *str);
char *my_revstr(char *str);
int my_str_isnum(char const *str);
int my_in(char want, char *source);
int my_getnbr(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);

#endif