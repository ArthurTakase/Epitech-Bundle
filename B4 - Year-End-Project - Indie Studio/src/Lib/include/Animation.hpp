/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Animation.cpp
*/

#pragma once

#include "Model3D.hpp"
#include "raylib.h"

class Animation
{
  public:
    Animation() noexcept = default;
    ~Animation() noexcept;
    Animation(const Animation& other) noexcept = default;
    Animation(Animation&& other) noexcept      = default;

    Animation& operator=(const Animation& rhs) noexcept = default;
    Animation& operator=(Animation&& rhs) noexcept = default;

    void addAnimation(const std::string_view& path) noexcept;
    void updateAnimation(Model3D& model_) noexcept;
    void setSkipFrame(int frame) noexcept;
    void setAnimationId(int id) noexcept;

  private:
    ModelAnimation* animations_       = nullptr;
    unsigned int    frame_counter_    = 0;
    unsigned int    animations_count_ = 0;
    unsigned int    skip_frame_       = 1;
    unsigned int    animation_id_     = 0;
    bool            is_animated_      = false;
    float           time_             = 0;
};