/*
** EPITECH PROJECT, 2020
** my_in
** File description:
** return 1 if char in str
*/

int my_in(char want, char *source)
{
    for (int i = 0; source[i] != '\0'; i++)
        if (source[i] == want)
            return 1;
    return 0;
}
