/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** score
*/

#include "defender.h"
#include "lib.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

char *load_file(char const *filepath)
{
    char *buffer = malloc(sizeof(char) * 2);
    int fd = open(filepath, O_RDONLY);

    read(fd, buffer, 2);
    close(fd);
    return buffer;
}

int check_file(char *filepath)
{
    int file;

    if ((file = open(filepath, O_RDONLY)) == -1) {
        close(file);
        my_putstr("Fichier non trouvé.\n");
        return 1;
    }
    close(file);
    return 0;
}

void write_score(defender_t *def)
{
    int fd = open("asset/score", O_WRONLY);
    char *new_score = my_itos(def->best, 10);
    int len = my_strlen(new_score);
    write(fd, new_score, len);
    close(fd);
}

void check_best(defender_t *def)
{
    char *txt_file;
    char *score;

    if (check_file("asset/score"))
        return;
    txt_file = load_file("asset/score");
    def->best = my_getnbr(txt_file);
    if (def->best <= def->life) {
        def->best = def->life;
        write_score(def);
    }
    score = my_itos(def->best, 10);
    sfText_setString(def->score->txt, score);
    if (score[0] != '0')
        free(score);
}