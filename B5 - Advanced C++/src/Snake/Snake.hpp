/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** SnakeGame.cpp
*/

#pragma once

#include <ECS/Entity/EntityManager.hpp>
#include <ECS/Systems/BehaviorSystem.hpp>
#include <ECS/Systems/DestroyableSystem.hpp>
#include <ECS/Systems/DrawableSystem.hpp>
#include <ECS/Systems/HitboxSystem.hpp>
#include <ECS/Systems/MouvementSystem.hpp>
#include <Lib/Lib.hpp>
#include <vector>

/**
 * The class used to handle the snake game, its entities and systems.
 */
class SnakeGame
{
  public:
    SnakeGame();
    ~SnakeGame() noexcept                      = default;
    SnakeGame(const SnakeGame& other) noexcept = delete;
    SnakeGame(SnakeGame&& other) noexcept      = delete;

    SnakeGame& operator=(const SnakeGame& rhs) noexcept = delete;
    SnakeGame& operator=(SnakeGame&& rhs) noexcept      = delete;

    int  run() noexcept;
    int  fruit() noexcept;
    int  player() noexcept;
    int  wall(int x, int y) noexcept;
    void stop() noexcept;
    int  score(int size, int posX, int posY) noexcept;

  private:
    EntityManager     entityManager_;
    DrawableSystem    drawableSystem_;
    BehaviorSystem    behaviorSystem_;
    HitboxSystem      hitboxSystem_;
    MouvementSystem   mouvementSystem_;
    DestroyableSystem destroyableSystem_;
    Lib               lib_;
    bool              running_ = true;
    int               score_   = 0;
    int               scoreId_;
};