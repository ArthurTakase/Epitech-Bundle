/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Splash
*/

#include "Splash.hpp"

#include "DeltaTime.hpp"

/**
 * It's a constructor for the Splash scene
 *
 * @param core_ref This is a reference to the core class. This is used to change the scene.
 */
Splash::Splash(Core& core_ref) noexcept
    : Scene()
    , core_entry_(core_ref)
    , background_color_(Colors::C_BLACK)
    , timer(5)
    , opacity_(255)
    , splashSound_(Splash::SPLASH_SCREEN)
{
    splashSound_.play();
}

/**
 * It does nothing
 */
void Splash::switchAction() noexcept {}

/**
 * If the timer is done, switch to the menu scene
 */
void Splash::action() noexcept
{
    timer.updateTimer();

    if (timer.isTimerDone()) core_entry_.switchScene(bomberman::SceneType::MENU);
}

/**
 * It does nothing
 */
void Splash::playMusic() noexcept {}

/**
 * It does nothing
 */
void Splash::updateMusic() const noexcept {}

/**
 * It returns the background color of the splash screen
 *
 * @return The background color of the splash screen.
 */
ColorManager Splash::getBackgroundColor() const noexcept
{
    return (background_color_);
}

/**
 * It draws the FPS counter and the splash screen
 *
 * @return A reference to the sprites vector in the Data class.
 */
void Splash::SystemDisplay() noexcept
{
    FpsHandler::draw(10, 10);

    auto& sprites = core_entry_.getData().getSprites();
    if (sprites.size() == 0) return;
    sprites[4]->draw({ 255, 255, 255, opacity_ });
    sprites[7]->draw({ 255, 255, 255, static_cast<unsigned char>(255 - opacity_) });

    if (timer.getTime() > 3) return;
    if (opacity_ > 0) opacity_ -= 120 * DeltaTime::getDeltaTime();
    else
        opacity_ = 0;
}