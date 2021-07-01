/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** my_lennbr
*/

int len_nbr(int nb)
{
    int count = 0;

    if (nb != 0)
        for (count; nb > 0; count++)
            nb /= 10;
    else
        count = 1;
    return count;
}