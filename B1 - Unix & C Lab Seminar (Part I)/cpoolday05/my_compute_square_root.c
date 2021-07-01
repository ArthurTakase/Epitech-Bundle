/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root (int nb)
{
    int temp = nb;
    int count = 0;

    for (int i = 1; temp > 0; i += 2) {
        temp -= i;
        count++;
    }
    if (temp < 0)
        return 0;
    return count;
}
