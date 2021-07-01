/*
** EPITECH PROJECT, 2021
** minishell2 (|)
** File description:
** pipe
*/

#include "minishell.h"
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char ***split_multiple_pipe(dlistnode_t *temp)
{
    char ***all_cmd = malloc(sizeof(char **) * (temp->infos->is_pipe + 2));
    char *saveptr = NULL;
    char *part = strtok_r(temp->infos->original_cmd, "|", &saveptr);
    int i = 0;

    all_cmd[i] = split(part, " ");
    while ((part = strtok_r(saveptr, "|", &saveptr)) != NULL) {
        i++;
        all_cmd[i] = split(part, " ");
    }
    i++;
    all_cmd[i] = NULL;
    return all_cmd;
}

void child_pipe(shell_t *shell, char ***cmd, int fdd, int fd[])
{
    dup2(fdd, STDIN_FILENO);
    if (*(cmd + 1) != NULL)
        dup2(fd[1], STDOUT_FILENO);
    shell->command = *cmd;
    close(fd[0]);
    child(shell);
    exit(0);
}

void all_wait(int *all_pid, int len)
{
    int waitstatus;

    for (int i = 0; i != len; i++) {
        waitpid(all_pid[i], &waitstatus, 0);
        return_value(waitstatus);
    }
}

void exec_pipe(shell_t *shell, dlistnode_t *temp)
{
    char ***cmd = split_multiple_pipe(temp);
    int fd[2];
    pid_t *pid = malloc(sizeof(pid_t) * (temp->infos->is_pipe + 1));
    int fdd = 0;

    for (int i = 0; *cmd != NULL; i++) {
        pipe(fd);
        if ((pid[i] = fork()) == 0)
            child_pipe(shell, cmd, fdd, fd);
        else if (pid[i] > 0) {
            close(fd[1]);
            fdd = fd[0];
            cmd++;
        }
    }
    close(fd[0]);
    all_wait(pid, temp->infos->is_pipe);
    free(pid);
    exit(0);
}