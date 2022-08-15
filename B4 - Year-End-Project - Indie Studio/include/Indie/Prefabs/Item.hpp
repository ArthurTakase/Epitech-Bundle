/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Item
*/

#pragma once

#include "Bomberman.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Sound.hpp"

class Item : public Entity
{
  public:
    Item(Vector3D pos, GameData& data);
    Item(GameData& data, bomberman::ItemType type);
    Item(GameData& data, bomberman::ItemType type, Vector3D pos);
    Item(const Item& other) noexcept = delete;
    Item(Item&& other) noexcept      = delete;
    ~Item() noexcept                 = default;

    Item& operator=(const Item& rhs) noexcept = delete;
    Item& operator=(Item&& rhs) noexcept = delete;

    void                Update() final;
    void                OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept;
    void                setType(const bomberman::ItemType& type) noexcept;
    bomberman::ItemType getType() const noexcept;

  private:
    void     setPlayerStat(std::unique_ptr<Player>& p) noexcept;
    Vector3D findFreePosition(void) const noexcept;
    bool     entitiesHere(Vector3D& pos) const noexcept;
    Model3D& findItemModel() const noexcept;

  private:
    GameData&           data;
    bomberman::ItemType itemType;
    SoundManager        getItemSound;
    SoundManager        newItemSound;

    static const inline char* GET_ITEM = "assets/audios/GetItem.wav";
    static const inline char* NEW_ITEM = "assets/audios/NewItem.wav";
};
