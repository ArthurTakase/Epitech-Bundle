/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Game
*/

#pragma once

#include <math.h>

#include <memory>
#include <vector>

#include "Bomberman.hpp"
#include "Button.hpp"
#include "Controller.hpp"
#include "Core.hpp"
#include "Entity.hpp"
#include "Fps.hpp"
#include "Model3D.hpp"
#include "Scene.hpp"
#include "Sound.hpp"
#include "Timer.hpp"

enum class Direction { UP, RIGHT, DOWN, LEFT };

class Game : public Scene
{
  public:
    Game(Core& core_ref) noexcept;
    Game(const Game& other) noexcept = delete;
    Game(Game&& other) noexcept      = delete;
    ~Game() noexcept                 = default;

    Game& operator=(const Game& rhs) noexcept = delete;
    Game& operator=(Game&& rhs) noexcept = delete;

    void         action() noexcept final;
    void         playMusic() noexcept final;
    void         updateMusic() const noexcept final;
    ColorManager getBackgroundColor() const noexcept final;
    void         switchAction() noexcept final;
    void         SystemDestroy() noexcept final;
    void         SystemCollision() noexcept final;
    void         SystemDisplay() noexcept final;

  private:
    // methods
    void createMap() noexcept;
    void hurryUp() noexcept;
    void endGame() noexcept;
    void endGameAction() noexcept;
    void endGameDisplay() noexcept;
    void createButtons() noexcept;
    void pauseAction() noexcept;

    // attributes
    float         time_party_ = 120;
    Core&         core_entry_;
    Timer         chrono_;
    unsigned char opacity_save_ = 0;
    Timer         timer_save;

    float lastTimeBlockPlace;
    bool  isHurry;
    int   nbBlockPlaced;
    int   x;
    int   z;
    int   maxX;
    int   maxZ;
    int   minX;
    int   minZ;

    Direction                direction;
    SoundManager             startSound_;
    SoundManager             hurryUpSound_;
    MusicManager             loop_music_;
    MusicManager             hurry_music_;
    MusicManager             victory_music_;
    Vector3D                 camera_position_ = { 0.0f, 14.5f, 2.0f };
    Vector3D                 camera_target_   = { 0.0f, 0.0f, 1.0f };
    Vector3D                 camera_up_       = { 0.0f, 2.0f, 0.0f };
    float                    HurryUpX;
    ColorManager             background_color_;
    std::vector<Button>      buttons_      = {};
    std::vector<Button>      pause_btn_    = {};
    int                      button_index_ = 0;
    Controller               controller;
    TextHandler              victoryText_;
    TextHandler              hurryUpText_;
    TextHandler              timeText_;
    TextHandler              pauseText_;
    std::vector<TextHandler> playerText_ = {};

    bool end_game;
    bool pause;

    static const inline char* GAME_MUSIC    = "assets/audios/Battle.mp3";
    static const inline char* HURRY_MUSIC   = "assets/audios/BattleHurryUp.mp3";
    static const inline char* VICTORY_MUSIC = "assets/audios/Victory.mp3";
    static const inline char* START         = "assets/audios/Start.wav";
    static const inline char* HURRY_UP      = "assets/audios/HurryUp.wav";
};
