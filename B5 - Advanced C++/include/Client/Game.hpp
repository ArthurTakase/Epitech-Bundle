/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <ECS/Systems/MusicSystem.hpp>
#include <ECS/Systems/SoundSystem.hpp>
#include <Lib/Lib.hpp>
#include <Lib/SoundManager.hpp>
#include <Serializer/BitSize.hpp>
#include <Tools/Shortcuts.hpp>
#include <queue>
#include <mutex>

/**
 * @brief This class is used to create a game instance in the client.
 */
class Game
{
  public:
    Game(std::queue<GamePacket>& packets, std::mutex& mutex);
    ~Game() noexcept                 = default;
    Game(const Game& other) noexcept = delete;
    Game(Game&& other) noexcept      = delete;

    Game& operator=(const Game& rhs) noexcept = delete;
    Game& operator=(Game&& rhs) noexcept      = delete;

    void run() noexcept;
    Lib& getLib() noexcept;

    EntityManager& getManager() noexcept;

  private:
    std::vector<std::string_view> soundPaths_ = {
        EXPLOSION_PATH, HEAL_PATH, HURT_PATH, MENU_PATH, PIOU_PATH, POWERUP_PATH};

    EntityManager           manager_;
    Lib                     lib_;
    DrawableSystem          drawableSystem_;
    DestroyableSystem       destroyableSystem_;
    SoundSystem             soundSystem_;
    MusicSystem             musicSystem_;
    std::queue<GamePacket>& dataReceived_;
    std::mutex&             mutexForPacket_;
    SoundManager            soundManager_;

    void updateOrCreateEntity(GamePacket packet) noexcept;
    int  createSound(const std::string_view& path) noexcept;
};
