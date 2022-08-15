/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PlayerSelect
*/

#include "PlayerSelect.hpp"

#include "raylib.h"

/**
 * It creates the buttons, the background, the title, the text and the stats.
 *
 * @param core_ref A reference to the core object.
 */
PlayerSelect::PlayerSelect(Core& core_ref) noexcept
    : loop_music_(MUSIC)
    , core_entry_(core_ref)
    , background_color_(Colors::C_WHITE)
    , background_(BG_PATH, 0, 0, 1.1)
    , title_(TITLE_PATH, 30, 30)
    , choose_text_(SELECT, "Select players", 0, 0)
{
    choose_text_.setTextSize(40);
    choose_text_.setPosition(
        core_entry_.getWindow().getWidth() / 2, core_entry_.getWindow().getHeight() / 9);
}

/**
 * It draws the toggle button for the player selection screen
 *
 * @param id The id of the toggle.
 * @param position The position of the toggle.
 * @param isBot Whether the player is a bot or not.
 */
void PlayerSelect::drawToggle(const int id, const Vector2& position, bool isBot) noexcept
{
    if (!isBot) {
        toggle_auto_[id].setText("Player");
        toggle_auto_[id].setTextPosition({ position.x + 45, position.y + 30 });
    } else {
        toggle_auto_[id].setText("Bot");
        toggle_auto_[id].setTextPosition({ position.x + 80, position.y + 30 });
    }
    toggle_auto_[id].setPosition(position);
    toggle_auto_[id].draw();
}

/**
 * It draws the selection
 * arrows for the player with the given id
 *
 * @param id The id of the player.
 * @param pos_left The position of the left side of the selection.
 * @param pos_right The position of the right selection arrow.
 */
void PlayerSelect::drawSelection(
    const int id, const Vector2& pos_left, const Vector2& pos_right) noexcept
{
    select_left_[id].setPosition(pos_left);
    select_left_[id].draw();
    select_right_[id].setPosition(pos_right);
    select_right_[id].draw();
}

/**
 * It displays the stats of all the players in the game
 */
void PlayerSelect::displayAllStats() noexcept
{
    auto  height    = static_cast<float>(core_entry_.getWindow().getHeight());
    float nbPlayers = 0;

    for (auto& player : core_entry_.getData().getPlayers()) {
        Vector2 pos_l      = { 70 + 460 * nbPlayers, static_cast<float>(height - height / 7) + 40 };
        Vector2 pos_r      = { pos_l.x + 320, (height - height / 7) + 40 };
        Vector2 position   = { 120 + 460 * nbPlayers, 600 };
        Vector2 toggle_pos = { 140 + 460 * nbPlayers, 540 };
        displayPlayerStats(position,
            { pos_l.x + 85, pos_l.y + 25 },
            findStatsId(((std::unique_ptr<Player>&)player)->getType()));
        drawToggle(static_cast<int>(nbPlayers),
            toggle_pos,
            ((std::unique_ptr<Player>&)player)->getBotState());
        drawSelection(static_cast<int>(nbPlayers), pos_l, pos_r);
        nbPlayers++;
    }
}

/**
 * It returns the index of the stats array that corresponds to the given player type
 *
 * @param type The type of player to find the stats for.
 *
 * @return The index of the player type in the stats array.
 */
unsigned int PlayerSelect::findStatsId(const PlayerType& type) const noexcept
{
    if (type == PlayerType::NORMAL) { return (0); };
    if (type == PlayerType::ATTACK) { return (1); };
    if (type == PlayerType::TACTICAL) { return (2); };
    if (type == PlayerType::RUNNER) { return (3); };
    return (0);
}

/**
 * It displays the player's stats and texts
 *
 * @param stats_pos The position of the stats bar.
 * @param texts_pos The position of the text.
 * @param id The id of the player.
 */
void PlayerSelect::displayPlayerStats(
    const Vector2& stats_pos, const Vector2& texts_pos, unsigned int id) noexcept
{
    stats_[id].setPos(stats_pos.x, stats_pos.y);
    stats_[id].draw();
    texts_[id].setPosition(texts_pos.x, texts_pos.y);
    texts_[id].draw();
}

/**
 * It teleports the camera to a new position
 */
void PlayerSelect::switchAction() noexcept
{
    core_entry_.getCameraman().tpTo(
        { 4.0f, 2.0f, 1.5f }, { 0.0f, 1.0f, 1.5f }, { 0.0f, 2.0f, 0.0f });

    core_entry_.getData().getPlayers().clear();
    buttons_.clear();
    stats_.clear();
    select_left_.clear();
    select_right_.clear();
    toggle_auto_.clear();

    core_entry_.getData().setNbPlayers(0);

    createButtons();

    stats_.emplace_back(
        "assets/textures/selection/normal.png", core_entry_.getWindow().getWidth() / 2, 50);
    stats_.emplace_back("assets/textures/selection/attack.png");
    stats_.emplace_back("assets/textures/selection/tactical.png");
    stats_.emplace_back("assets/textures/selection/runner.png");
    texts_.emplace_back("assets/fonts/menu.ttf", "Balanced", 0, 0);
    texts_.emplace_back("assets/fonts/menu.ttf", "Attack", 0, 0);
    texts_.emplace_back("assets/fonts/menu.ttf", "Tactical", 0, 0);
    texts_.emplace_back("assets/fonts/menu.ttf", "Runner", 0, 0);
}

/**
 * It creates the buttons for the player selection scene
 */
