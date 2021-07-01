/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** Proto des lib utilisées dans le programme
*/

#ifndef LIB_H_
#define LIB_H_

char *load_file(char const *filepath);
int my_str_isnum(char const *str);
int my_in(char want, char *source);
int my_getnbr(char const *str);
char **clone_array(char **src);

#endif