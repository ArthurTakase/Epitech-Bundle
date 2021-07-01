/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Task05
*/

int my_getnbr(char const *str)
{
    int neg = 1;
    int result = 0;
    int i = 0;

    if (str == 0)
        return 0;
    for (; (*str < 47 || *str > 58) && *str != 0; i++)
        str++;
    if (i > 0 && *(str - 1) == 45)
        neg = -1;
    while (*str != 0 && *str >= '0' && *str <= '9') {
        result *= 10;
        result = result + *str - 48;
        str = str + 1;
    }
    result *= neg;
    return result;
}
