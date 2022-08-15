/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** DeltaTime
*/

#include "DeltaTime.hpp"

#include "raylib.h"

/**
 * > This function returns the time in seconds it took to render the last frame
 *
 * @return The time it took to render the last frame.
 */
float DeltaTime::getDeltaTime() noexcept
{
    return GetFrameTime();
}