/*
** EPITECH PROJECT, 2020
** read buffer
** File description:
** read buffer
*/

#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE (484564)

char *my_read_buff(void)
{
    char *buff = malloc(sizeof(char) * BUFF_SIZE + 1);
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset += len;
    }
    buff[offset] = '\0';
    return buff;
}
