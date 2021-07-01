/*
** EPITECH PROJECT, 2020
** my_howin
** File description:
** return how many time n is in str
*/

int my_howmanyin(char c, char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return count;
}
