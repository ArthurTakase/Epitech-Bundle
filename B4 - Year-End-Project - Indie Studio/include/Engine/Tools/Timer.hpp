/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Timer
*/

#pragma once

class Timer
{
  public:
    Timer(float lifeTime) noexcept;
    ~Timer() noexcept                  = default;
    Timer(const Timer& other) noexcept = delete;
    Timer(Timer&& other) noexcept      = delete;

    Timer& operator=(const Timer& rhs) noexcept = delete;
    Timer& operator=(Timer&& rhs) noexcept = delete;

    float getTime() const noexcept;
    void  setLifeTime(float time) noexcept;

    void updateTimer() noexcept;
    void resetTimer() noexcept;
    bool isTimerDone() const noexcept;

  private:
    float life_time_;
    float default_;
};
