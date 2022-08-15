/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** ACore
*/

#pragma once
#include "GameData.hpp"
#include "Scene.hpp"

class ACore
{
  public:
    ACore() noexcept                   = default;
    ACore(const ACore& other) noexcept = delete;
    ACore(ACore&& other) noexcept      = delete;
    virtual ~ACore() noexcept          = default;

    ACore& operator=(const ACore& rhs) noexcept = delete;
    ACore& operator=(ACore&& rhs) noexcept = delete;

    virtual void    run() noexcept = 0;
    void            setExit(bool value) noexcept;
    GameData&       getData() noexcept;
    const GameData& getData() const noexcept;

  protected:
    bool                                exit_ = false;
    GameData                            data_;
    std::vector<std::unique_ptr<Scene>> scenes;

    virtual void checkCamera() noexcept  = 0;
    virtual void displayScene() noexcept = 0;
    virtual void initScenes() noexcept   = 0;
    Scene&       findScene() noexcept;

  private:
};