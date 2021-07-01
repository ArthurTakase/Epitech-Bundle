/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef struct s_shell {
    char **env;
    char **command;
    char **path;
    char *prompt;
    char *home;
} shell_t;

char **get_command(void);
char **parse(char *argv);
void execute_command(shell_t *shell);
char **get_path(char **env);
int execute_built(shell_t *shell);
int in_list(char *commande);

int show_env(shell_t *shell);
int funct_cd(shell_t *shell);
int funct_setenv(shell_t *shell);
int funct_unsetenv(shell_t *shell);

int len_array(char **array);
int check_loop(char **env, char *search);
int check_start(char *env, char *search);
int my_end(char const *msg, int const x);

char *set_prompt(void);
void clean_path(char **path);
char **my_clone(char **src);

int exe_bash(shell_t *shell);

#endif