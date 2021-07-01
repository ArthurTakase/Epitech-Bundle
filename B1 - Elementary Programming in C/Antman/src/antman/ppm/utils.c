/*
** EPITECH PROJECT, 2021
** antman
** File description:
** utils
*/

#include <unistd.h>

void print_text(char **file)
{
    int count = 0;

    file[0] += 3;
    while (file[0][count] != '\n')
        count++;
    write(1, &count, 1);
    write(1, file[0], count++);
    file[0] += count;
}