/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Player
*/

#pragma once

#include <memory>
#include <vector>

#include "Bomberman.hpp"
#include "Color.hpp"
#include "Controller.hpp"
#include "Entity.hpp"
#include "GameData.hpp"
#include "Sound.hpp"
#include "Timer.hpp"
#include "Vector.hpp"

enum class PlayerType { NORMAL, ATTACK, TACTICAL, RUNNER, __size__ };

class Player : public Entity
{
  public:
    Player(const int newId, GameData& data);
    ~Player() noexcept                   = default;
    Player(const Player& other) noexcept = delete;
    Player(Player&& other) noexcept      = delete;
    Player& operator=(const Player& rhs) noexcept = delete;
    Player& operator=(Player&& rhs) noexcept = delete;

    void       Update() final;
    void       addItem(bomberman::ItemType item) noexcept;
    void       dispatchItem() noexcept;
    void       OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept;
    void       setStats(int bomb, int sp, int size) noexcept;
    void       setPlayerType(PlayerType type) noexcept;
    void       setWallPass(const bool& pass) noexcept;
    bool       getWallPass() const noexcept;
    bool       getWallPassEnd() const noexcept;
    int        getNbBombMax() const noexcept;
    float      getSpeedMax() const noexcept;
    int        getBombSizeMax() const noexcept;
    float      getSpeed() const noexcept;
    int        getNbBomb() const noexcept;
    int        getBombSize() const noexcept;
    void       setSpeed(const float& speed) noexcept;
    void       setNbBomb(const int& nbBomb) noexcept;
    void       setBombSize(const int& bombSize) noexcept;
    PlayerType getPlayerType() const noexcept;
    void       setPosition();
    void       setPosition(Vector3D pos);
    PlayerType getType() const noexcept;
    int        getId() const noexcept;
    int        findNextType() const noexcept;
    int        findPrevType() const noexcept;
    void       toggleBot() noexcept;
    void       setIsBot(const bool& bot) noexcept;
    bool       isPlayer() const noexcept;
    bool       getBotState() const noexcept;

  private:
    // methods
    void                  setKeyboard() noexcept;
    void                  placeBomb();
    bool                  isCollidingNextTurn(int xdir, int zdir);
    void                  handlePlayerMovement();
    void                  handleAutoMovement();
    std::vector<Vector3D> getSurroundingBox();
    std::vector<Vector3D> getBombsPositions();
    std::vector<Vector3D> getFirePositions();
    std::vector<Vector3D> getPowerupPositions();
    std::vector<Vector3D> getPlayersPositions();

    // attributes
    SoundManager                     killSound_;
    Controller                       controller;
    Key                              moveUp;
    Key                              moveDown;
    Key                              moveLeft;
    Key                              moveRight;
    Key                              dropBomb;
    int                              id;
    GameData&                        data;
    std::vector<bomberman::ItemType> items;
    bool                             wallpass;
    Timer                            wallpassTimer;
    bool                             wallpassEnd;
    bool                             isBot;
    int                              nbBomb;
    float                            speed;
    int                              bombSize;
    int                              nbBombMax;
    float                            speedMax;
    int                              bombSizeMax;
    PlayerType                       type;
    int                              colorIndex = 0;
    std::array<float, 4>             direction  = { 90, 270, 90, 270 };

    std::vector<std::array<unsigned char, 3>> colors = { Colors::C_LIGHTGRAY,
        Colors::C_GRAY,
        Colors::C_YELLOW,
        Colors::C_GOLD,
        Colors::C_ORANGE,
        Colors::C_PINK,
        Colors::C_RED,
        Colors::C_MAROON,
        Colors::C_GREEN,
        Colors::C_LIME,
        Colors::C_DARKGREEN,
        Colors::C_SKYBLUE,
        Colors::C_BLUE,
        Colors::C_DARKBLUE,
        Colors::C_PURPLE,
        Colors::C_VIOLET,
        Colors::C_DARKPURPLE,
        Colors::C_BEIGE,
        Colors::C_BROWN,
        Colors::C_DARKBROWN };

    static const inline char* KILL = "assets/audios/Kill.wav";
};
