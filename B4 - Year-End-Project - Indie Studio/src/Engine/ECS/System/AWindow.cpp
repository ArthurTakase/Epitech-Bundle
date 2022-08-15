/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AWindow
*/

#include "AWindow.hpp"

/**
 * It's a constructor for the AWindow class
 *
 * @param width The width of the window in pixels.
 * @param height The height of the window in pixels.
 * @param fps The number of frames per second.
 */
AWindow::AWindow(int width, int height, int fps) noexcept
    : width_(width)
    , height_(height)
    , fps_(fps)
{
}

/**
 * This function returns the width of the window.
 *
 * @return The width of the window.
 */
int AWindow::getWidth() const noexcept
{
    return (width_);
}

/**
 * This function returns the height of the window.
 *
 * @return The height of the window.
 */
int AWindow::getHeight() const noexcept
{
    return (height_);
}

/**
 * It returns the value of the private member variable fps_.
 *
 * @return The fps_ variable.
 */
float AWindow::getFps() const noexcept
{
    return (fps_);
}
