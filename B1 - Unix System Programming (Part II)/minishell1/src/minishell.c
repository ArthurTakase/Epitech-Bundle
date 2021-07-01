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

void my_handle(int sig)
{
    sig = sig;
    my_putstr("\n📛 -> ");
}

void init_shell(shell_t *shell, char **env)
{
    int index = check_loop(env, "HOME");

    shell->env = my_clone(env);
    shell->path = get_path(shell->env);
    shell->prompt = set_prompt();
    shell->home = clonestr(shell->env[index] + 5);
}

void free_all(shell_t *shell)
{
    clean_path(shell->command);
    clean_path(shell->path);
    clean_path(shell->env);
    free(shell->home);
}

int minishell(int argc, char **argv, char **env)
{
    shell_t shell;

    argv = argv;
    argc = argc;
    init_shell(&shell, env);
    signal(SIGINT, my_handle);
    while (1) {
        my_putstr(shell.prompt);
        shell.command = get_command();
        if (shell.command[0] == NULL)
            continue;
        if (!my_strcmp(shell.command[0], "exit"))
            break;
        if (!execute_built(&shell))
            execute_command(&shell);
        clean_path(shell.command);
    }
    free_all(&shell);
    my_putstr("exit\n");
    return 0;
}