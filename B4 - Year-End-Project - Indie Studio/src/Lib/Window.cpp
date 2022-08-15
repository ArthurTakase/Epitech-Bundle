/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window
*/

#include "Window.hpp"

/**
 * It initializes the window and sets the fps
 *
 * @param width the width of the window
 * @param height the height of the window
 * @param fps The number of frames per second the game will run at.
 */
WindowManager::WindowManager(int width, int height, int fps) noexcept
    : AWindow(width, height, fps)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width_, height_, "Indie Studio - Bomberman");
    AudioDevice::initialize();
    FpsHandler::setFps(fps_);
}

/**
 * It closes the audio device and closes the window
 */
WindowManager::~WindowManager() noexcept
{
    AudioDevice::close();
    CloseWindow();
}

/**
 * It clears the screen and draws the scene
 *
 * @param scene The scene to display.
 * @param camera The camera that will be used to render the scene.
 */
void WindowManager::display(Scene& scene, const Cameraman& camera) noexcept
{
    auto  color = scene.getBackgroundColor().getColor();
    Color col   = { color[0], color[1], color[2], 255 };

    BeginDrawing();
    ClearBackground(col);
    scene.SystemDisplay();
    EndDrawing();
}

/**
 * This function returns true if the window should close, and false otherwise
 *
 * @return A boolean value.
 */
bool WindowManager::isExit() noexcept
{
    return (WindowShouldClose());
}

/**
 * It resets the height of the window to the height of the screen
 */
void WindowManager::resetHeight() noexcept
{
    height_ = GetScreenHeight();
}

/**
 * It resets the width of the window to the width of the screen
 */
void WindowManager::resetWidth() noexcept
{
    width_ = GetScreenWidth();
}

/**
 * It sets the fps_ member variable to the value passed in, and then calls the FpsHandler::setFps()
 * function to set the fps_ member variable in the FpsHandler class
 *
 * @param value The new FPS value.
 */
void WindowManager::setFps(float value) noexcept
{
    fps_ = value;
    FpsHandler::setFps(fps_);
}

/**
 * Decrease the fps by 30 if it's not already at 30
 *
 * @return A reference to the WindowManager object.
 */
void WindowManager::decreaseFps() noexcept
{
    if (fps_ == 30) return;
    index_--;
    fps_ = possible_fps_[index_];
    FpsHandler::setFps(fps_);
}

/**
 * If the fps is not 120, increase the fps by 30
 *
 * @return A reference to the WindowManager object.
 */
void WindowManager::increaseFps() noexcept
{
    if (fps_ == 120) return;
    index_++;
    fps_ = possible_fps_[index_];
    FpsHandler::setFps(fps_);
}

/**
 * Increase the music volume by 10% if it's not already at 100%
 *
 * @return A pointer to the WindowManager object.
 */
void WindowManager::increaseMusic() noexcept
{
    if (music_percent_ == 100) return;
    music_percent_ = music_percent_ + 10;
    AudioDevice::setMusic(music_percent_);
}

/**
 * Decrease the music volume by 10% if it's not already at 0%
 *
 * @return A pointer to the WindowManager object.
 */
void WindowManager::decreaseMusic() noexcept
{
    if (music_percent_ == 0) return;
    music_percent_ = music_percent_ - 10;
    AudioDevice::setMusic(music_percent_);
}

/**
 * This function returns the music percentage.
 *
 * @return The music_percent_ variable is being returned.
 */
int WindowManager::getMusicPercentage() const noexcept
{
    return (music_percent_);
}