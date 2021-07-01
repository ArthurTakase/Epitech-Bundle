/*
** EPITECH PROJECT, 2020
** final stumper
** File description:
** rush3
*/

// Return width
int width(char *buff)
{
    int i = 0;

    while (buff[i] != '\n')
        i++;
    return i;
}

// Return height
int height(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            count++;
    return count;
}