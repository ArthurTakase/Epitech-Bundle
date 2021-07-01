/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** l_option
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "../include/my_printf.h"

void set_color(struct stat *buf)
{
    if (buf->st_mode & S_IXUSR)
        my_printf("\033[0;32m");
    if (S_ISDIR(buf->st_mode))
        my_printf("\033[0;34m");
    if (buf->st_mode & S_ISVTX)
        my_printf("\033[0;42;30m");
    if (buf->st_mode & S_IFCHR)
        my_printf("\033[0;33;40m");
    
}

void show_perm(struct stat *buf)
{
    if (buf->st_mode & S_IFCHR)
        my_printf("c");
    else
        my_printf( (S_ISDIR(buf->st_mode)) ? "d" : "-");
    my_printf( (buf->st_mode & S_IRUSR) ? "r" : "-");
    my_printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
    my_printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
    my_printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
    my_printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
    my_printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
    my_printf( (buf->st_mode & S_IROTH) ? "r" : "-");
    my_printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
    if (buf->st_mode & S_ISVTX)
        my_printf("t");
    else
        my_printf( (buf->st_mode & S_IXOTH) ? "x" : "-");
}

void show_time(struct stat *buf)
{
    char *time = ctime(&buf->st_mtime);

    for (int i = 4; i <= 15; i++)
        my_printf("%c", time[i]);
}

void l_option(char const *filepath, char const *name)
{
    struct stat *buf = malloc(sizeof(struct stat));
    struct passwd *pw = malloc(sizeof(struct passwd));
    struct group *gr = malloc(sizeof(struct group));

    stat(filepath, buf);
    pw = getpwuid(buf->st_uid);
    gr = getgrgid(buf->st_gid);
    show_perm(buf);
    my_printf(". ");
    my_printf("%d %s %s ", buf->st_nlink, pw->pw_name, gr->gr_name);
    my_printf("%d ", buf->st_size);
    show_time(buf);
    my_printf(" ");
    set_color(buf);
    my_printf("%s", name);
    my_printf("\033[0m\n");
    free(buf);
}