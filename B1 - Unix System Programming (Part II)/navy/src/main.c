/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** main
*/

#include "struct.h"

global_t *global;

// Vérifie que le fichier donné en paramètre existe
int get_error(char *filepath)
{
    int file;
    char *buffer;

    if ((file = open(filepath, O_RDONLY)) == -1)
        return 1;
    close(file);
    buffer = load_file(filepath);
    if (my_strlen(buffer) == 31 && check_coord31(buffer))
        return 1;
    if (my_strlen(buffer) == 32 && check_coord32(buffer))
        return 1;
    return 0;
}

// Initialisation des valeurs de la structure globale
int init(void)
{
    if ((global = malloc(sizeof(global_t))) == NULL)
        return 1;
    global->is_next = 0;
    if ((global->coord = malloc(3)) == NULL)
        return 1;
    my_strcpy(global->coord, "@1");
    global->is_hit = 0;
    global->tab = create_tab();
    global->tab_ad = create_tab();
    return 0;
}

// Remet certaines valeurs de la structure globale à 0
void reset(void)
{
    global->coord[0] = '@';
    global->coord[1] = '1';
    global->is_hit = 0;
}

//Fonction principale
int main(int argc, char **argv)
{
    if (init())
        return 84;
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            my_printf("ceci est mon -h\n");
        else if (!get_error(argv[1]))
            player1(argv[1]);
        else
            return 84;
    } else if (argc == 3) {
        if (!get_error(argv[2]))
            player2(argv[2], argv[1]);
        else
            return 84;
    }
    win();
    return 0;
}