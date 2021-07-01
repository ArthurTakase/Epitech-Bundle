/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** La fonction compare les deux chaînes s1 et s2 sur n elements.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
