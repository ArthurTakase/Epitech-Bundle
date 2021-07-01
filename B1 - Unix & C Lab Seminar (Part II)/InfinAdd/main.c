/*
** EPITECH PROJECT, 2020
** infinitadd
** File description:
** main
*/

#include "include/my.h"
#include "include/infinit.h"
#include <stdlib.h>

// Gestion d'erreur
// Return 0 si erreur
// Return 1 si tout est bon
int get_error(int argc, char **argv)
{
    if (argc != 3)
        return 0;
    if (!(my_str_isnum(argv[1])) || !(my_str_isnum(argv[2])))
        return 0;
    return 1;
}

// Affiche le resultat
int print_result(char **argv, int neg1, int neg2)
{
    char *result = malloc(sizeof(char) * (my_strlen(argv[1]) + 2));
    result = choice_calc(argv, neg1, neg2);
    
    my_putstr(result);
    my_putchar('\n');
    return 0;
}

// Fonction principale
int main(int argc, char **argv)
{
    int neg1 = get_neg(argv[1]);
    int neg2 = get_neg(argv[2]);

    argv[1] = set_neg(argv[1], neg1);
    argv[2] = set_neg(argv[2], neg2);
    if (get_error(argc, argv) == 0)
        return 84;
    argv[get_less(argv)] = compare_len(argv);
    print_result(argv, neg1, neg2);
    return 0;
}
