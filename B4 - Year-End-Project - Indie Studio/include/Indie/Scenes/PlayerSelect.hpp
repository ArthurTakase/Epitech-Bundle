/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PlayerSelect
*/

#pragma once

#include <string>

#include "Button.hpp"
#include "Controller.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "Fps.hpp"
#include "GameData.hpp"
#include "Mouse.hpp"
#include "Player.hpp"
#include "Scene.hpp"
#include "Text.hpp"

class PlayerSelect : public Scene
{
  public:
    PlayerSelect(Core& core_ref) noexcept;
    PlayerSelect(const PlayerSelect& other) noexcept = delete;
    PlayerSelect(PlayerSelect&& other) noexcept      = delete;
    ~PlayerSelect() noexcept                         = default;

    PlayerSelect& operator=(const PlayerSelect& rhs) noexcept = delete;
    PlayerSelect& operator=(PlayerSelect&& rhs) noexcept = delete;

    // main methods
    void action() noexcept final;
    void switchAction() noexcept final;

    // music methods
    void playMusic() noexcept final;
    void updateMusic() const noexcept final;

    // background methods
    ColorManager getBackgroundColor() const noexcept final;

    void SystemDestroy() noexcept final{};
    void SystemCollision() noexcept final{};
    void SystemDisplay() noexcept final;

  private:
    // methods
    void createButtons() noexcept;
    void drawButtons() const noexcept;
    void displayPlayerStats(
        const Vector2& stats_pos, const Vector2& texts_pos, unsigned int id) noexcept;
    void         displayAllStats() noexcept;
    unsigned int findStatsId(const PlayerType& type) const noexcept;
    void drawSelection(const int id, const Vector2& pos_left, const Vector2& pos_right) noexcept;
    void drawToggle(const int id, const Vector2& position, bool isBot) noexcept;

    // attributes
    MusicManager             loop_music_;
    Core&                    core_entry_;
    ColorManager             background_color_;
    Sprite                   background_;
    Sprite                   title_;
    TextHandler              choose_text_;
    std::vector<Button>      buttons_      = {};
    std::vector<Button>      select_left_  = {};
    std::vector<Button>      select_right_ = {};
    std::vector<Button>      toggle_auto_  = {};
    std::vector<Sprite>      stats_        = {};
    std::vector<TextHandler> texts_        = {};
    Controller               controller;

    static const inline char*       MUSIC      = "assets/audios/Select.mp3";
    static const inline char*       BG_PATH    = "assets/textures/home/background.png";
    static const inline char*       TITLE_PATH = "assets/textures/selection/title.png";
    static const inline std::string SELECT     = "assets/fonts/menu.ttf";
};
