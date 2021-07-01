/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** len_array
*/

int len_array(char **array)
{
    int i = 0;

    while (*array) {
        i++;
        array++;
    }
    return i;
}

int len_3darray(char ***array)
{
    int i = 0;

    while (*array) {
        i++;
        array++;
    }
    return i;
}