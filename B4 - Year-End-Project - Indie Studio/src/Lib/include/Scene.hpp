/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Scene
*/

#pragma once

#include "Color.hpp"
#include "Mouse.hpp"
#include "Music.hpp"
#include "Vector.hpp"

class Scene
{
  public:
    Scene() noexcept                   = default;
    Scene(const Scene& other) noexcept = delete;
    Scene(Scene&& other) noexcept      = delete;
    virtual ~Scene() noexcept          = default;

    Scene& operator=(const Scene& rhs) noexcept = delete;
    Scene& operator=(Scene&& rhs) noexcept = delete;

    virtual void         action() noexcept                   = 0;
    virtual ColorManager getBackgroundColor() const noexcept = 0;
    // enlever la méthode getBackGroundColor de la scène
    //  methods for camera
    virtual void switchAction() noexcept = 0;

    // methods for musics
    virtual void playMusic() noexcept         = 0;
    virtual void updateMusic() const noexcept = 0;

    virtual void SystemDestroy() noexcept   = 0;
    virtual void SystemCollision() noexcept = 0;
    virtual void SystemDisplay() noexcept   = 0;
};
