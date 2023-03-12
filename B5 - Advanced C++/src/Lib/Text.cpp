/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Text.cpp
*/

#include <Error/Error.hpp>
#include <Lib/Text.hpp>
#include <iostream>

/**
 * It initializes all the member variables of the Text class to their default
 * values
 */
Text::Text()
    : textString_("")
    , fontPath_("")
    , fontSize_(0)
    , x_(0)
    , y_(0)
    , color_(sf::Color::White)
    , text_("", font_)
{
}

/**
 * It creates a text object with the given text, font, font size, and position.
 *
 * @param text The text to be displayed
 * @param fontPath The path to the font file.
 * @param fontSize The size of the font.
 * @param x The x position of the text
 * @param y The y coordinate of the text.
 *
 * @return A reference to the text object.
 */
Text::Text(const std::string& text, const std::string& fontPath, int fontSize, int x, int y)
    : textString_(text)
    , fontPath_(fontPath)
    , fontSize_(fontSize)
    , x_(x)
    , y_(y)
    , color_(sf::Color::White)
    , text_(text.c_str(), font_)
{
    if (text == "" || fontPath == "") { return; }

    if (!font_.loadFromFile(fontPath)) { throw Error("Error: Could not load font from file: " + fontPath); }
    text_.setFont(font_);
    text_.setString(textString_);
    text_.setCharacterSize(fontSize);
    text_.setPosition({static_cast<float>(x), static_cast<float>(y)});
}

/**
 * It sets the text string of the text object
 *
 * @param text The text to be displayed.
 */
void Text::setTextString(const std::string& text)
{
    textString_ = text;
    text_.setString(textString_);
}

/**
 * It sets the font path and loads the font from the file
 *
 * @param path The path to the font file.
 */
void Text::setFontPath(const std::string& path)
{
    fontPath_ = path;

    if (!font_.loadFromFile(fontPath_)) { throw Error("Error: Could not load font from file: " + fontPath_); }
    text_.setFont(font_);
}

/**
 * It sets the font size of the text object
 *
 * @param size The size of the font.
 */
void Text::setFontSize(int size)
{
    fontSize_ = size;
    text_.setCharacterSize(fontSize_);
}

/**
 * Sets the x coordinate of the text.
 *
 * @param x The x coordinate of the text.
 */
void Text::setX(int x)
{
    this->x_ = x;
    text_.setPosition({static_cast<float>(x), static_cast<float>(y_)});
}

/**
 * Sets the y coordinate of the text.
 *
 * @param y The y coordinate of the text.
 */
void Text::setY(int y)
{
    this->y_ = y;
    text_.setPosition({static_cast<float>(x_), static_cast<float>(y)});
}

/**
 * It sets the color of the text
 *
 * @param r Red value
 * @param g The graphics object to draw the text on.
 * @param b The boldness of the text.
 * @param a The text to be displayed
 */
void Text::setColor(int r, int g, int b, int a)
{
    color_ = sf::Color(r, g, b, a);
    text_.setFillColor(color_);
}

/**
 * This function returns a pointer to the text_ variable.
 *
 * @return A pointer to the text_ variable.
 */
void* Text::getText()
{
    return static_cast<void*>(&text_);
}

/**
 * This function returns a pointer to the font_ member of the Text class.
 *
 * @return A pointer to the font_ object.
 */
void* Text::getFont()
{
    return static_cast<void*>(&font_);
}

/**
 * This function returns a pointer to the color_ member of the Text class.
 *
 * @return A pointer to the color_ member variable.
 */
void* Text::getColor()
{
    return static_cast<void*>(&color_);
}

/**
 * GetX() returns the x coordinate of the text.
 *
 * @return The x coordinate of the text.
 */
int Text::getX() const
{
    return x_;
}

/**
 * GetY() returns the y coordinate of the text.
 *
 * @return The y coordinate of the text.
 */
int Text::getY() const
{
    return y_;
}

/**
 * This function returns the font size of the text.
 *
 * @return The font size of the text.
 */
int Text::getFontSize() const
{
    return fontSize_;
}

/**
 *
 * @return The textString_ variable is being returned.
 */
std::string Text::getTextString() const
{
    return textString_;
}

/**
 * It returns the font path
 *
 * @return The fontPath_ variable.
 */
std::string Text::getFontPath() const
{
    return fontPath_;
}
