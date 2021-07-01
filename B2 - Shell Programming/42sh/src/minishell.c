/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** minishell
*/

#include <stdlib.h>
#include <signal.h>
#include "minishell.h"
#include "lib.h"

void init_shell(shell_t *shell, char **env, int argc, char **argv)
{
    int index;

    argc = argc;
    argv = argv;
    shell->env = my_clone(env);
    shell->path = get_path(shell->env);
    shell->prompt = set_prompt();
    if ((index = check_loop(env, "HOME")) != -1)
        shell->home = clonestr(shell->env[index] + 5);
    else
        shell->home = NULL;
}

void free_all(shell_t *shell)
{
    clean_2darray(shell->path);
    clean_2darray(shell->env);
    free(shell->home);
    shell->cmd = clear_dlist(shell->cmd);
}

int minishell(int argc, char **argv, char **env)
{
    shell_t shell;

    init_shell(&shell, env, argc, argv);
    signal(SIGINT, my_handle);
    while (!loop_shell(&shell));
    free_all(&shell);
    my_putstr("exit\n");
    return 0;
}