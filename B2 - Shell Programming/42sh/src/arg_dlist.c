/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** arg
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "lib.h"

char **split(char *txt, char *sep)
{
    int nb_word = how_many_in(txt, sep);
    char *saveptr = NULL;
    char *token = strtok_r(txt, sep, &saveptr);
    char **result = malloc(sizeof(char *) * (nb_word + 2));
    int i = 1;

    result[i - 1] = clonestr(token);
    for (;(token = strtok_r(saveptr, sep, &saveptr)) != NULL; i++)
        result[i] = clonestr(token);
    result[i] = NULL;
    return result;
}

command_t *split_list(char *txt)
{
    command_t *cmd = malloc(sizeof(command_t));

    get_stdout(cmd, &txt);
    get_stdin(cmd, &txt);
    cmd->original_cmd = clonestr(txt);
    cmd->is_pipe = how_many_in(txt, "|");
    cmd->cmd = split(txt, " ");
    return cmd;
}

void split_limit_list(char *str, shell_t *shell)
{
    char *saveptr = NULL;
    char *limit[4] = {";", "&&", "||", NULL};
    char *part = my_strtok_r(str, limit, &saveptr);

    shell->cmd = push_back_dlist(shell->cmd, split_list(part));
    while (saveptr != NULL) {
        part = my_strtok_r(saveptr, limit, &saveptr);
        shell->cmd = push_back_dlist(shell->cmd, split_list(part));
    }
}

void get_command_list(shell_t *shell)
{
    size_t n = 0;
    char *buffer = NULL;
    char *clean_buffer;
    shell->cmd = new_dlist();

    if (getline(&buffer, &n, stdin) == -1)
        exit(0);
    if (buffer[0] == '\n')
        return;
    if (buffer[my_strlen(buffer) - 1] == '\n')
        buffer[my_strlen(buffer) - 1] = '\0';
    clean_buffer = clean_str(buffer);
    split_limit_list(clean_buffer, shell);
    free(buffer);
    free(clean_buffer);
}