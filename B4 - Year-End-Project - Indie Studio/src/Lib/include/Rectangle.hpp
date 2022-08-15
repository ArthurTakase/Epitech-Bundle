/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Rectangle
*/

#pragma once

class RectangleManager
{
  public:
    RectangleManager(float x, float y, float width, float height) noexcept;
    RectangleManager(const RectangleManager& other) noexcept = default;
    RectangleManager(RectangleManager&& other) noexcept      = default;
    ~RectangleManager() noexcept                             = default;

    RectangleManager& operator=(const RectangleManager& rhs) noexcept = default;
    RectangleManager& operator=(RectangleManager&& rhs) noexcept = default;

    float getX() const noexcept;
    float getY() const noexcept;
    float getWidth() const noexcept;
    float getHeight() const noexcept;
    void  setPos(float x, float y) noexcept;
    void  setWidth(float width) noexcept;
    void  setHeight(float height) noexcept;

  protected:
  private:
    float x_;
    float y_;
    float width_;
    float height_;
};
