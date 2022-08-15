/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Home
*/

#pragma once

#include <vector>

#include "Button.hpp"
#include "Controller.hpp"
#include "Core.hpp"
#include "Fps.hpp"
#include "Scene.hpp"

class Home : public Scene
{
  public:
    Home(Core& core_ref) noexcept;
    Home(const Home& other) noexcept = delete;
    Home(Home&& other) noexcept      = delete;
    Home& operator=(const Home& rhs) noexcept = delete;
    Home& operator=(Home&& rhs) noexcept = delete;
    ~Home() noexcept                     = default;

    void action() noexcept final;
    void SystemDisplay() noexcept final;
    void SystemDestroy() noexcept final{};
    void SystemCollision() noexcept final{};

  protected:
    void         playMusic() noexcept final;
    void         updateMusic() const noexcept final;
    ColorManager getBackgroundColor() const noexcept final;
    void         switchAction() noexcept final;

  private:
    // methods
    void drawButtons() const noexcept;
    void createButtons() noexcept;
    void createTexts() noexcept;

    // attributes
    MusicManager             loop_music_;
    std::vector<Button>      buttons_ = {};
    Core&                    core_entry_;
    ColorManager             background_color_;
    Sprite                   background_;
    Sprite                   title_;
    Controller               controller;
    std::vector<Button>      settings_;
    std::vector<TextHandler> settings_texts_;

    static const inline char* MENU_MUSIC = "assets/audios/MainMenu.mp3";
    static const inline char* BG_PATH    = "assets/textures/home/background.png";
    static const inline char* TITLE_PATH = "assets/textures/home/title.png";
    static const inline char* FONT_PATH  = "assets/fonts/menu.ttf";
};
