/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** AData
*/

#include "AData.hpp"

/**
 * This function returns the current scene index.
 *
 * @return The current scene index.
 */
int AData::getCurrentSceneIndex() const noexcept
{
    return (current_scene_);
}

/**
 * It returns the number of players
 *
 * @return The number of players.
 */
int AData::getNbPlayers() const noexcept
{
    return (nb_players_);
}

/**
 * It sets the number of players
 *
 * @param value The value to set the parameter to.
 */
void AData::setNbPlayers(int value) noexcept
{
    nb_players_ = value;
}

/**
 * It returns a reference to the vector of unique pointers to entities
 *
 * @return A reference to the vector of unique pointers to entities.
 */
std::vector<std::unique_ptr<Entity>>& AData::getEntities() noexcept
{
    return (entities_);
}

/**
 * Clear the entities_ vector.
 */
void AData::clearEntities() noexcept
{
    entities_.clear();
}
