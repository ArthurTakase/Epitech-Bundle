/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** HitboxComponent.cpp
*/

#include <ECS/Components/DrawableComponent.hpp>

/**
 * It's a constructor for the DrawableComponent class
 *
 * @param offsetX The x-coordinate of the top-left corner of the texture relative
 * to the top-left corner of the entity.
 * @param offsetY The y-coordinate of the top-left corner of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param textureId The id of the texture to use.
 */
DrawableComponent::DrawableComponent(int offsetX, int offsetY, int width, int height, int textureId)
    : offsetX_(offsetX)
    , offsetY_(offsetY)
    , width_(width)
    , height_(height)
    , textureId_(textureId)
    , scaleX_(1)
    , scaleY_(1)
{
}

/**
 * It initializes the DrawableComponent class with the given parameters
 *
 * @param offsetX The x-coordinate of the top-left corner of the sprite relative to
 * the top-left corner of the entity.
 * @param offsetY The y-coordinate of the top-left corner of the sprite.
 * @param width The width of the sprite in pixels.
 * @param height The height of the sprite in pixels.
 * @param textureId The id of the texture to use.
 * @param scaleX The scale of the sprite in the X direction.
 * @param scaleY The scale of the sprite in the Y direction.
 */
DrawableComponent::DrawableComponent(
    int offsetX, int offsetY, int width, int height, int textureId, float scaleX, float scaleY)
    : offsetX_(offsetX)
    , offsetY_(offsetY)
    , width_(width)
    , height_(height)
    , textureId_(textureId)
    , scaleX_(scaleX)
    , scaleY_(scaleY)
{
    sprite_.setScale(scaleX, scaleY);
}

/**
 * Copy constructor for DrawableComponent.
 *
 * @param other The other DrawableComponent to copy from.
 */
DrawableComponent::DrawableComponent(const DrawableComponent& other) noexcept
    : offsetX_(other.offsetX_)
    , offsetY_(other.offsetY_)
    , width_(other.width_)
    , height_(other.height_)
    , textureId_(other.textureId_)
    , sprite_(other.sprite_.getSpritePath(), other.sprite_.getX(), other.sprite_.getY())
    , scaleX_(other.scaleX_)
    , scaleY_(other.scaleY_)
{
}

/**
 * It returns the value of the private member variable _offsetX
 *
 * @return The offset of the x-coordinate of the drawable component.
 */
int DrawableComponent::getOffsetX() const noexcept
{
    return offsetX_;
}

/**
 * This function returns the y-offset of the drawable component.
 *
 * @return The offset of the y-axis.
 */
int DrawableComponent::getOffsetY() const noexcept
{
    return offsetY_;
}

/**
 * It returns the width of the drawable component
 *
 * @return The width of the DrawableComponent.
 */
int DrawableComponent::getWidth() const noexcept
{
    return width_;
}

/**
 * It returns the height of the drawable component
 *
 * @return The height of the DrawableComponent.
 */
int DrawableComponent::getHeight() const noexcept
{
    return height_;
}

/**
 * It returns the value of the private member variable _textureId
 *
 * @return The texture id of the drawable component.
 */
int DrawableComponent::getTextureId() const noexcept
{
    return textureId_;
}

/**
 * It sets the offset of the X coordinate of the DrawableComponent
 *
 * @param offsetX The x offset of the sprite.
 */
void DrawableComponent::setOffsetX(int offsetX) noexcept
{
    offsetX_ = offsetX;
}

/**
 * It sets the offsetY variable to the value passed in
 *
 * @param offsetY The y-offset of the sprite.
 */
void DrawableComponent::setOffsetY(int offsetY) noexcept
{
    offsetY_ = offsetY;
}

/**
 * This function sets the width of the drawable component
 *
 * @param width The width of the drawable component.
 */
void DrawableComponent::setWidth(int width) noexcept
{
    width_ = width;
}

/**
 * It sets the height of the drawable component
 *
 * @param height The height of the drawable component.
 */
void DrawableComponent::setHeight(int height) noexcept
{
    height_ = height;
}

/**
 * It sets the texture ID of the drawable component
 *
 * @param textureId The id of the texture to use.
 */
void DrawableComponent::setTextureId(int textureId) noexcept
{
    textureId_ = textureId;
}

/**
 * It returns the sprite of the drawable component
 *
 * @return The sprite of the drawable component.
 */
Sprite& DrawableComponent::getSprite() noexcept
{
    return sprite_;
}

/**
 * It sets the scale of the sprite
 *
 * @param x The x-coordinate of the position of the sprite.
 * @param y The y coordinate of the sprite.
 */
void DrawableComponent::setScale(float x, float y) noexcept
{
    scaleX_ = x;
    scaleY_ = y;
    sprite_.setScale(x, y);
}

/**
 * Returns the scale of the object in the X direction.
 *
 * @return The scaleX_ variable.
 */
float DrawableComponent::getScaleX() const noexcept
{
    return scaleX_;
}

/**
 * This function returns the scaleY_ member variable.
 *
 * @return The scaleY_ variable.
 */
float DrawableComponent::getScaleY() const noexcept
{
    return scaleY_;
}