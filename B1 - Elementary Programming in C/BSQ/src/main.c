/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main
*/

#include "../include/error.h"

int start(char *argv);

// Main function with error handling
int main(int argc, char **argv)
{
    if (argc != 2) {
        return ERROR;
    }
    return start(argv[1]);
}