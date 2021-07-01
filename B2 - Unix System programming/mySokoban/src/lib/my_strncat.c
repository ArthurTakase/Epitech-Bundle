/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates two strings
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    for (; i < nb && src[i] != '\0'; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + i] = '\0';
    return dest;
}
