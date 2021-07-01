/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_getnbr
*/

int my_get_nbr(char *str)
{
    int first = 0;
    int number = 0;
    int count = 0;

    while (!(str[first] < 58 && str[first] > 47))
        first++;
    while (str[count + first] < 58 && str[count + first] > 47) {
        number *= 10;
        number += str[count + first] - 48;
        count++;
    }
    return (str[0] == '-') ? number *= -1 : number;
}