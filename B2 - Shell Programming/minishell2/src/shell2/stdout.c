/*
** EPITECH PROJECT, 2021
** minishell2 (60%, functionnal) (copie)
** File description:
** stdout
*/

#include "minishell.h"

int get_start(char *txt, char sign)
{
    for (int i = 0; txt[i] != '\0'; i++) {
        if (txt[i] == sign)
            return i;
    }
    return -1;
}

int get_stdout(command_t *cmd, char **txt)
{
    int start;
    int len;

    cmd->nb_redir = how_many_in(*txt, ">");
    if (cmd->nb_redir > 2 || cmd->nb_redir <= 0) {
        cmd->stdout_str = "/dev/stdout";
        return 0;
    }
    start = get_start(*txt, '>');
    cmd->stdout_str = copy_strpart(*txt, start + cmd->nb_redir, &len, "|< ");
    *txt = rm_strpart(*txt, start, len + cmd->nb_redir);
    if (my_strlen(cmd->stdout_str) == 0)
        cmd->stdout_str = NULL;
    return 0;
}