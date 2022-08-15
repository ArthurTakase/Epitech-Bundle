/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AData
*/

#pragma once
#include "Entity.hpp"

class AData
{
  public:
    AData() noexcept                   = default;
    AData(const AData& other) noexcept = delete;
    AData(AData&& other) noexcept      = delete;
    ~AData() noexcept                  = default;

    AData& operator=(const AData& rhs) noexcept = delete;
    AData& operator=(AData&& rhs) noexcept = delete;

    virtual void updateMouse() noexcept = 0;
    int          getCurrentSceneIndex() const noexcept;
    int          getNbPlayers() const noexcept;
    void         setNbPlayers(int value) noexcept;
    void         clearEntities() noexcept;
    void         unloadAll() noexcept;

    std::vector<std::unique_ptr<Entity>>& getEntities() noexcept;

  protected:
    int                                  current_scene_ = 0;
    int                                  nb_players_    = 0;
    std::vector<std::unique_ptr<Entity>> entities_;

  private:
};
