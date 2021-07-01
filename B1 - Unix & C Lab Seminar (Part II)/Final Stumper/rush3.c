/*
** EPITECH PROJECT, 2020
** final stumper
** File description:
** rush3
*/

#include "include/my.h"

int get_corner(char *get);

int height(char *buff);

int width(char *buff);

int choice_p2(char *buff, char *get)
{
    if (get_corner(get) == 1 && buff[1] == '-'
        && buff[width(buff) + 1] == '|')
        return 1;
    if (get_corner(get) == 2 && buff[1] == buff[width(buff) + 1]
        && buff[1] == '*')
        return 2;
    if (get_corner(get) == 3 && buff[1] == 'B'
        && buff[1] == buff[width(buff) + 1])
        return 3;
    if (get_corner(get) == 4 && buff[1] == 'B'
        && buff[1] == buff[width(buff) + 1])
        return 4;
    if (get_corner(get) == 5 && buff[1] == 'B'
        && buff[1] == buff[width(buff) + 1])
        return 5;
    return 0;
}

// Return the value of the good tab
int choice(char *buff, char *get)
{
    int temp;

    if (get[1] == 'k') {
        if (get[0] == 'o')
            return 1;
        if (get[0] == '*')
            return 2;
        if (get[0] == 'B')
            return 6;
    } else if (get_corner(get) != 10){
        if ((temp = choice_p2(buff, get)))
            return temp;
    }
    return 10;
}

// Putchar function
void show_special(int len_width, int len_height, int choice)
{
    my_putstr("[rush1-");
    if (choice == 6) {
        my_putstr("3] ");
        my_put_nbr(len_width);
        my_putchar(' ');
        my_put_nbr(len_height);
        my_putstr(" || [rush1-4] ");
        my_put_nbr(len_width);
        my_putchar(' ');
        my_put_nbr(len_height);
        my_putstr(" || [rush1-5");
    } else
        my_put_nbr(choice);
    my_putstr("] ");
    my_put_nbr(len_width);
    my_putchar(' ');
    my_put_nbr(len_height);
    my_putchar('\n');
}

// Get corners values
int rush3(char *buff)
{
    int int_choice;
    char get[4] = {buff[0], buff[width(buff) - 1], buff[my_strlen(buff) - 2],
        buff[my_strlen(buff) - 1 - width(buff)]};

    if (height(buff) > 0) {
        if (width(buff) == 1 || height(buff) == 1)
            int_choice = choice(buff, get);
        else
            int_choice = choice(buff, get);
        if (int_choice != 10)
            show_special(width(buff), height(buff), int_choice);
        else
            my_putstr("none\n");
        return 0;
    }
    return 84;
}
