/*
** EPITECH PROJECT, 2021
** minishell2 (< et <<)
** File description:
** stdin
*/

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>

int get_stdin(command_t *cmd, char **txt)
{
    int start;
    int len;

    cmd->nb_redir_in = how_many_in(*txt, "<");
    if (cmd->nb_redir_in > 2 || cmd->nb_redir_in <= 0) {
        cmd->stdin_str = "/dev/stdin";
        return 0;
    }
    start = get_start(*txt, '<');
    cmd->stdin_str = copy_strpart(*txt, start + cmd->nb_redir_in, &len, "|> ");
    *txt = rm_strpart(*txt, start, len + cmd->nb_redir_in);
    if (my_strlen(cmd->stdin_str) == 0)
        cmd->stdin_str = NULL;
    return 0;
}

int get_double_in(int fd, char *limit)
{
    size_t n = 0;
    char *buffer = NULL;

    if (getline(&buffer, &n, stdin) == -1)
        return 0;
    if (!my_strcmp(buffer, limit))
        return -1;
    write(fd, buffer, my_strlen(buffer));
    free(buffer);
    return 1;
}

int double_in(dlistnode_t *temp)
{
    int fds[2];
    int temp_int;
    char *limit = my_strcat(temp->infos->stdin_str, "\n");

    pipe(fds);
    while (1) {
        my_putstr("? ");
        if ((temp_int = get_double_in(fds[1], limit)) == 0)
            return 0;
        else if (temp_int == -1)
            break;
    }
    free(limit);
    close(fds[1]);
    return fds[0];
}