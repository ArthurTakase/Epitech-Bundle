/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sprite.cpp
*/

#include <Error/Error.hpp>
#include <Lib/Sprite.hpp>

/**
 * This is the default constructor for the Sprite class.
 */
Sprite::Sprite()
    : spritePath_("")
    , x_(0)
    , y_(0)
{
}

/**
 * Sprite is a class that takes a string, an int, and an int and sets the spritePath, x, and y
 * variables to the values of the string, int, and int.
 *
 * @param path The path to the image file.
 * @param x The x coordinate of the sprite.
 * @param y The y coordinate of the sprite.
 */
Sprite::Sprite(std::string path, int x, int y)
    : spritePath_(path)
    , x_(x)
    , y_(y)
{
    if (path == "") { return; }

    if (!texture_.loadFromFile(spritePath_)) { throw Error("Error: Could not load sprite from file: " + spritePath_); }
    sprite_.setTexture(texture_);
    sprite_.setPosition({static_cast<float>(x_), static_cast<float>(y_)});
}

/**
 * This function sets the sprite path to the path passed in.
 *
 * @param path The path to the sprite sheet.
 */
void Sprite::setSpritePath(const std::string& path)
{
    spritePath_ = path;

    if (!texture_.loadFromFile(spritePath_)) { throw Error("Error: Could not load sprite from file: " + spritePath_); }
    sprite_.setTexture(texture_);
}

/**
 * Returns the path to the sprite's image file.
 *
 * @return The spritePath variable is being returned.
 */
const std::string& Sprite::getSpritePath() const noexcept
{
    return spritePath_;
}

/**
 * This function sets the x coordinate of the sprite.
 *
 * @param x The x coordinate of the sprite.
 */
void Sprite::setX(int x) noexcept
{
    x_ = x;
    sprite_.setPosition({static_cast<float>(x_), static_cast<float>(y_)});
}

/**
 * This function sets the y coordinate of the sprite.
 *
 * @param y The y coordinate of the sprite.
 */
void Sprite::setY(int y) noexcept
{
    y_ = y;
    sprite_.setPosition({static_cast<float>(x_), static_cast<float>(y_)});
}

/**
 * This function returns the x coordinate of the sprite.
 *
 * @return The x coordinate of the sprite.
 */
int Sprite::getX() const noexcept
{
    return x_;
}

/**
 * This function returns the y coordinate of the sprite.
 *
 * @return The y coordinate of the sprite.
 */
int Sprite::getY() const noexcept
{
    return y_;
}

/**
 * This function returns the sprite.
 *
 * @return The sprite.
 */
void* Sprite::getSprite() noexcept
{
    return static_cast<void*>(&sprite_);
}

/**
 * This function returns the texture.
 *
 * @return The texture.
 */
void* Sprite::getTexture() noexcept
{
    return static_cast<void*>(&texture_);
}

/**
 * This function sets the texture rectangle of the sprite.
 *
 * @param xtexture The x coordinate of the texture.
 * @param ytexture The y coordinate of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 */
void Sprite::setTextureRect(int xtexture, int ytexture, int width, int height) noexcept
{
    sf::Rect<int> rect({xtexture, ytexture}, {width, height});

    sprite_.setTextureRect(rect);
}

/**
 * This function updates the position of the sprite.
 */
void Sprite::updatePosition() noexcept
{
    sprite_.setPosition({static_cast<float>(x_), static_cast<float>(y_)});
}

/**
 * Sets the scale of the sprite
 *
 * @param x The x-scale of the sprite.
 * @param y The y coordinate of the sprite.
 */
void Sprite::setScale(float x, float y) noexcept
{
    sprite_.setScale({x, y});
}