/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window
*/

#pragma once
#include "AWindow.hpp"
#include "AudioDevice.hpp"
#include "Cameraman.hpp"
#include "Fps.hpp"
#include "Scene.hpp"

class WindowManager : public AWindow
{
  public:
    WindowManager(int width, int height, int fps) noexcept;
    WindowManager(const WindowManager& other) noexcept = delete;
    WindowManager(WindowManager&& other) noexcept      = delete;
    ~WindowManager() noexcept;

    WindowManager& operator=(const WindowManager& rhs) noexcept = delete;
    WindowManager& operator=(WindowManager&& rhs) noexcept = delete;

    // getters and setters
    int  getMusicPercentage() const noexcept;
    void resetHeight() noexcept final;
    void resetWidth() noexcept final;

    // methods
    void display(Scene& scene, const Cameraman& camera) noexcept;
    bool isExit() noexcept final;
    void setFps(float value) noexcept final;
    void increaseFps() noexcept;
    void decreaseFps() noexcept;
    void increaseMusic() noexcept;
    void decreaseMusic() noexcept;

  protected:
  private:
    int                  music_percent_ = 100;
    int                  index_         = 1;
    std::array<float, 4> possible_fps_  = { 30, 60, 90, 120 };
};
