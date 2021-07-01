/*
** EPITECH PROJECT, 2020
** get color
** File description:
** get color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int	color;

    color = red;
    color = color << 8;
    color += green;
    color = color << 8;
    color += blue;
    return color;
}
