/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Fps
*/

#include "Fps.hpp"

#include "raylib.h"

/**
 * Draw the FPS counter at the specified coordinates
 *
 * @param x The x coordinate of the top left corner of the text.
 * @param y The y coordinate of the FPS counter.
 */
void FpsHandler::draw(int x, int y)
{
    DrawFPS(x, y);
}

/**
 * It sets the target FPS
 *
 * @param fps The target FPS to be set.
 */
void FpsHandler::setFps(float fps) noexcept
{
    SetTargetFPS(fps);
}