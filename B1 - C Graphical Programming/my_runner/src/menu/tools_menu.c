/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** tools_menu
*/

#include "struct.h"

int check_button(run_t *run, button_t coord)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(run->window);

    if (mouse.x < coord.x + coord.width && mouse.y < coord.y + coord.height &&
        mouse.x > coord.x && mouse.y > coord.y)
        return 1;
    return 0;
}