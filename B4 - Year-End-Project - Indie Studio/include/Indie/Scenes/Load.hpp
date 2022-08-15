/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** PlayerSelect
*/

#pragma once
#include <vector>

#include "Button.hpp"
#include "Core.hpp"
#include "Scene.hpp"
#include "Text.hpp"

class Load : public Scene
{
  public:
    Load(Core& core_ref) noexcept;
    Load(const Load& other) noexcept = delete;
    Load(Load&& other) noexcept      = delete;
    ~Load() noexcept                 = default;

    Load& operator=(const Load& rhs) noexcept = delete;
    Load& operator=(Load&& rhs) noexcept = delete;

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
    void createIllustrations() noexcept;
    void createButtons() noexcept;
    void drawIllustrations() const noexcept;
    void drawButtons() const noexcept;
    void getSavesNames() noexcept;
    void initTexts() noexcept;

    // attributes
    MusicManager             loop_music_;
    Core&                    core_entry_;
    ColorManager             background_color_;
    Sprite                   background_;
    Sprite                   title_;
    TextHandler              title_text_;
    std::vector<Button>      buttons_       = {};
    std::vector<Button>      remove_        = {};
    std::vector<Sprite>      illustrations_ = {};
    std::vector<TextHandler> load_names_    = {};
    Controller               controller_;
    int                      button_index_ = 0;

    static const inline std::string BUTTON_PATH = "assets/textures/home/button.png";
    static const inline char*       BLACK_IMG   = "assets/textures/load/black_bomber.png";
    static const inline char*       WHITE_IMG   = "assets/textures/load/white_bomber.png";
    static const inline char*       RED_IMG     = "assets/textures/load/red_bomber.png";
    static const inline char*       MUSIC       = "assets/audios/Select.mp3";
    static const inline char*       BG_PATH     = "assets/textures/home/background.png";
    static const inline char*       TITLE_PATH  = "assets/textures/selection/title.png";
    static const inline std::string FONT_PATH   = "assets/fonts/menu.ttf";
    static const inline char*       SAVE_PATH   = "Save/";
};
