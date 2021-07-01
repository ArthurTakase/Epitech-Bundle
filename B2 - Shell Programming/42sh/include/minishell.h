/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "define.h"
#include "lib.h"
#include "dlist.h"

#include <stdlib.h>

typedef struct s_shell {
    dlist_t cmd;
    char **command;
    char **env;
    char **path;
    char *prompt;
    char *home;
    dlistnode_t *temp;
} shell_t;

//INIT
char *set_prompt(void);

// GET
void get_command_list(shell_t *shell);
char **get_path(char **env);
int get_home(shell_t *shell);

// EXECUTE
void execute_command(shell_t *shell, dlistnode_t *temp);
int execute_built(shell_t *shell, dlistnode_t *temp);
int exe_bash(shell_t *shell);

// TOOLS
int in_list(char *commande);
int check_loop(char **env, char *search);
int check_start(char *env, char *search);
int my_error(char const *msg, int const x);
char **my_clone(char **src);
void print_2darray(char **array);
void print_3darray(char ***array);
void print_dlist(dlist_t cmd);
char **split(char *txt, char *sep);
int get_start(char *txt, char sign);
void return_value(int waitstatus);
char *add_home_if(char *str, shell_t *shell);

// BUILT IN
int show_env(shell_t *shell);
int funct_cd(shell_t *shell);
int funct_setenv(shell_t *shell);
int funct_unsetenv(shell_t *shell);
int check_dir(char *path, char *command);
int classic_cd(shell_t *shell);
int home_cd(shell_t *shell);
int cd_dot(shell_t *shell);
int funct_echo(shell_t *shell);

// OTHER
void edit_pwd(shell_t *shell);
void edit_oldpwd(shell_t *shell);
void my_handle(int sig);
int loop_shell(shell_t *shell);

// STDOUT
int get_stdout(command_t *cmd, char **txt);
void exec_pipe(shell_t *shell, dlistnode_t *temp);
void child(shell_t *shell);

// STDIN
int get_stdin(command_t *cmd, char **txt);
int double_in(dlistnode_t *temp);

#endif