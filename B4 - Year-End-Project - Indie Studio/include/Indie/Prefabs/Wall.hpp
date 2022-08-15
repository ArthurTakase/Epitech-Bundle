/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Box
*/

#pragma once

#include "Crate.hpp"

class Wall : public Entity
{
  public:
    Wall(Vector3D pos, Model3D& model);
    Wall(const Wall& other) noexcept = delete;
    Wall(Wall&& other) noexcept      = delete;
    ~Wall() noexcept                 = default;

    Wall& operator=(const Wall& rhs) noexcept = delete;
    Wall& operator=(Wall&& rhs) noexcept = delete;

    void Update() final;
    void OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept final;

  protected:
  private:
};