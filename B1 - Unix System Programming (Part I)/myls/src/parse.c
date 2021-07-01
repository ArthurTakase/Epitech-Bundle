/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** parse
*/

#include <stdlib.h>

char *parse_command(int argc, char **argv)
{
    char *command_list = malloc(sizeof(char) * argc);
    int index = 0;

    for (int i = 0; i != argc; i++)
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                command_list[index] = argv[i][j];
                index++;
            }
        }
    command_list[index] = 0;
    return command_list;
}

char **parse_dir(int argc, char **argv)
{
    char **result = malloc(sizeof(char *) * argc);
    int index = 0;

    for (int i = 0; i < argc; i++) {
        result[i] = malloc(sizeof(char) * 512);
    }
    for (int i = 1; i != argc; i++) {
        if (argv[i][0] != '-') {
            result[index] = argv[i];
            index++;
        }
    }
    result[index] = NULL;
    return result;
}