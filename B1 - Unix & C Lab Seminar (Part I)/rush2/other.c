/*
** EPITECH PROJECT, 2020
** misc functions
** File description:
** misc functions
*/

#include "include/my.h"

// Counts the number of letters in the given sentence.
// Counts only the letters
int count_letter(char **argv)
{
    int count = 0;

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] >= 97 && argv[1][i] <= 122)
            count++;
    }
    return count;
}

// Gives the absolute value of the number given in parameter
int abs(int n)
{
    if (n < 0)
        n = -n;
    return n;
}

// Allows to know if a char is a letter
int is_alpha_char(char letter)
{
    if (letter < 65  || (letter > 90 && letter < 97) || letter > 122)
        return 0;
    return 1;
}

// Error management
// Returns 1 if everything is good
// Returns 0 if there is an error
int get_error(int argc, char **argv)
{
    if (argc < 3)
        return 0;
    for (int i = 2; i < argc; i++) {
        if (is_alpha_char(argv[i][0]) == 0)
            return 0;
    }
    return 1;
}
