/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** AI
*/

#include "AI.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Component.hpp"
#include "Game.hpp"
#include "Vector.hpp"
#include "raylib.h"

AI::AI() noexcept
    : actions_(" udlrp")
    , next_pos_({ 0, 0 })
    , is_moving_(false)
    , direction_(Direction::DOWN)
    , player_position_({ 0, 0 })
    , boxes_({})
    , bombs_({})
    , fires_({})
    , players_({})
    , powerups_({})
    , placed_bombs_(0)
{
}

void AI::handleColliding()
{
    if (is_moving_) { is_moving_ = false; }
}

float AI::distance(Vector2D pos1, Vector2D pos2) const
{
    return (std::sqrt(std::pow(pos1.x - pos2.x, 2) + std::pow(pos1.y - pos2.y, 2)));
}

bool AI::isInCase(Vector2D pos1, Vector3D pos2, float offset) const
{
    float pos2_x_max = pos2.x + offset;
    float pos2_x_min = pos2.x - offset;
    float pos2_z_max = pos2.z + offset;
    float pos2_z_min = pos2.z - offset;
    if (pos1.x > pos2_x_min && pos1.x < pos2_x_max && pos1.y > pos2_z_min && pos1.y < pos2_z_max)
        return true;
    return false;
}

bool AI::isInCross(Vector2D pos1, Vector3D pos2) const
{
    float pos2_x_max = pos2.x + 0.5;
    float pos2_x_min = pos2.x - 0.5;
    float pos2_z_max = pos2.z + 0.5;
    float pos2_z_min = pos2.z - 0.5;
    if ((pos1.x > pos2_x_min && pos1.x < pos2_x_max)
        || (pos1.y > pos2_z_min && pos1.y < pos2_z_max))
        return true;
    return false;
}

bool AI::isDirectionBlocked(Direction direction, float offset) const
{
    Vector2D next_pos = player_position_;

    switch (direction) {
        case Direction::UP: next_pos.y -= offset; break;
        case Direction::DOWN: next_pos.y += offset; break;
        case Direction::LEFT: next_pos.x -= offset; break;
        case Direction::RIGHT: next_pos.x += offset; break;
        default: break;
    }
    for (auto& box : boxes_) {
        if (isInCase(next_pos, box)) { return (true); }
    }
    return (false);
}

std::string AI::getPossibleActions() const noexcept
{
    std::string possible_actions = actions_;

    if (isDirectionBlocked(Direction::UP)) {
        possible_actions.erase(possible_actions.find('u'), 1);
    }
    if (isDirectionBlocked(Direction::DOWN)) {
        possible_actions.erase(possible_actions.find('d'), 1);
    }
    if (isDirectionBlocked(Direction::LEFT)) {
        possible_actions.erase(possible_actions.find('l'), 1);
    }
    if (isDirectionBlocked(Direction::RIGHT)) {
        possible_actions.erase(possible_actions.find('r'), 1);
    }
    return possible_actions;
}

bool AI::canPlaceBomb()
{
    Vector2D next_pos       = player_position_;
    int      path_available = possible_actions_.size() - 2;

    if (nb_bomb_ <= 0
        || (round(abs(player_position_.x)) == 6 && round(abs(player_position_.y)) == 4)) {
        return (false);
    }
    if (placed_bombs_ < 4) {
        if (path_available != 1) { return (false); }
        if (possible_actions_.find('u') != std::string::npos) { next_pos.y += 1; }
        if (possible_actions_.find('d') != std::string::npos) { next_pos.y -= 1; }
        if (possible_actions_.find('l') != std::string::npos) { next_pos.x -= 1; }
        if (possible_actions_.find('r') != std::string::npos) { next_pos.x += 1; }
        for (auto& fire : fires_) {
            if (isInCase(next_pos_, fire)) { return false; }
        }
        return (true);
    }
    if (placed_bombs_ >= 4) {
        if (path_available > 2) { return (false); }
        return (true);
    }
    return (false);
}

bool AI::dodgeBombs() const
{
    for (auto& bomb : bombs_) {
        if (isInCross(player_position_, bomb)
            && distance(player_position_, { bomb.x, bomb.z }) < 4) {
            return true;
        }
    }
    return false;
}

float AI::distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

