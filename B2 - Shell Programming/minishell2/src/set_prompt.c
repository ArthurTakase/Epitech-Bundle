/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** set_prompt
*/

#include <sys/types.h>
#include <unistd.h>

char *set_prompt(void)
{
    int pid = getpid();

    if (pid % 9 == 0)
        return "🐻 -> ";
    if (pid % 8 == 0)
        return "🐼 -> ";
    if (pid % 7 == 0)
        return "🦊 -> ";
    if (pid % 6 == 0)
        return "🐸 -> ";
    if (pid % 5 == 0)
        return "🐧 -> ";
    if (pid % 4 == 0)
        return "🦈 -> ";
    if (pid % 3 == 0)
        return "🦝 -> ";
    if (pid % 2 == 0)
        return "🐢 -> ";
    return "🦅 -> ";
}