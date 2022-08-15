/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Fps
*/

#pragma once

class FpsHandler
{
  public:
    FpsHandler() noexcept                        = delete;
    FpsHandler(const FpsHandler& other) noexcept = delete;
    FpsHandler(FpsHandler&& other) noexcept      = delete;
    ~FpsHandler() noexcept                       = delete;

    FpsHandler& operator=(const FpsHandler& rhs) noexcept = delete;
    FpsHandler& operator=(FpsHandler&& rhs) noexcept = delete;

    static void draw(int x, int y);
    static void setFps(float fps) noexcept;

  protected:
  private:
};