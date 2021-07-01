/*
** EPITECH PROJECT, 2021
** solostumper02
** File description:
** anagram
*/

#include <unistd.h>
#include "lib.h"

// Detection des erreurs de l'utilisateur
// Trop ou pas assez d'arguments -> Erreur
int check_error(int argc)
{
    if (argc < 3) {
        write(2, "Error: not enough arguments.\n", 30);
        return 1;
    }
    if (argc > 3) {
        write(2, "Error: too many arguments.\n", 28);
        return 1;
    }
    return 0;
}

// Regarde si "want" se trouve dans "source"
// Return 1 si Vrai, 0 si Faux
int in(char want, char *source)
{
    for (int i = 0; source[i] != '\0'; i++)
        if (source[i] == want)
            return 1;
    return 0;
}

// Met le texte en minuscule pour la comparaison
char *set_lower(char *txt)
{
    for (int i = 0;txt[i] != '\0'; i++)
        if (txt[i] < 97 || txt[i] > 122)
            txt[i] += 32;
    return txt;
}

// Regarde sur les deux char * sont des anagrammes
// Compare dans un premier temps la taille
// Puis regarde si toutes les lettres de "un" se trouvent dans "deux"
char *check_an(char *un, char *deux)
{
    if (my_strlen(un) != my_strlen(deux))
        return "no anagrams.\n";
    un = set_lower(un);
    deux = set_lower(deux);
    for (int i = 0; un[i] != '\0'; i++)
        if (!in(un[i], deux))
            return "no anagrams.\n";
    return "anagram!\n";
}

// Fonction principale
// Vérification du nombre d'arguments
// Lancement de la fonction check_an() et afichage du retour
int anagram(int argc, char **argv)
{
    char *result;

    if (check_error(argc))
        return 84;
    result = check_an(argv[1], argv[2]);
    my_putstr(result);
    return 0;
}