bool AI::isDirectionSafe(Direction direction, bool fireOnly) const
{
    Vector2D next_pos = player_position_;

    switch (direction) {
        case Direction::UP: next_pos.y -= 1; break;
        case Direction::DOWN: next_pos.y += 1; break;
        case Direction::LEFT: next_pos.x -= 1; break;
        case Direction::RIGHT: next_pos.x += 1; break;
        default: break;
    }
    for (auto& fire : fires_) {
        if (isInCase(next_pos, fire)) return false;
    }
    if (!fireOnly) {
        for (auto& bomb : bombs_) {
            if (distance(player_position_, { bomb.x, bomb.z }) < 4) {
                if (isInCase(next_pos, bomb)) return (false);
                if (isInCase(player_position_, bomb)
                    || (isInCross(player_position_, bomb)
                        && distance(player_position_.x, player_position_.y, bomb.x, bomb.z)
                               < distance(next_pos.x, next_pos.y, bomb.x, bomb.z)))
                    return (true);
                if (isInCross(next_pos, bomb)) return (false);
            }
        }
    }
    return true;
}

AIEvent AI::findSafePath()
{
    Vector3D toDodge = { 0, 0, 0 };

    for (auto& bomb : bombs_) {
        if (isInCross(player_position_, bomb) && distance(player_position_, { bomb.x, bomb.z }) < 3)
            toDodge = bomb;
    }
    if (isInCase(player_position_, toDodge, 0.75) && is_moving_ == false) {
        if (!isDirectionBlocked(Direction::UP, 0.8)
            && !isInCase({ player_position_.x, player_position_.y - 1 }, toDodge)
            && isDirectionSafe(Direction::UP, true)) {
            is_moving_ = true;
            direction_ = Direction::UP;
            return (AIEvent::MOVE_UP);
        }
        if (!isDirectionBlocked(Direction::DOWN, 0.8)
            && !isInCase({ player_position_.x, player_position_.y + 1 }, toDodge)
            && isDirectionSafe(Direction::DOWN, true)) {
            is_moving_ = true;
            direction_ = Direction::DOWN;
            return (AIEvent::MOVE_DOWN);
        }
        if (!isDirectionBlocked(Direction::LEFT, 0.8)
            && !isInCase({ player_position_.x - 1, player_position_.y }, toDodge)
            && isDirectionSafe(Direction::LEFT, true)) {
            is_moving_ = true;
            direction_ = Direction::LEFT;
            return (AIEvent::MOVE_LEFT);
        }
        if (!isDirectionBlocked(Direction::RIGHT, 0.8)
            && !isInCase({ player_position_.x + 1, player_position_.y }, toDodge)
            && isDirectionSafe(Direction::RIGHT, true)) {
            is_moving_ = true;
            direction_ = Direction::RIGHT;
            return (AIEvent::MOVE_RIGHT);
        }
        is_moving_ = false;
    } else if (isInCross(player_position_, toDodge) && is_moving_ == false) {
        float toDodge_x_max = toDodge.x + 0.5;
        float toDodge_x_min = toDodge.x - 0.5;
        float toDodge_z_max = toDodge.z + 0.5;
        float toDodge_z_min = toDodge.z - 0.5;
        if (player_position_.x > toDodge_x_min && player_position_.x < toDodge_x_max) {
            if (!isDirectionBlocked(Direction::LEFT, 0.8)
                && !isInCase({ player_position_.x - 1, player_position_.y }, toDodge)) {
                is_moving_ = true;
                direction_ = Direction::LEFT;
                return (AIEvent::MOVE_LEFT);
            }
            if (!isDirectionBlocked(Direction::RIGHT, 0.8)
                && !isInCase({ player_position_.x + 1, player_position_.y }, toDodge)) {
                is_moving_ = true;
                direction_ = Direction::RIGHT;
                return (AIEvent::MOVE_RIGHT);
            }
        }
        if (player_position_.y > toDodge_z_min && player_position_.y < toDodge_z_max) {
            if (!isDirectionBlocked(Direction::UP, 0.8)
                && !isInCase({ player_position_.x, player_position_.y - 1 }, toDodge)) {
                is_moving_ = true;
                direction_ = Direction::UP;
                return (AIEvent::MOVE_UP);
            }
            if (!isDirectionBlocked(Direction::DOWN, 0.8)
                && !isInCase({ player_position_.x, player_position_.y + 1 }, toDodge)) {
                is_moving_ = true;
                direction_ = Direction::DOWN;
                return (AIEvent::MOVE_DOWN);
            }
        }
    } else if (isInCross(player_position_, toDodge) && is_moving_ && rand() % 4 == 0) {
    }
    return AIEvent::NONE;
}

