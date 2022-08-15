/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Load
*/

#include "Load.hpp"

#include <algorithm>
#include <exception>
#include <filesystem>
#include <iostream>
#include <string>

#include "Bomberman.hpp"

/**
 * It initializes the Load class
 *
 * @param core_ref The core reference.
 */
Load::Load(Core& core_ref) noexcept
    : loop_music_(MUSIC)
    , core_entry_(core_ref)
    , background_color_(Colors::C_WHITE)
    , background_(BG_PATH, 0, 0, 1.1)
    , title_(TITLE_PATH, 30, 30, 0.5)
    , title_text_(FONT_PATH, "Pick a save :", 0, 0)
{
    title_text_.setTextSize(40);
    title_text_.setPosition(
        core_entry_.getWindow().getWidth() / 2, core_entry_.getWindow().getHeight() / 9);
    createButtons();
    createIllustrations();
}

/**
 * It creates the illustrations
 * that are displayed on the screen
 */
void Load::createIllustrations() noexcept
{
    float width  = core_entry_.getWindow().getWidth();
    float height = core_entry_.getWindow().getHeight();

    illustrations_.emplace_back(
        "assets/textures/load/white_bomber.png", width / 6 - 10, height / 6 + 30);
    illustrations_.emplace_back(
        RED_IMG, width / 6 + (490 * illustrations_.size()), height / 6 + 30);
    illustrations_.emplace_back(
        BLACK_IMG, width / 6 + (495 * illustrations_.size()), height / 6 + 30);
}

void Load::initTexts() noexcept
{
    while (load_names_.size() < 3) { load_names_.emplace_back(FONT_PATH, "No Save", 0, 0); }
}
/**
 * It draws all the illustrations
 */
void Load::drawIllustrations() const noexcept
{
    for (auto& it : illustrations_) { it.draw(); }
}

/**
 * It creates the buttons for the load scene
 *
 * @return the scene type of the game.
 */
void Load::createButtons() noexcept
{
    float width  = core_entry_.getWindow().getWidth();
    float height = core_entry_.getWindow().getHeight();

    getSavesNames();
    for (int i = 0; i < 3; i++) {
        auto name = load_names_[i].getText();
        if (name.compare("No Save")) {
            buttons_.emplace_back(BUTTON_PATH,
                width / 6 + (500 * buttons_.size()),
                height - (height / 3),
                std::function<void(void)>([this, name]() {
                    core_entry_.getData().setTryToLoad(name);
                    core_entry_.switchScene(bomberman::SceneType::GAME);
                }),
                FONT_PATH,
                name.substr(5),
                130,
                0,
                false);
            remove_.emplace_back(BUTTON_PATH,
                width / 6 + (500 * remove_.size()),
                height - (height / 5),
                std::function<void(void)>([this, name]() {
                    std::remove(name.c_str());
                    core_entry_.switchScene(bomberman::SceneType::LOAD);
                }),
                FONT_PATH,
                "remove",
                0,
                0,
                false);
        } else {
            buttons_.emplace_back(BUTTON_PATH,
                width / 6 + (500 * buttons_.size()),
                height - (height / 3),
                std::function<void(void)>([this, i]() { return; }),
                FONT_PATH,
                load_names_[i].getText(),
                20,
                0,
                false);
        }
    }
    buttons_.emplace_back("assets/textures/selection/close.png",
        width / 4 + 1200,
        height / 10,
        std::function<void(void)>(
            [this](void) { core_entry_.switchScene(bomberman::SceneType::MENU); }),
        "assets/fonts/menu.ttf",
        "",
        0,
        0,
        false);
}

/**
 * It gets the names of the saves in the save folder and puts them in a vector
 */
void Load::getSavesNames() noexcept
{
    int nbSave = 0;

    try {
        for (const auto& entry : std::filesystem::directory_iterator(SAVE_PATH)) {
            if (nbSave >= 3) break;
            if (load_names_.size() > 0) load_names_.pop_back();
            auto path = static_cast<std::string>(entry.path().string());

            load_names_.emplace(load_names_.begin(), FONT_PATH, path, 0, 0);
            nbSave++;
        }
    } catch (std::exception err) {
        std::filesystem::create_directory("Save");
        getSavesNames();
    }
    initTexts();
}

/**
 * It teleports the cameraman to a new position
 */
void Load::switchAction() noexcept
{
    core_entry_.getCameraman().tpTo(
        { 4.0f, 2.0f, 1.5f }, { 0.0f, 1.0f, 1.5f }, { 0.0f, 2.0f, 0.0f });
    buttons_.clear();
    remove_.clear();
    load_names_.clear();
    initTexts();
    createButtons();
}

/**
 * It draws all the buttons in the buttons_ vector
 */
void Load::drawButtons() const noexcept
{
    for (auto& it : buttons_) { it.draw(); }
    for (auto& it : remove_) { it.draw(); }
}

/**
 * If the mouse is hovering over a button, then call the button's action function.
 */
void Load::action() noexcept
{
    for (auto& it : buttons_)
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
    for (auto& it : remove_)
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
}

/**
 * It plays the music
 */
void Load::playMusic() noexcept
{
    loop_music_.play();
}

/**
 * It updates the music
 */
void Load::updateMusic() const noexcept
{
    loop_music_.update();
}

/**
 * It returns the background color of the load object
 *
 * @return A ColorManager object.
 */
ColorManager Load::getBackgroundColor() const noexcept
{
    return (background_color_);
}

/**
 * It draws the background, title, FPS, title text, buttons, and illustrations
 */
void Load::SystemDisplay() noexcept
{
    background_.draw({ 255, 255, 255, 175 });
    title_.draw();
    FpsHandler::draw(10, 10);
    title_text_.draw();
    drawButtons();
    drawIllustrations();
}
