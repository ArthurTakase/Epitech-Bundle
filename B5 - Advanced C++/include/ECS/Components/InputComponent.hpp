/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** InputComponent.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <queue>

/**
 * @brief Component assigned to drawable entities.
 */
class InputComponent : public IComponent
{
  public:
    InputComponent() noexcept                            = default;
    ~InputComponent() noexcept                           = default;
    InputComponent(const InputComponent& other) noexcept = default;
    InputComponent(InputComponent&& other) noexcept      = default;

    InputComponent& operator=(const InputComponent& rhs) noexcept = default;
    InputComponent& operator=(InputComponent&& rhs) noexcept      = default;

    int  getInput() noexcept;
    void addInput(int input) noexcept;
    void clearInputs() noexcept;

  private:
    std::queue<int> inputs_;
};