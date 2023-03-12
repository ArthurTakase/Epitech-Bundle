/*
** EPITECH PROJECT, 2022string
** YEP
** File description:
** Sprite.cpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <bitset>
#include <string>

/**
 * @brief This class is used to create and encapsulate a sprite.
 *
 */
class Sprite
{
  public:
    Sprite();
    Sprite(std::string path, int x, int y);
    Sprite(const Sprite& other) noexcept = default;
    Sprite(Sprite&& other) noexcept      = default;
    ~Sprite() noexcept                   = default;

    Sprite& operator=(const Sprite& rhs) noexcept = default;
    Sprite& operator=(Sprite&& rhs) noexcept      = default;

    void               setSpritePath(const std::string& path);
    const std::string& getSpritePath() const noexcept;
    void               setX(int x) noexcept;
    void               setY(int y) noexcept;
    int                getX() const noexcept;
    int                getY() const noexcept;
    void*              getSprite() noexcept;
    void*              getTexture() noexcept;
    void               setTextureRect(int xtexture, int ytexture, int width, int height) noexcept;
    void               updatePosition() noexcept;
    void               setScale(float x, float y) noexcept;

  private:
    std::string spritePath_;
    int         x_;
    int         y_;
    sf::Sprite  sprite_;
    sf::Texture texture_;
};
