/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Button
*/

#include "Button.hpp"

/**
 * It creates a button with a texture, a position, a function to execute when clicked, a font, a
 * message, and a text position
 *
 * @param texture_path The path to the texture of the button.
 * @param pos_x The x position of the button
 * @param pos_y The y position of the button
 * @param function The function that will be called when the button is clicked.
 * @param font_path The path to the font file.
 * @param message The text that will be displayed on the button.
 * @param textPosX The X position of the text relative to the button.
 * @param textPosY The Y position of the text.
 */
Button::Button(const std::string& texture_path,
    float                         pos_x,
    float                         pos_y,
    std::function<void(void)>     function,
    const std::string&            font_path,
    const std::string&            message,
    int                           textPosX,
    int                           textPosY) noexcept
    : fx_clicked_(ON_CLICK)
    , fx_hover_(ON_HOVER)
    , texture_(texture_path)
    , task_(function)
    , text_(font_path, message, 0, 0)
    , color_(Colors::C_WHITE)
    , rectangle_(pos_x,
          pos_y,
          static_cast<float>(texture_.getWidth()),
          static_cast<float>(texture_.getHeight()))
{
    texture_.setPos(rectangle_.getX(), rectangle_.getY());
    text_.setPosition(
        (pos_x + 150 - (message.size() * 35) / 2) + textPosX, (pos_y + 45) + textPosY);
}

Button::Button(const std::string& texture_path,
    float                         pos_x,
    float                         pos_y,
    std::function<void(void)>     function,
    const std::string&            font_path,
    const std::string&            message,
    int                           textPosX,
    int                           textPosY,
    bool                          sound) noexcept
    : fx_clicked_(ON_CLICK)
    , fx_hover_(ON_HOVER)
    , texture_(texture_path)
    , task_(function)
    , text_(font_path, message, 0, 0)
    , color_(Colors::C_WHITE)
    , rectangle_(pos_x,
          pos_y,
          static_cast<float>(texture_.getWidth()),
          static_cast<float>(texture_.getHeight()))
    , sound(sound)
{
    texture_.setPos(rectangle_.getX(), rectangle_.getY());
    text_.setPosition(
        (pos_x + 150 - (message.size() * 35) / 2) + textPosX, (pos_y + 45) + textPosY);
}

/**
 * It initializes the button's
 * texture, sound effects, task, text, color, and rectangle
 *
 * @param texture_path The path to the texture of the button.
 * @param pos_x The x position of the button.
 * @param pos_y The y position of the button.
 * @param function The function that will be called when the button is clicked.
 * @param font_path The path to the font file.
 * @param message The text that will be displayed on the button.
 */
Button::Button(const std::string& texture_path,
    float                         pos_x,
    float                         pos_y,
    std::function<void(void)>     function,
    const std::string&            font_path,
    const std::string&            message) noexcept
    : fx_clicked_(ON_CLICK)
    , fx_hover_(ON_HOVER)
    , texture_(texture_path)
    , task_(function)
    , text_(font_path, message, 0, 0)
    , color_(Colors::C_WHITE)
    , rectangle_(pos_x,
          pos_y,
          static_cast<float>(texture_.getWidth()),
          static_cast<float>(texture_.getHeight()))
{
    texture_.setPos(rectangle_.getX(), rectangle_.getY());
    text_.setPosition(pos_x + 150 - (message.size() * 30) / 2, pos_y + 45);
}

/**
 * It creates a button with a texture, a position, a function to execute when clicked, a font, a
 * message, and a scale
 *
 * @param texture_path The path to the texture of the button.
 * @param pos_x The x position of the button
 * @param pos_y The y position of the button.
 * @param function The function that will be called when the button is clicked.
 * @param font_path The path to the font file.
 * @param message The text that will be displayed on the button.
 * @param scale The scale of the button.
 */
Button::Button(const std::string& texture_path,
    float                         pos_x,
    float                         pos_y,
    std::function<void(void)>     function,
    const std::string&            font_path,
    const std::string&            message,
    float                         scale) noexcept
    : fx_clicked_(ON_CLICK)
    , fx_hover_(ON_HOVER)
    , texture_(texture_path)
    , task_(function)
    , scale_(scale)
    , text_(font_path, message, 0, 0)
    , color_(Colors::C_WHITE)
    , rectangle_(pos_x,
          pos_y,
          static_cast<float>(texture_.getWidth()),
          static_cast<float>(texture_.getHeight()))
{
    texture_.setPos(rectangle_.getX(), rectangle_.getY());
    text_.setPosition((pos_x + 150 - (message.size() * 30) / 2), (pos_y + 45));
    texture_.setScale(scale);
    rectangle_.setWidth(texture_.getWidth() * scale);
    rectangle_.setHeight(texture_.getHeight() * scale);
}

/**
 * It draws the button's texture and text
 */
void Button::draw() const noexcept
{
    texture_.draw(color_.getColor());
    text_.draw();
}

/**
 * If the mouse is colliding with the button, then change the color of the button to pink, play the
 * hover sound effect, and if the mouse is clicked, then change the color of the button to white,
 * play the clicked sound effect, and return true
 *
 * @param mouse_ The mouse handler object.
 *
 * @return A boolean value.
 */
bool Button::checkCollision(const MouseHandler& mouse_) noexcept
{
    if (mouse_.isColliding(rectangle_)) {
        if (mouse_.isClicking()) { state_ = 2; };
        if (state_ == 0) {
            state_ = 1;
            color_.setColor(Colors::C_PINK);
            if (sound) fx_hover_.play();
        }
        if (mouse_.isClicked()) { is_action_ = true; }
    } else {
        color_.setColor(Colors::C_WHITE);
        state_ = 0;
    }
    if (is_action_) {
        color_.setColor(Colors::C_WHITE);
        if (sound) fx_clicked_.play();
        is_action_ = false;
        return (true);
    }
    return (false);
}

/**
 * The function action() calls the function task_().
 */
void Button::action() const noexcept
{
    task_();
}

/**
 * It sets the state of the button and changes the color of the button based on the state
 *
 * @param state 0 = normal, 1 = hover, 2 = pressed
 */
void Button::setState(int state) noexcept
{
    state_ = state;

    if (state_ == 0) {
        color_.setColor(Colors::C_WHITE);
    } else if (state_ == 1) {
        color_.setColor(Colors::C_PINK);
    } else if (state_ == 2) {
        color_.setColor(Colors::C_PINK);
    }
}

/**
 * It sets the position of the button
 *
 * @param pos The position of the button.
 */
void Button::setPosition(const Vector2& pos) noexcept
{
    texture_.setPos(pos.x, pos.y);
    rectangle_.setPos(pos.x, pos.y);
}

/**
 * It sets the position of the text
 *
 * @param pos The position of the text.
 */
void Button::setTextPosition(const Vector2& pos) noexcept
{
    text_.setPosition(pos.x, pos.y);
}

/**
 * It sets the text of the button
 *
 * @param new_text The new text to be displayed on the button.
 */
void Button::setText(std::string new_text) noexcept
{
    text_.setText(new_text);
}

/**
 * Sets the size of the text
 *
 * @param size The size of the text.
 */
void Button::setTextSize(int size) noexcept
{
    text_.setTextSize(size);
}

/**
 * It inverts the display of the button
 */
void Button::invertDisplay() noexcept
{
    texture_.invertDisplay();
}