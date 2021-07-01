/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** dlist
*/

#ifndef DLIST_H_
#define DLIST_H_

typedef struct s_command
{
    char **cmd;
    char *stdout_str;
    int nb_redir;
    char *original_cmd;
    int is_pipe;
    char *stdin_str;
    int nb_redir_in;
} command_t;

typedef struct s_dlistnode
{
    command_t *infos;
    struct s_dlistnode *back;
    struct s_dlistnode *next;
} dlistnode_t;

typedef struct s_dlist
{
    int len;
    struct s_dlistnode *begin;
    struct s_dlistnode *end;
} *dlist_t;

dlist_t push_back_dlist(dlist_t li, command_t *cmd);
dlist_t push_front_dlist(dlist_t li, command_t *cmd);
dlist_t pop_back_dlist(dlist_t li);
dlist_t pop_front_dlist(dlist_t li);
dlist_t clear_dlist(dlist_t li);
dlist_t new_dlist(void);
int is_empty_dlist(dlist_t li);
int dlist_len(dlist_t li);

#endif /* !DLIST_H_ */