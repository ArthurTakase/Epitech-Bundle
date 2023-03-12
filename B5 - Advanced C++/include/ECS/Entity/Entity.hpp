/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Entity.cpp
*/

#pragma once

#include <ECS/Components/IComponent.hpp>
#include <Tools/InstanceOf.hpp>
#include <cstddef>
#include <memory>
#include <optional>
#include <type_traits>
#include <vector>

/**
 * @brief Entity part of the ECS. It can be linked to many components to add attributes to it. No variable must be
 * directly located in this object.
 */
class Entity
{
  public:
    explicit Entity(size_t id);
    Entity(const Entity& other) noexcept = default;
    Entity(Entity&& other) noexcept      = default;
    ~Entity() noexcept                   = default;

    Entity& operator=(const Entity& rhs) noexcept = delete;
    Entity& operator=(Entity&& rhs) noexcept      = delete;

    size_t                                    getId() const noexcept;
    std::vector<std::unique_ptr<IComponent>>& getComponents() noexcept;

  private:
    size_t                                   id_;
    std::vector<std::unique_ptr<IComponent>> components_ = {};

  public:
    /**
     * @brief Add a component to the entity
     *
     * @tparam T component type
     * @param component object constructor (ex: HitboxComponent(10, 10))
     */
    template <typename T>
    void addComponent(T&& component) noexcept
    {
        auto component_ptr = std::make_unique<std::remove_cvref_t<T>>(std::forward<T>(component));
        components_.push_back(std::move(component_ptr));
    };

    /**
     * @brief Get the corresponding component
     * @tparam T Component type
     * @return T* if component exist, nullptr otherwise
     */
    template <typename T>
    T* getComponent() noexcept
    {
        for (auto& i : components_) {
            if (Tools::instanceOf<T>(i.get())) { return dynamic_cast<T*>(i.get()); }
        }
        return nullptr;
    };

    /**
     * @brief Remove a component from the entity
     *
     * @tparam T component type
     * @return true if the component was removed
     * @return false if the component was not found
     */
    template <typename T>
    bool removeComponent() noexcept
    {
        for (size_t i = 0; i < components_.size(); i++) {
            if (Tools::instanceOf<T>(components_[i].get())) {
                components_.erase(components_.begin() + i);
                return true;
            }
        }
        return false;
    };

    /**
     * @brief Check if the entity has a component
     *
     * @tparam T component type
     * @return true if the entity has the component
     * @return false if the entity does not have the component
     */
    template <typename T>
    bool hasComponent() noexcept
    {
        for (auto& i : components_)
            if (Tools::instanceOf<T>(i.get())) { return true; }
        return false;
    };

    /**
     * @brief Check if the entity has multiple components
     *
     * @tparam T component type
     * @tparam Args component types
     * @return true if the entity has all the components
     * @return false if the entity does not have all the components
     */
    template <typename T, typename... Args>
    bool hasComponents() noexcept
    {
        if constexpr (sizeof...(Args) == 0) {
            return hasComponent<T>();
        } else {
            return hasComponent<T>() && hasComponents<Args...>();
        }
    };
};