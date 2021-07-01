/*
** EPITECH PROJECT, 2020
** Bootstrap BSQ
** File description:
** tools
*/

int width(char *file, int height);
int height(char *file);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath);
int **create_dup(char **map, int nb_y, int nb_x);
int **set_dup(int **dup, int height, int width);
char **print_x(int **dup, char **map, int height, int width);