void PlayerSelect::createButtons() noexcept
{
    int width  = core_entry_.getWindow().getWidth();
    int height = core_entry_.getWindow().getHeight();

    buttons_.emplace_back("assets/textures/home/button.png",
        width / 4 + 200,
        height / 6,
        std::function<void(void)>([this]() {
            if (core_entry_.getData().getNbPlayers() < 4) {
                core_entry_.getData().setNbPlayers(core_entry_.getData().getNbPlayers() + 1);
                core_entry_.getData().addPlayer(core_entry_.getData().getNbPlayers() - 1);
                Player& new_player =
                    *reinterpret_cast<Player*>(core_entry_.getData().getPlayers().back().get());
                toggle_auto_.emplace_back("assets/textures/home/button.png",
                    0,
                    0,
                    std::function<void(void)>([&new_player](void) { new_player.toggleBot(); }),
                    "assets/fonts/menu.ttf",
                    "Player",
                    0.8f);
                select_right_.emplace_back("assets/textures/selection/right.png",
                    0,
                    0,
                    std::function<void(void)>([&new_player]() {
                        new_player.setPlayerType(
                            static_cast<PlayerType>(new_player.findNextType()));
                    }),
                    "assets/fonts/menu.ttf",
                    "",
                    0.2f);
                select_left_.emplace_back("assets/textures/selection/left.png",
                    0,
                    0,
                    std::function<void(void)>([&new_player]() {
                        new_player.setPlayerType(
                            static_cast<PlayerType>(new_player.findPrevType()));
                    }),
                    "assets/fonts/menu.ttf",
                    "",
                    0.2f);
            }
        }),
        "assets/fonts/menu.ttf",
        "Add");

    buttons_.emplace_back("assets/textures/home/button.png",
        width / 4 + 550,
        height / 6,
        std::function<void(void)>([this](void) {
            if (core_entry_.getData().getNbPlayers() > 2) {
                core_entry_.getData().setNbPlayers(core_entry_.getData().getNbPlayers() - 1);
                core_entry_.getData().getPlayers().pop_back();
                toggle_auto_.pop_back();
                select_right_.pop_back();
                select_left_.pop_back();
            }
        }),
        "assets/fonts/menu.ttf",
        " Remove");

    buttons_.emplace_back("assets/textures/home/button.png",
        width / 4 + 900,
        height / 6,
        std::function<void(void)>([this](void) {
            if (this->core_entry_.getData().getNbPlayers() > 1)
                core_entry_.switchScene(bomberman::SceneType::GAME);
        }),
        "assets/fonts/menu.ttf",
        "Play");

    buttons_.emplace_back("assets/textures/selection/close.png",
        width / 4 + 1250,
        height / 6,
        std::function<void(void)>(
            [this](void) { core_entry_.switchScene(bomberman::SceneType::MENU); }),
        "assets/fonts/menu.ttf",
        "");
}

/**
 * It draws all the buttons
 */
void PlayerSelect::drawButtons() const noexcept
{
    for (auto& it : buttons_) { it.draw(); }
}

/**
 * If the gamepad is connected, then check if the dpad is pressed, and if so, change the button
 * index. If the B button is pressed, then call the action function of the button at the current
 * index. If the gamepad is not connected, then check if the mouse is hovering over any of the
 * buttons, and if so, call the action function of that button
 */
void PlayerSelect::action() noexcept
{
    for (auto& it : buttons_)
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
    for (auto& it : toggle_auto_) {
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
    }
    for (auto& it : select_left_) {
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
    }
    for (auto& it : select_right_) {
        if (it.checkCollision(core_entry_.getData().getMouseHandler())) { it.action(); }
    }
}

/**
 * It plays the music
 */
void PlayerSelect::playMusic() noexcept
{
    loop_music_.play();
}

/**
 * It updates the music
 */
void PlayerSelect::updateMusic() const noexcept
{
    loop_music_.update();
}

/**
 * `ColorManager PlayerSelect::getBackgroundColor() const noexcept`
 *
 * The function returns a `ColorManager` object. The function is a member of the `PlayerSelect`
 * class. The function is a `const` function. The function is a `noexcept` function
 *
 * @return The background color of the player select screen.
 */
ColorManager PlayerSelect::getBackgroundColor() const noexcept
{
    return (background_color_);
}

// ****************************************************************************
// *                               SYSTEMS                                    *
// ****************************************************************************

/**
 * It displays the background, the title, the players, the buttons, the stats and the FPS
 */
void PlayerSelect::SystemDisplay() noexcept
{
    background_.draw({ 255, 255, 255, 175 });
    title_.draw();

    // **************************** 3D **********************************

    core_entry_.getCameraman().begin3D();

    float nbPlayers = 0;
    for (auto& player : core_entry_.getData().getPlayers()) {
        auto render    = player->getComponent<Render>();
        auto transform = player->getComponent<Transform3D>();

        if (!render.has_value() || !transform.has_value()) continue;

        Vector3D position = { 0.2f, 0.6f, 4.5f - nbPlayers * 2 };
        Vector3D rotation = { 0, 1, 0 };

        render->get().getAnimation().setAnimationId(1);
        render->get().getAnimation().updateAnimation(render->get().getModel());
        render->get().displayModelV(transform->get(), position, rotation, 180.0f);
        nbPlayers++;
    }

    core_entry_.getCameraman().end3D();

    // **************************** 2D **********************************

    FpsHandler::draw(10, 10);
    choose_text_.draw();
    drawButtons();
    displayAllStats();
}