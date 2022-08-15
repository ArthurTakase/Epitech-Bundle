/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Text
*/

#include "Text.hpp"

/**
 * It loads the font, sets the message, and sets the color
 *
 * @param font_path The path to the font file.
 * @param message The text to be displayed.
 * @param posX The x position of the text.
 * @param posY The Y position of the text.
 */
TextHandler::TextHandler(
    const std::string_view& font_path, const std::string_view& message, int posX, int posY) noexcept
    : font_(LoadFontEx(font_path.data(), font_size_, 0, 250))
    , message_(message.data())
    , color_(Colors::C_WHITE)
{
    setPosition(posX, posY);
}

/**
 * "Move the other object's data into this object, and mark the other object as unloaded."
 *
 * The first thing we do is move the font_ object into this object. This is done by calling the move
 * constructor of the font_ object
 *
 * @param other The TextHandler object that we're moving from.
 */
TextHandler::TextHandler(TextHandler&& other) noexcept
    : font_(std::move(other.font_))
    , message_(other.message_)
    , position_(other.position_)
    , color_(other.color_)
{
    other.unloaded_ = true;
}

/**
 * "Move the data from the right hand side to the left hand side, and then set the right hand side
 * to an unloaded state."
 *
 * The first thing we do is move the font_ data member from the right hand side to the left hand
 * side. This is done by calling the move constructor of the std::unique_ptr class
 *
 * @return A reference to the object that was assigned to.
 */
TextHandler& TextHandler::operator=(TextHandler&& rhs) noexcept
{
    font_         = std::move(rhs.font_);
    message_      = rhs.message_;
    position_     = rhs.position_;
    color_        = rhs.color_;
    rhs.unloaded_ = true;
    return *(this);
}

/**
 * It deletes the `TextHandler` object
 */
TextHandler::~TextHandler() noexcept
{
    this->unload();
}

/**
 * It unloads the font
 */
void TextHandler::unload() noexcept
{
    if (!unloaded_) {
        UnloadFont(font_);
        unloaded_ = true;
    }
}

/**
 * It draws the text to the screen
 *
 * @return A reference to the TextHandler object.
 */
void TextHandler::draw() const noexcept
{
    auto  color = color_.getColor();
    Color col   = { color[0], color[1], color[2], 255 };

    if (!displayed_) { return; }
    DrawTextEx(font_, message_.c_str(), { position_.x, position_.y }, font_size_, 0, col);
}

/**
 * It inverts the value of the displayed_ member variable
 */
void TextHandler::invertDisplay() noexcept
{
    displayed_ = !displayed_;
}

/**
 * It sets the color of the text
 *
 * @param color The color of the text.
 */
void TextHandler::setTextColor(const std::array<unsigned char, 3>& color) noexcept
{
    color_.setColor(color);
}

/**
 * It sets the font size of the text
 *
 * @param size The size of the font.
 */
void TextHandler::setTextSize(int size) noexcept
{
    font_size_ = size;
}

/**
 * It sets the position of the text
 *
 * @param posX The x position of the text.
 * @param posY The y-coordinate of the text.
 */
void TextHandler::setPosition(int posX, int posY) noexcept
{
    position_.x = posX;
    position_.y = posY;
}

/**
 * It sets the message to be displayed
 *
 * @param message The message to be displayed.
 */
void TextHandler::setText(const std::string_view& message) noexcept
{
    message_ = message;
}

/**
 * It returns a reference to the message_ string
 *
 * @return A reference to the message_ string.
 */
std::string& TextHandler::getText() noexcept
{
    return message_;
}
