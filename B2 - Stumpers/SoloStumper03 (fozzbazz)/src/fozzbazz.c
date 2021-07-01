/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-solostumper03-arthur.decaen
** File description:
** fozzbazz
*/

#include <stdlib.h>
#include <stdio.h>

// Verifies that the arguments contain only numbers.
// Returns 1 if yes, 0 if not.
int is_nbr(char const *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return 0;
    }
    return 1;
}

// Function in charge of detecting errors.
// Returns 1 if there is a problem, 0 if no problem.
int check_error(int argc, char **argv)
{
    if (argc != 3)
        return 1;
    if (!is_nbr(argv[1]) || !is_nbr(argv[2]))
        return 1;
    if (atoi(argv[1]) > atoi(argv[2]))
        return 1;
    return 0;
}

// Main loop.
// Look at each number and write the result at each loop turn.
int main_loop(int const un, int const deux)
{
    for (int temp = un; temp <= deux; temp += 1) {
        if (temp % 2 == 0)
            printf("Fozz");
        if (temp % 9 == 0)
            printf("Bazz");
        if (temp % 2 != 0 && temp % 9 != 0)
            printf("%d", temp);
        printf("\n");
    }
    return 0;
}

// Main function.
// In charge of launching the other functions of the program.
// Returns 84 if there is an error, 0 if all is well.
int fozzbazz(int argc, char **argv)
{
    if (check_error(argc, argv))
        return 84;
    main_loop(atoi(argv[1]), atoi(argv[2]));
    return 0;
}