/*
** EPITECH PROJECT, 2020
** final stumper
** File description:
** main
*/

#include <unistd.h>
#include "include/my.h"

#define BUFF_SIZE (484564)

int rush3(char *buff);

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset += len;
    }
    buff[offset] = '\0';
    if (buff[0] == '\0'|| rush3(buff) == 84) {
        write(2, "Error\n", 7);
        return 84;
    }
    return 0;
}
