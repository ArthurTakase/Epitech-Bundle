/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DrawableComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <ECS/Entity/Entity.hpp>
#include <Lib/Sprite.hpp>
#include <Lib/Timer.hpp>
#include <functional>
#include <memory>

/**
 * @brief Component assigned to drawable entities.
 */
class DrawableComponent : public IComponent
{
  public:
    DrawableComponent() noexcept = default;
    DrawableComponent(int offsetX, int offsetY, int width, int height, int textureId);
    DrawableComponent(int offsetX, int offsetY, int width, int height, int textureId, float scaleX, float scaleY);
    DrawableComponent(const DrawableComponent& other) noexcept;
    DrawableComponent(DrawableComponent&& other) noexcept = default;
    ~DrawableComponent() noexcept                         = default;

    DrawableComponent& operator=(const DrawableComponent& rhs) noexcept = default;
    DrawableComponent& operator=(DrawableComponent&& rhs) noexcept      = default;

    int     getOffsetX() const noexcept;
    int     getOffsetY() const noexcept;
    int     getWidth() const noexcept;
    int     getHeight() const noexcept;
    int     getTextureId() const noexcept;
    void    setOffsetX(int offsetX) noexcept;
    void    setOffsetY(int offsetY) noexcept;
    void    setWidth(int width) noexcept;
    void    setHeight(int height) noexcept;
    void    setScale(float x, float y) noexcept;
    float   getScaleX() const noexcept;
    float   getScaleY() const noexcept;
    void    setTextureId(int textureId) noexcept;
    Sprite& getSprite() noexcept;

  private:
    int    offsetX_;
    int    offsetY_;
    int    width_;
    int    height_;
    int    textureId_;
    float  scaleX_;
    float  scaleY_;
    Sprite sprite_;
};