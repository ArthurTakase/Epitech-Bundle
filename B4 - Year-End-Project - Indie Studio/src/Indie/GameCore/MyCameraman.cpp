/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** MyCameraman.cpp
*/

#include "MyCameraman.hpp"

#include <math.h>

#include <cmath>

#include "Error.hpp"

/**
 * It finds the center of the entities and sets the camera's position and target to that point
 *
 * @param entities A vector of pointers to the entities that are being rendered.
 */
void MyCameraman::lookBetweenEntity(const std::vector<std::unique_ptr<Entity>>& entities)
{
    float minX = INFINITY;
    float minZ = INFINITY;
    float maxX = -minX;
    float maxZ = -minZ;

    for (auto& entity : entities) {
        auto render = entity->getComponent<Render>();
        if (!render.has_value()) continue;

        auto transform = entity->getComponent<Transform3D>();
        if (!transform.has_value()) throw(Error("Error in camera_ handling.\n"));

        Vector3D pos = transform->get().getPosition();
        if (pos.x < minX) minX = pos.x;
        if (pos.x > maxX) maxX = pos.x;
        if (pos.z < minZ) minZ = pos.z;
        if (pos.z > maxZ) maxZ = pos.z;
    }

    float newX = (minX + maxX) / 2;
    float newZ = (minZ + maxZ) / 2;

    camera_.target.x   = newX;
    camera_.target.z   = newZ;
    camera_.position.x = newX;
    camera_.position.z = newZ + 2.0f;
    camera_.position.y =
        static_cast<float>(sqrt(pow(maxX - minX, 2) + pow(maxZ - minZ, 2)) * 0.8f + 2.0f);

    if (camera_.position.y <= 8.0f) { camera_.position.y = 8.0f; }
}