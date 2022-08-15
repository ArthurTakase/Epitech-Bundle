/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** GameData
*/

#include "GameData.hpp"

#include <iostream>

#include "Bomb.hpp"
#include "Crate.hpp"
#include "Error.hpp"
#include "Fire.hpp"
#include "InstanceOf.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Save.hpp"
#include "Wall.hpp"

/**
 * This function returns the mouse position.
 *
 * @return The mouse position.
 */
Vector2D GameData::getMousePos() const noexcept
{
    return (mouse_.getMousePosition());
}

/**
 * It updates the mouse
 */
void GameData::updateMouse() noexcept
{
    mouse_.update();
}

/**
 * It returns a copy of the MouseHandler object.
 *
 * @return A reference to the mouse_ object.
 */
MouseHandler GameData::getMouseHandler() const noexcept
{
    return (mouse_);
}

/**
 * It sets the current scene to the scene passed in as a parameter
 *
 * @param scene The scene to set as the current scene.
 */
void GameData::setCurrentScene(const bomberman::SceneType& scene) noexcept
{
    current_scene_ = static_cast<typename std::underlying_type<bomberman::SceneType>::type>(scene);
}

/**
 * It creates a new model and adds it to the list of models
 *
 * @param model_path The path to the model file.
 * @param texture_path The path to the texture file.
 */
void GameData::addModel(
    const std::string_view& model_path, const std::string_view& texture_path) noexcept
{
    models_.emplace_back(std::make_unique<Model3D>(model_path, texture_path));
}

/**
 * It creates a new sprite, adds it to the sprites_ vector, and returns a reference to the new
 * sprite
 *
 * @param texture_path The path to the texture file.
 * @param scale The scale of the sprite.
 */
void GameData::addSprite(const std::string_view& texture_path, float scale) noexcept
{
    sprites_.emplace_back(std::make_unique<Sprite>(texture_path, 0, 0, scale));
}

/**
 * It creates a new player object and adds it to the players_ vector
 *
 * @param index The index of the player.
 */
void GameData::addPlayer(int index) noexcept
{
    players_.emplace_back(std::make_unique<Player>(index, *this));
}

/**
 * It creates a new item and adds it to the list of entities
 *
 * @param item The type of item to add.
 */
void GameData::addItem(bomberman::ItemType item) noexcept
{
    entities_.emplace_back(std::make_unique<Item>(*this, item));
}

/**
 * It creates a new item at the given position and adds it to the list of entities
 *
 * @param position The position of the item.
 */
void GameData::addItem(const Vector3D& position) noexcept
{
    entities_.emplace_back(std::make_unique<Item>(position, *this));
}

/**
 * It creates a new item at the given position and given type and adds it to the list of entities
 *
 * @param position The position of the item.
 */
void GameData::addItem(const Vector3D& position, bomberman::ItemType type) noexcept
{
    entities_.emplace_back(std::make_unique<Item>(*this, type, position));
}

/**
 * It returns the number of players in the game
 *
 * @return The number of players in the game.
 */
int GameData::getNbPlayers() const noexcept
{
    return (nb_players_);
}

/**
 * It sets the number of players
 *
 * @param value The value to set the parameter to.
 */
void GameData::setNbPlayers(int value) noexcept
{
    nb_players_ = value;
}

/**
 * It creates a new crate at the given position and adds it to the list of entities
 *
 * @param position The position of the crate.
 */
void GameData::addCrate(Vector3D position) noexcept
{
    entities_.emplace_back(std::make_unique<Crate>(position,
        *models_[static_cast<typename std::underlying_type<bomberman::ModelType>::type>(
            bomberman::ModelType::M_CRATE)],
        *this));
}

/**
 * It creates a new wall entity and adds it to the list of entities
 *
 * @param position The position of the wall.
 */
void GameData::addWall(Vector3D position) noexcept
{
    entities_.emplace_back(std::make_unique<Wall>(position,
        *models_[static_cast<typename std::underlying_type<bomberman::ModelType>::type>(
            bomberman::ModelType::M_WALL)]));
}

/**
 * It adds a fire to the game
 *
 * @param fire The fire to add to the game.
 */
void GameData::addFire(std::unique_ptr<Fire> fire) noexcept
{
    entities_.push_back(std::move(fire));
}

/**
 * It creates a new bomb entity and adds it to the list of entities
 *
 * @param position The position of the bomb
 * @param player_ref A reference to the player that placed the bomb.
 * @param size the size of the bomb
 */
void GameData::addBomb(Vector3D position, Player& player_ref, int size) noexcept
{
    entities_.emplace_back(std::make_unique<Bomb>(position,
        player_ref,
        *models_[static_cast<typename std::underlying_type<bomberman::ModelType>::type>(
            bomberman::ModelType::M_BOMB)],
        size,
        *this));
}

/**
 * It returns a reference to the vector of unique pointers to Entity objects
 *
 * @return A reference to the vector of unique pointers to Entity objects.
 */
std::vector<std::unique_ptr<Entity>>& GameData::getPlayers() noexcept
{
    return (players_);
}

/**
 * It returns a reference to the vector of unique pointers to Model3D objects
 *
 * @return A reference to the vector of unique pointers to Model3D objects.
 */
std::vector<std::unique_ptr<Model3D>>& GameData::getModels() noexcept
{
    return (models_);
}

/**
 * It returns a reference to the vector of unique pointers to Sprite objects
 *
 * @return A reference to the sprites_ vector.
 */
std::vector<std::unique_ptr<Sprite>>& GameData::getSprites() noexcept
{
    return (sprites_);
}

/**
 * It clears the entities_ vector
 */
void GameData::clearEntities() noexcept
{
    entities_.clear();
}

/**
 * It clears all the data containers
 */
void GameData::unloadAll() noexcept
{
    entities_.clear();
    players_.clear();
    models_.clear();
    sprites_.clear();
}

/**
 * It sets the value of the try_to_load member variable
 *
 * @param value The value to set the parameter to.
 */
void GameData::setTryToLoad(const std::string& value) noexcept
{
    try_to_load = value;
}

/**
 * It returns the string that is used to try to load the game data.
 *
 * @return The try_to_load variable.
 */
std::string GameData::tryToLoad() const noexcept
{
    return try_to_load;
}

void GameData::saveGame()
{
    std::unique_ptr<Save> parser = std::make_unique<Save>(*this);
    parser->save();
}

void GameData::loadGame()
{
    std::unique_ptr<Save> parser = std::make_unique<Save>(*this);
    parser->load(try_to_load);
}
