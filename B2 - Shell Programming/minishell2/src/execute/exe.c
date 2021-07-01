/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** exe
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "lib.h"
#include "minishell.h"

void execute_path(shell_t *shell)
{
    DIR *dir;
    char *next_path;

    for (int i = 0; shell->path[i] != NULL; i++) {
        dir = opendir(shell->path[i]);
        if (dir != NULL) {
            next_path = my_strcat(my_strcat(shell->path[i], "/"),
            shell->command[0]);
            execve(next_path, shell->command, shell->env);
        }
    }
}

void child(shell_t *shell)
{
    if (my_in('/', shell->command[0])) {
        exe_bash(shell);
        execve(shell->command[0], shell->command, shell->env);
    } else if (shell->path != NULL)
        execute_path(shell);
    my_putstr(shell->command[0]);
    my_putstr(": Command not found.\n");
    exit(127);
}

void return_value(int waitstatus)
{
    if (WIFSIGNALED(waitstatus)) {
        if (WTERMSIG(waitstatus) == SIGFPE)
            write(2, "Floting exception", 18);
        if (WTERMSIG(waitstatus) == SIGSEGV)
            write(2, "Segmentation fault", 19);
        if (WCOREDUMP(waitstatus))
            write(2, "(core dumped)\n", 15);
        else
            write(2, "\n", 1);
    }
}

void execute_command(shell_t *shell, dlistnode_t *temp)
{
    pid_t pid = fork();
    int waitstatus;

    if (pid == 0) {
        if (temp->infos->is_pipe)
            exec_pipe(shell, temp);
        child(shell);
    }
    if (pid > 0) {
        wait(&waitstatus);
        return_value(waitstatus);
    }
}