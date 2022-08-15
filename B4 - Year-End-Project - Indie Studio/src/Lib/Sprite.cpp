/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Sprite
*/

#include "Sprite.hpp"

/**
 * It loads an image from a file, creates a texture from the image, and sets the position and scale
 * to default values
 *
 * @param path The path to the image file.
 */
Sprite::Sprite(const std::string_view& path) noexcept
    : image_(LoadImage(path.data()))
    , texture_(LoadTextureFromImage(image_))
    , pos_x_(0)
    , pos_y_(0)
    , scale_(1.0f)
{
}

/**
 * It loads an image from a file, creates a texture from the image, and stores the texture in a
 * member variable
 *
 * @param path The path to the image file.
 * @param x The x position of the sprite.
 * @param y The y coordinate of the sprite.
 */
Sprite::Sprite(const std::string_view& path, float x, float y) noexcept
    : image_(LoadImage(path.data()))
    , texture_(LoadTextureFromImage(image_))
    , pos_x_(x)
    , pos_y_(y)
    , scale_(1.0f)
{
}

/**
 * It loads an image from a file, creates a texture from the image, and stores the texture, the
 * image, and the position and scale of the sprite
 *
 * @param path The path to the image file.
 * @param x The x position of the sprite.
 * @param y The y position of the sprite.
 * @param scale The scale of the sprite.
 */
Sprite::Sprite(const std::string_view& path, float x, float y, float scale) noexcept
    : image_(LoadImage(path.data()))
    , texture_(LoadTextureFromImage(image_))
    , pos_x_(x)
    , pos_y_(y)
    , scale_(scale)
{
}

/**
 * It loads an image from a file, creates a texture from that image, and stores the texture, the
 * image, the position, the scale, and whether or not the sprite is displayed
 *
 * @param path The path to the image file.
 * @param x The x position of the sprite.
 * @param y The y position of the sprite.
 * @param scale The scale of the sprite.
 * @param display If true, the sprite will be displayed on the screen.
 */
Sprite::Sprite(const std::string_view& path, float x, float y, float scale, bool display) noexcept
    : image_(LoadImage(path.data()))
    , texture_(LoadTextureFromImage(image_))
    , pos_x_(x)
    , pos_y_(y)
    , scale_(scale)
    , displayed_(display)
{
}

/**
 * "Move the other sprite into this sprite, and mark the other sprite as unloaded."
 *
 * The first thing we do is move the image and texture from the other sprite into this sprite. This
 * is done using the move assignment operator, which is a member function of the image and texture
 * classes
 *
 * @param other The other sprite to move from.
 */
Sprite::Sprite(Sprite&& other) noexcept
    : image_(std::move(other.image_))
    , texture_(std::move(other.texture_))
    , pos_x_(other.pos_x_)
    , pos_y_(other.pos_y_)
    , scale_(other.scale_)
    , displayed_(other.displayed_)
    , unloaded_(other.unloaded_)
{
    other.unloaded_ = true;
}

/**
 * "Move the data from the right hand side to the left hand side, and set the right hand side to
 * unloaded."
 *
 * The first thing we do is move the data from the right hand side to the left hand side. This is
 * done by using the `std::move` function. This function takes an object and returns a reference to
 * that object. The reference is an rvalue reference, which means that it can only be used on the
 * right hand side of an assignment. This is important because it means that the object can be moved
 * from
 *
 * @return A reference to the object that was assigned to.
 */
Sprite& Sprite::operator=(Sprite&& rhs) noexcept
{
    image_        = std::move(rhs.image_);
    texture_      = std::move(rhs.texture_);
    pos_x_        = rhs.pos_x_;
    pos_y_        = rhs.pos_y_;
    scale_        = rhs.scale_;
    displayed_    = rhs.displayed_;
    unloaded_     = rhs.unloaded_;
    rhs.unloaded_ = true;
    return *(this);
}

/**
 * The destructor unloads the sprite.
 */
Sprite::~Sprite() noexcept
{
    this->unload();
}

/**
 * If the sprite is not unloaded, unload the image and texture, and set the unloaded flag to true.
 */
void Sprite::unload() noexcept
{
    if (!unloaded_) {
        UnloadImage(image_);
        UnloadTexture(texture_);
        unloaded_ = true;
    }
}

/**
 * Sets the position of the sprite.
 *
 * @param x The x position of the sprite.
 * @param y The y coordinate of the sprite.
 */
void Sprite::setPos(float x, float y) noexcept
{
    pos_x_ = x;
    pos_y_ = y;
}

/**
 * This function returns the value of the private member variable pos_x_.
 *
 * @return The value of the private member variable pos_x_.
 */
int Sprite::getPosX() const noexcept
{
    return pos_x_;
}

/**
 * This function returns the y position of the sprite.
 *
 * @return The value of the private member variable pos_y_.
 */
int Sprite::getPosY() const noexcept
{
    return pos_y_;
}

/**
 * If the sprite is displayed, draw it
 */
void Sprite::draw() const noexcept
{
    if (displayed_) { DrawTextureEx(texture_, { pos_x_, pos_y_ }, 0.0f, scale_, WHITE); }
}

/**
 * It draws the sprite to the screen
 *
 * @param color The color to draw the sprite with.
 */
void Sprite::draw(const std::array<unsigned char, 3>& color) const noexcept
{
    Color col = { color[0], color[1], color[2], 255 };

    if (displayed_) { DrawTextureEx(texture_, { pos_x_, pos_y_ }, 0.0f, scale_, col); }
}

/**
 * It draws the sprite to the screen
 *
 * @param color The color to draw the sprite with.
 */
void Sprite::draw(const std::array<unsigned char, 4>& color) const noexcept
{
    Color col = { color[0], color[1], color[2], color[3] };

    if (displayed_) { DrawTextureEx(texture_, { pos_x_, pos_y_ }, 0.0f, scale_, col); }
}

/**
 * Sets the scale of the sprite.
 *
 * @param scale The scale of the sprite.
 */
void Sprite::setScale(float scale) noexcept
{
    scale_ = scale;
}

/**
 * It returns the width of the sprite.
 *
 * @return The width of the texture.
 */
float Sprite::getWidth() const noexcept
{
    return (texture_.width);
}

/**
 * It returns the height of the sprite
 *
 * @return The height of the texture.
 */
float Sprite::getHeight() const noexcept
{
    return (texture_.height);
}

/**
 * `setDisplay` sets the `displayed_` member variable to the value of the `value` parameter
 *
 * @param value The new value for the displayed_ variable.
 */
void Sprite::setDisplay(bool value) noexcept
{
    displayed_ = value;
}

/**
 * It inverts the value of the displayed_ member variable
 */
void Sprite::invertDisplay() noexcept
{
    displayed_ = !displayed_;
}

/**
 * `bool Sprite::getDisplay() const noexcept`
 *
 * This function returns a boolean value. It is a member function of the class Sprite. It is a const
 * function, meaning it does not modify the object. It is a noexcept function, meaning it does not
 * throw exceptions
 *
 * @return The value of the displayed_ variable.
 */
bool Sprite::getDisplay() const noexcept
{
    return (displayed_);
}