void AI::sideMovements()
{
    if (rand() % 32 > 2 || dodgeBombs()) return;
    if (direction_ == Direction::UP
        || direction_ == Direction::DOWN
               && (abs(std::fmod(player_position_.y, 1)) <= 0.1
                   || abs(std::fmod(player_position_.y, 1)) >= 0.9)) {
        if (isDirectionSafe(Direction::LEFT) && !isDirectionBlocked(Direction::LEFT)) {
            direction_ = Direction::LEFT;
            return;
        }
        if (isDirectionSafe(Direction::RIGHT) && !isDirectionBlocked(Direction::RIGHT)) {
            direction_ = Direction::RIGHT;
            return;
        }
    }
    if (direction_ == Direction::LEFT
        || direction_ == Direction::RIGHT
               && (abs(std::fmod(player_position_.x, 1)) <= 0.1
                   || abs(std::fmod(player_position_.x, 1)) >= 0.9)) {
        if (isDirectionSafe(Direction::UP) && !isDirectionBlocked(Direction::UP)) {
            direction_ = Direction::UP;
            return;
        }
        if (isDirectionSafe(Direction::DOWN) && !isDirectionBlocked(Direction::DOWN)) {
            direction_ = Direction::DOWN;
            return;
        }
    }
}

AIEvent AI::movePlayer()
{
    char action = possible_actions_[rand() % (possible_actions_.size() + 1)];

    if (is_moving_ && isDirectionSafe(direction_)) {
        sideMovements();
        if (direction_ == Direction::UP) { return (AIEvent::MOVE_UP); }
        if (direction_ == Direction::DOWN) { return (AIEvent::MOVE_DOWN); }
        if (direction_ == Direction::LEFT) { return (AIEvent::MOVE_LEFT); }
        if (direction_ == Direction::RIGHT) { return (AIEvent::MOVE_RIGHT); }
    } else if (is_moving_ == false) {
        if (rand() % 2 == 0 && canPlaceBomb()) {
            placed_bombs_++;
            return (AIEvent::PLACE_BOMB);
        }
        if (action == 'u') {
            is_moving_ = true;
            direction_ = Direction::UP;
        } else if (action == 'd') {
            is_moving_ = true;
            direction_ = Direction::DOWN;
        } else if (action == 'l') {
            is_moving_ = true;
            direction_ = Direction::LEFT;
        } else if (action == 'r') {
            is_moving_ = true;
            direction_ = Direction::RIGHT;
        }
    } else if (is_moving_ == true && isDirectionSafe(direction_) == false) {
        is_moving_ = false;
    }
    return (AIEvent::NONE);
}

char AI::getObjectAtPosition(int x, int z)
{
    for (auto& box : boxes_) {
        if (box.x == x && box.z == z) { return ('w'); }
    }
    for (auto& bomb : bombs_) {
        if (bomb.x == x && bomb.z == z) { return ('b'); }
    }
    for (auto& player : players_) {
        if (round(player.x) == x && round(player.z) == z) { return ('p'); }
    }
    for (auto& powerup : powerups_) {
        if (powerup.x == x && powerup.z + 0.5 == z) { return ('P'); }
    }
    for (auto& fire : fires_) {
        if (fire.x == x && fire.z == z) { return ('f'); }
    }
    if (x == round(player_position_.x) && z == round(player_position_.y)) { return ('j'); }
    return (' ');
}

void AI::calculateMap()
{
    map_.clear();
    map_ = std::vector<std::string>(16, std::string(16, ' '));
    for (int z = -5; z < 8; z++) {
        for (int x = -7; x < 8; x++) { map_[z + 5][x + 7] = getObjectAtPosition(x, z); }
    }
    for (auto& line : map_) { std::cout << line << std::endl; }
}

AIEvent AI::getEvent(Vector2D& playerPosition,
    std::vector<Vector3D>&     boxes,
    std::vector<Vector3D>&     bombs,
    std::vector<Vector3D>&     fires,
    std::vector<Vector3D>&     players,
    std::vector<Vector3D>&     powerups,
    int                        nbBomb)
{
    player_position_  = playerPosition;
    boxes_            = boxes;
    bombs_            = bombs;
    fires_            = fires;
    players_          = players;
    powerups_         = powerups;
    nb_bomb_          = nbBomb;
    possible_actions_ = getPossibleActions();

    calculateMap();
    if (dodgeBombs()) findSafePath();
    return (movePlayer());
}

ComponentType AI::getComponentType() const noexcept
{
    return (TYPE);
}