/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AWindow
*/

#pragma once

class AWindow
{
  public:
    AWindow(int width, int height, int fps) noexcept;
    AWindow(const AWindow& other) noexcept = delete;
    AWindow(AWindow&& other) noexcept      = delete;
    virtual ~AWindow() noexcept            = default;

    AWindow& operator=(const AWindow& rhs) noexcept = delete;
    AWindow& operator=(AWindow&& rhs) noexcept = delete;

    // getters
    int   getWidth() const noexcept;
    int   getHeight() const noexcept;
    float getFps() const noexcept;

    // virtual methods
    virtual void setFps(float value) noexcept = 0;
    virtual void resetHeight() noexcept       = 0;
    virtual void resetWidth() noexcept        = 0;
    virtual bool isExit()                     = 0;

  protected:
    int   width_;
    int   height_;
    float fps_;

  private:
};