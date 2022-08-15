/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Crate
*/

#pragma once
#include "Entity.hpp"
#include "GameData.hpp"

class Crate : public Entity
{
  public:
    Crate(Vector3D pos, Model3D& model, GameData& data);
    Crate(const Crate& other) noexcept = delete;
    Crate(Crate&& other) noexcept      = delete;
    ~Crate() noexcept                  = default;

    Crate& operator=(const Crate& rhs) noexcept = delete;
    Crate& operator=(Crate&& rhs) noexcept = delete;

    void Update() final;
    void dropItem();
    void OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept final;

  public:
    GameData& data_;
};
