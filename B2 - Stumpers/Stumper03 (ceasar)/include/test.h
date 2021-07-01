/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** Fichier avec tous les prototypes du programme pour criterion
*/

#ifndef TEST_H_
#define TEST_H_

int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int encrypt(int argc, char **argv);
int get_error(int argc, char **argv);

char *fs_cat_x_bytes(char const *filepath, int x);
char *load_file(char const *filepath);
char *encrypt_cesar(char *file, int key);

void write_in_file(char *to_write);

#endif