/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** StatComponent.cpp
*/

#include <ECS/Components/StatComponent.hpp>

/**
 * It's a constructor that takes two parameters and assigns them to the two member variables
 *
 * @param life The life of the entity.
 * @param damage The damage of the entity.
 */
StatComponent::StatComponent(std::vector<float> statistics_) noexcept
    : statistics_(statistics_)
{
}

/**
 * If the index is valid, return the value at that index, otherwise return
 * NO_INDEX.
 *
 * @param index The index of the stat to get.
 *
 * @return A reference to the stat at the given index.
 */
float StatComponent::getStat(int index) const noexcept
{
    if (index >= statistics_.size()) { return NO_INDEX; }
    return statistics_[index];
}

/**
 * It sets the value of a statistic
 *
 * @param index The index of the stat to set.
 * @param value The value to set the stat to.
 */
void StatComponent::setStat(int index, float value) noexcept
{
    while (index >= statistics_.size()) { statistics_.push_back(0); }
    statistics_[index] = value;
}