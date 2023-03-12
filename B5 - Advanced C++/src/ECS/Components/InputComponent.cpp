/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** InputComponent
*/

#include <ECS/Components/InputComponent.hpp>

/**
 * If there are no inputs_, return -1, otherwise return the first input in the
 * queue.
 *
 * @return The first input in the queue.
 */
int InputComponent::getInput() noexcept
{
    if (inputs_.empty()) { return (-1); }

    int input = inputs_.front();
    inputs_.pop();

    return (input);
}

/**
 * It adds an input to the set of inputs_
 *
 * @param input The input to add to the component.
 */
void InputComponent::addInput(int input) noexcept
{
    inputs_.emplace(input);
}

/**
 * It clears the inputs_ queue
 */
void InputComponent::clearInputs() noexcept
{
    while (!inputs_.empty()) { inputs_.pop(); }
}