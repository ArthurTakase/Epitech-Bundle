/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <ECS/Systems/MouvementSystem.hpp>
#include <ECS/Systems/MusicSystem.hpp>
#include <ECS/Systems/SoundSystem.hpp>
#include <Lib/Lib.hpp>
#include <Lib/SoundManager.hpp>
#include <NetworkLib/ISocket.hpp>
#include <Tools/Shortcuts.hpp>

/**
 * @brief This class is used to create a menu instance in the client.
 */
class Menu
{
  public:
    Menu();
    Menu(const Menu& other) noexcept = delete;
    Menu(Menu&& other) noexcept      = delete;
    ~Menu() noexcept                 = default;

    Menu& operator=(const Menu& rhs) noexcept = delete;
    Menu& operator=(Menu&& rhs) noexcept      = delete;

    Address run(Window& window);
    bool    getIsOpen() const noexcept;

  private:
    static constexpr unsigned int     MAX_INDEX       = 2;
    static constexpr unsigned int     MAX_VALUE       = 255;
    static constexpr int              MIN_VALUE       = -255;
    static constexpr std::string_view TITLE_PATH      = SPRITE("7");
    static constexpr std::string_view FONT_PATH       = FONT("gameboy.ttf");
    static constexpr std::string_view BACKGROUND_PATH = SPRITE("0");

  private:
    std::string ip_     = "";
    std::string port_   = "";
    bool        isOpen_ = true;

    std::vector<std::string_view> soundPaths_ = {
        EXPLOSION_PATH, HEAL_PATH, HURT_PATH, MENU_PATH, PIOU_PATH, POWERUP_PATH};

    EntityManager     manager_;
    DrawableSystem    drawableSystem_;
    DestroyableSystem destroyableSystem_;
    BehaviorSystem    behaviorSystem_;
    MouvementSystem   mouvementSystem_;
    MusicSystem       musicSystem_;
    SoundSystem       soundSystem_;

    SoundManager soundManager_;
    int          menuSound;
    int          hurtSound;

    // methods
    void createMusic(const std::string_view& path) noexcept;
    int  createText(int x, int y, int size, const std::string_view& txt) noexcept;
    int  createIPMenu(Window& window) noexcept;
    int  createTitleMenu(Window& window) noexcept;
    int  createBackground(int x) noexcept;
    int  createSound(const std::string_view& path) noexcept;
    void playSound(int id) noexcept;
};
