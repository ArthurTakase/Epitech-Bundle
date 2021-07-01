/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** rush2
*/

#include "include/my.h"
#include <unistd.h>
#include "include/rush.h"

// Displays the probable language
void affiche(int i)
{
    if (i == 0)
        my_putstr("=> English");
    if (i == 1)
        my_putstr("=> French");
    if (i == 2)
        my_putstr("=> German");
    if (i == 3)
        my_putstr("=> Spanish");
}

// Compares the sum of the difference of each letter of each language.
void compare_tout(int *our_lang)
{
    int temp[4] = {0, 0, 0, 0};
    int temptemp[4] = {0, 0, 0, 0};
    int i = 0;

    temp[0] = compare_eng(our_lang);
    temp[1] = compare_fr(our_lang);
    temp[2] = compare_all(our_lang);
    temp[3] = compare_esp(our_lang);
    temptemp[0] = temp[0];
    temptemp[1] = temp[1];
    temptemp[2] = temp[2];
    temptemp[3] = temp[3];
    my_sort_int_array(temp, 4);
    i = 0;
    while (temp[0] != temptemp[i])
        i++;
    affiche(i);
}

// Displays the values of each letter
int print_elem(char **argv, int n, int j)
{
    float part1 = ((float)n / count_letter(argv)) * 100;
    float part2 = (int)(part1 * 100) % 100;

    my_putchar(argv[j][0]);
    my_putchar(':');
    my_put_nbr(n);
    my_putstr(" (");
    my_put_nbr(part1);
    my_putchar('.');
    my_put_nbr(part2);
    if (part2 == 0)
        my_putchar('0');
    my_putstr("%)");
    my_putchar('\n');
    return part1 * 100;
}

// FOR THE NORME !
int norme(char **argv, int j, int i, int n)
{
    char *phrase = my_strlowcase(argv[1]);
    int flag = 0;

    if (argv[j][0] >= 65 && argv[j][0] <= 90) {
        argv[j][0] += 32;
        flag = 1;
    }
    if (phrase[i] == argv[j][0])
        n++;
    if (flag == 1)
        argv[j][0] -= 32;
    flag = 0;
    return n;
}

// Main function
int main(int argc, char **argv)
{
    int our_lang[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 0;
    int temp;

    if (get_error(argc, argv) == 0) {
        write(2, "Invalid size\n", 13);
        return 0;
    }
    for (int j = 2; j != argc; j++) {
        for (int i = 0; argv[1][i] != '\0'; i++) {
            n = norme(argv, j, i, n);
        }
        temp = print_elem(argv, n, j);
        our_lang[argv[j][0] - 97] = temp;
        n = 0;
    }
    compare_tout(our_lang);
    return 0;
}
