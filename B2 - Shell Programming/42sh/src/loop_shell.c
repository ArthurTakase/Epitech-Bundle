/*
** EPITECH PROJECT, 2021
** minishell2 (60%, functionnal) (copie)
** File description:
** loop_shell
*/

#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>

int switch_stdout(dlistnode_t *temp, int *saved_fd, int *fd)
{
    if (temp->infos->nb_redir > 2 || temp->infos->stdout_str == NULL)
        return errormsg(0, "Missing name for redirect.\n");
    *saved_fd = dup(STDOUT_FILENO);
    if (temp->infos->nb_redir == 0)
        *fd = *saved_fd;
    else if (temp->infos->nb_redir == 1)
        *fd = open(temp->infos->stdout_str, O_CREAT | O_TRUNC | O_RDWR, 0644);
    else
        *fd = open(temp->infos->stdout_str, O_CREAT | O_APPEND | O_RDWR, 0644);
    dup2(*fd, STDOUT_FILENO);
    return 1;
}

int switch_stdin(dlistnode_t *temp, int *saved_fd, int *fd)
{
    if (temp->infos->nb_redir_in > 2 || temp->infos->stdin_str == NULL)
        return errormsg(0, "Missing name for redirect.\n");
    *saved_fd = dup(STDIN_FILENO);
    if (temp->infos->nb_redir_in == 2)
        *fd =  double_in(temp);
    else if (temp->infos->nb_redir_in == 1)
        *fd = open(temp->infos->stdin_str, O_RDONLY, 0644);
    else
        *fd = *saved_fd;
    dup2(*fd, STDIN_FILENO);
    return 1;
}

int loop_p2(shell_t *shell, dlistnode_t *temp)
{
    int saved_fd;
    int fd;
    int saved_fd_in;
    int fd_in;

    shell->command = temp->infos->cmd;
    if (!switch_stdin(temp, &saved_fd_in, &fd_in))
        return 0;
    switch_stdout(temp, &saved_fd, &fd);
    if (!my_strcmp(shell->command[0], "exit"))
        return 1;
    if (!execute_built(shell, temp))
        execute_command(shell, temp);
    close(fd);
    close(fd_in);
    dup2(saved_fd, STDOUT_FILENO);
    dup2(saved_fd_in, STDIN_FILENO);
    return 0;
}

int loop_shell(shell_t *shell)
{
    dlistnode_t *temp;

    my_putstr(shell->prompt);
    get_command_list(shell);
    if (shell->cmd == NULL)
        return 0;
    temp = shell->cmd->begin;
    for (; temp != NULL; temp = temp->next) {
        if (loop_p2(shell, temp))
            return 1;
    }
    shell->cmd = clear_dlist(shell->cmd);
    return 0;
}