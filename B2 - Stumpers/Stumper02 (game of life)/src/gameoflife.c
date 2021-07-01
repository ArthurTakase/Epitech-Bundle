/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper2-arthur.decaen
** File description:
** gameoflife
*/

#include "gameoflife.h"
#include "lib.h"
#include <unistd.h>

int check_errors(int argc, char **argv)
{
    if (argv == NULL)
        exit(84);
    if (argc != 3) {
        write(2, "invalid lenght of argc.\n", 25);
        return 1;
    }
    if (!my_str_isnum(argv[2])) {
        write(2 , "the second argument must be a positive number.\n", 48);
        return 1;
    }
    return 0;
}

int gameoflife(int argc, char **argv)
{
    map_t map;

    if (argv == NULL)
        exit(84);
    if (check_errors(argc, argv))
        return 84;
    map.gen = my_getnbr(argv[2]);
    create_map(&map, argv[1]);

    for (int i = 0; i != map.gen; i++) {
        set_generation(&map);
        map.current_map = clone_array(map.next_map);
        free(map.next_map);
        map.next_map = malloc_map(&map);
    }
    for (int j = 0; map.current_map[j] != NULL; j++)
        printf("%s\n", map.current_map[j]);
    return 0;
}