/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Bomb
*/

#pragma once

#include <math.h>

#include "Bomberman.hpp"
#include "Fire.hpp"
#include "Player.hpp"
#include "Sound.hpp"
#include "Timer.hpp"

class Bomb : public Entity
{
  public:
    Bomb(Vector3D pos, Player& p, Model3D& newModel, int bombSize, GameData& data);
    Bomb(const Bomb& other) noexcept = delete;
    Bomb(Bomb&& other) noexcept      = delete;
    ~Bomb() noexcept                 = default;

    Bomb& operator=(const Bomb& rhs) noexcept = delete;
    Bomb& operator=(Bomb&& rhs) noexcept = delete;

    void Update() final;
    void explode() noexcept;
    void OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept final;
    int  getLifeTime() const noexcept;
    void setLifeTime(const int& newLifeTime) noexcept;
    int  getOwnerId() const noexcept;

  private:
    // methods
    void createFire(Vector3D mul) noexcept;

    // attributes
    float                              lifeTime;
    Timer                              lifeTimer;
    Player&                            player;
    int                                size;
    bool                               hasHitbox;
    GameData&                          data;
    std::vector<std::unique_ptr<Fire>> fires;
    bool                               is_exploding_;
    int                                animeDir;
    SoundManager                       dropSound_;
    SoundManager                       explodeSound;

    static const inline char* DROP_BOMB = "assets/audios/DropBomb.wav";
    static const inline char* EXPLODE   = "assets/audios/Explode.wav";
};
