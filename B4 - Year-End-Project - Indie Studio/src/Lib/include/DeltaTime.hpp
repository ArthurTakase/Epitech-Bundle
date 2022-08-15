/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** DeltaTime.cpp
*/

#pragma once

class DeltaTime
{
  public:
    DeltaTime() noexcept                       = delete;
    ~DeltaTime() noexcept                      = delete;
    DeltaTime(const DeltaTime& other) noexcept = delete;
    DeltaTime(DeltaTime&& other) noexcept      = delete;

    DeltaTime& operator=(const DeltaTime& rhs) noexcept = delete;
    DeltaTime& operator=(DeltaTime&& rhs) noexcept = delete;

    static float getDeltaTime() noexcept;
};