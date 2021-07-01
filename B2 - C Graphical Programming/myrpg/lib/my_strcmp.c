/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** La fonction compare les deux chaînes s1 et s2.
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

int my_strncmp(char *env, char *search)
{
    for (int i = 0; search[i] != '\0'; i++)
        if (search[i] != env[i])
            return 0;
    return 1;
}