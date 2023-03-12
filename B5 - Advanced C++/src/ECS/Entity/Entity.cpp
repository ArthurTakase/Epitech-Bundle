/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Entity.cpp
*/

#include <ECS/Entity/Entity.hpp>
#include <iostream>

/**
 * It's a constructor for the Entity class
 *
 * @param id The id of the entity.
 */
Entity::Entity(size_t id)
    : id_(id)
{
}

/**
 * It returns the value of the private member variable _id
 *
 * @return The id of the entity.
 */
size_t Entity::getId() const noexcept
{
    return id_;
}

/**
 * It returns a reference to the vector of unique pointers to components
 *
 * @return A reference to the vector of unique pointers to IComponent.
 */
std::vector<std::unique_ptr<IComponent>>& Entity::getComponents() noexcept
{
    return (components_);
};