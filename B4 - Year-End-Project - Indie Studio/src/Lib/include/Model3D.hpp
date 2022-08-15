/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Model3D
*/

#pragma once

#include <array>
#include <string_view>

#include "Vector.hpp"
#include "raylib.h"

class Model3D
{
  public:
    Model3D(const std::string_view& path, const std::string_view& texturePath) noexcept;
    Model3D(const Model3D& other) noexcept = delete;
    Model3D(Model3D&& other) noexcept      = delete;
    Model3D& operator=(const Model3D& rhs) noexcept = delete;
    Model3D& operator=(Model3D&& rhs) noexcept = delete;
    ~Model3D() noexcept;

    void draw(const Vector3D&               position,
        float                               scale,
        const std::array<unsigned char, 3>& color) const noexcept;
    void draw(const Vector3D&               position,
        const Vector3D&                     rotation,
        float                               rotation_angle,
        float                               scale,
        const std::array<unsigned char, 3>& color) const noexcept;
    void update(ModelAnimation animation, int frame_counter);

  private:
    Model     model_;
    Texture2D texture_;
    bool      unloaded_ = false;

    // methods
    void unload() noexcept;
};
