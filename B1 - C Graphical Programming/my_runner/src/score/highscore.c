/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** highscore
*/

#include "struct.h"

void write_score(run_t *run)
{
    int fd = open("asset/score.txt", O_WRONLY);
    char *new_score = my_itos(run->best->score, 10);
    ssize_t len = my_strlen(new_score);

    write(fd, new_score, len);
    close(fd);
}

void check_best(run_t *run)
{
    if (check_file("asset/score.txt") == 1)
        return;
    run->best->score = my_getnbr(load_file("asset/score.txt"));
    if (run->score->score >= run->best->score) {
        run->best->score = run->score->score;
        write_score(run);
    }
    sfText_setString(run->best->txt, my_itos(run->best->score, 10));
}