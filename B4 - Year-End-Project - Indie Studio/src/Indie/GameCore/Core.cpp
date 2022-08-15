/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Core
*/

#include "Core.hpp"

#include "Game.hpp"
#include "Home.hpp"
#include "Load.hpp"
#include "PlayerSelect.hpp"
#include "Splash.hpp"

/**
 * It initializes the window, the game models, the sprites, and the scenes
 */
Core::Core() noexcept
    : window_(std::make_unique<WindowManager>(1920, 1040, 60))
{
    initGameModels();
    initSprites();
    initScenes();
}

/**
 * It unloads all the data, resets all the scenes, and resets the window
 */
Core::~Core() noexcept
{
    data_.unloadAll();
    for (auto& scene : scenes) { scene.reset(); }
    window_.reset();
}

/**
 * It switches the current scene to the one specified in the parameter
 *
 * @param scene The scene to switch to.
 */
void Core::switchScene(const bomberman::SceneType& scene) noexcept
{
    data_.setCurrentScene(scene);
    findScene().playMusic();
    findScene().switchAction();
}

/**
 * The function runs the game loop
 */
void Core::run() noexcept
{
    while (!exit_) {
        checkExit();
        checkCamera();
        AudioDevice::update(findScene());
        data_.updateMouse();
        findScene().action();
        displayScene();
    }
}

/**
 * It displays the scene
 */
void Core::displayScene() noexcept
{
    window_->display(findScene(), camera_);
}

/**
 * If the camera is moving, then move it
 */
void Core::checkCamera() noexcept
{
    if (camera_.getIsMoving()) camera_.setIsMoving(camera_.smoothMove());
}

/**
 * If the window is marked for exit, then mark the core for exit
 */
void Core::checkExit() noexcept
{
    if (window_->isExit()) { setExit(true); }
}

/**
 * It returns a reference to the WindowManager object
 *
 * @return A reference to the window_ object.
 */
WindowManager& Core::getWindow() noexcept
{
    return (*window_);
}

/**
 * It returns a reference to the cameraman
 *
 * @return A reference to the cameraman.
 */
MyCameraman& Core::getCameraman() noexcept
{
    return (camera_);
}

/**
 * It loads all the models and textures used in the game
 */
void Core::initGameModels() noexcept
{
    data_.addModel("assets/models/bomb.glb", "assets/textures/entities/bomb.png");
    data_.addModel("assets/models/box.glb", "assets/textures/entities/wall.png");
    data_.addModel("assets/models/box.glb", "assets/textures/entities/box.png");
    data_.addModel("assets/models/item.glb", "assets/textures/items/i_roller.png");
    data_.addModel("assets/models/item.glb", "assets/textures/items/i_bomb.png");
    data_.addModel("assets/models/item.glb", "assets/textures/items/i_fire.png");
    data_.addModel("assets/models/item.glb", "assets/textures/items/item.png");
    data_.addModel("assets/models/fire.iqm", "assets/textures/entities/fire.png");
    data_.addModel("assets/models/player.iqm", "assets/textures/player/white.png");
    data_.addModel("assets/models/player.iqm", "assets/textures/player/black.png");
    data_.addModel("assets/models/player.iqm", "assets/textures/player/blue.png");
    data_.addModel("assets/models/player.iqm", "assets/textures/player/red.png");
}

/**
 * It adds sprites to the data_ member of the Core class
 */
void Core::initSprites() noexcept
{
    data_.addSprite("assets/icones/white.png", 0.5f);
    data_.addSprite("assets/icones/black.png", 0.5f);
    data_.addSprite("assets/icones/blue.png", 0.5f);
    data_.addSprite("assets/icones/red.png", 0.5f);
    data_.addSprite("assets/textures/home/splash.png", 1);
    data_.addSprite("assets/textures/home/background.png", 1.1);
    data_.addSprite("assets/icones/white.png", 0.5f);
    data_.addSprite("assets/textures/home/splash_team.png", 0.98);
}

/**
 * It creates a vector of unique pointers to scenes, and then switches to the splash scene
 */
void Core::initScenes() noexcept
{
    scenes.emplace_back(std::make_unique<Home>(*this));
    scenes.emplace_back(std::make_unique<Game>(*this));
    scenes.emplace_back(std::make_unique<PlayerSelect>(*this));
    scenes.emplace_back(std::make_unique<Splash>(*this));
    scenes.emplace_back(std::make_unique<Load>(*this));
    findScene().playMusic();
    switchScene(bomberman::SceneType::SPLASH);
}
