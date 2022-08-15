/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description: hpp file
** AI
*/

#pragma once

#include <vector>

#include "Component.hpp"
#include "Game.hpp"

enum class AIEvent { NONE, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, PLACE_BOMB };

class AI : public Component
{
  public:
    AI() noexcept;
    ~AI() noexcept               = default;
    AI(AI const& other) noexcept = default;
    AI(AI&& other) noexcept      = default;

    AI& operator=(AI const& other) noexcept = default;
    AI& operator=(AI&& other) noexcept = default;

    ComponentType getComponentType() const noexcept;
    AIEvent       getEvent(Vector2D& playerPosition,
              std::vector<Vector3D>& boxes,
              std::vector<Vector3D>& bombs,
              std::vector<Vector3D>& fires,
              std::vector<Vector3D>& players,
              std::vector<Vector3D>& powerups,
              int                    nbBomb);
    void          handleColliding();

    static constexpr ComponentType TYPE = ComponentType::AI;

  private:
    static float distance(int x1, int y1, int x2, int y2);
    std::string  getPossibleActions() const noexcept;
    bool         canPlaceBomb();
    bool         dodgeBombs() const;
    AIEvent      findSafePath();
    void         sideMovements();
    bool         isDirectionSafe(Direction direction, bool fireOnly = false) const;
    bool         isDirectionBlocked(Direction direction, float offset = 1) const;
    bool         isInCase(Vector2D pos1, Vector3D pos2, float offset = 0.5) const;
    bool         isInCross(Vector2D pos1, Vector3D pos2) const;
    float        distance(Vector2D pos1, Vector2D pos2) const;
    AIEvent      movePlayer();
    char         getObjectAtPosition(int x, int y);
    void         calculateMap();

    std::string              actions_;
    Vector2D                 next_pos_;
    Direction                direction_;
    std::string              possible_actions_;
    Vector2D                 player_position_;
    std::vector<Vector3D>    boxes_;
    std::vector<Vector3D>    bombs_;
    std::vector<Vector3D>    fires_;
    std::vector<Vector3D>    players_;
    std::vector<Vector3D>    powerups_;
    std::vector<std::string> map_;
    int                      nb_bomb_;
    int                      placed_bombs_;
    bool                     is_moving_;
};