/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Game.cpp
*/

#include <Client/Game.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/MusicComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <iostream>

/**
 * It's a constructor for the Game class
 *
 * @param packets The queue of packets received
 * @param mutex The mutex used to protect the queue of packets
 */
Game::Game(std::queue<GamePacket>& packets, std::mutex& mutex)
    : dataReceived_(packets)
    , mutexForPacket_(mutex)
    , drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , soundSystem_(&manager_)
    , musicSystem_(&manager_)
{
    drawableSystem_.setWindow(&lib_.getWindow());
    soundSystem_.setSoundManager(&soundManager_);

    for (auto& path : soundPaths_) { soundManager_.addSoundBuffer(path); }
    createSound(EXPLOSION_PATH);
    createSound(HEAL_PATH);
    createSound(HURT_PATH);
    createSound(MENU_PATH);
    createSound(PIOU_PATH);
    createSound(POWERUP_PATH);
}

/**
 * It clears the window, deserializes the packets received, and draws the entities
 */
void Game::run() noexcept
{
    {
        std::lock_guard<std::mutex> lock(mutexForPacket_);
        while (!dataReceived_.empty()) {
            auto& packet = dataReceived_.front();
            updateOrCreateEntity(packet);
            dataReceived_.pop();
        }
    }
    destroyableSystem_.run();
    drawableSystem_.run();
    soundSystem_.run();
    musicSystem_.run();
}

/**
 * This function returns a reference to the Lib object that is stored in the Game
 * object.
 *
 * @return A reference to the lib_ object.
 */
Lib& Game::getLib() noexcept
{
    return lib_;
}

/**
 * It deserializes a packet and creates an entity if it doesn't exist, or updates
 * it if it does
 *
 * @param packet the packet received from the server
 */
void Game::updateOrCreateEntity(GamePacket packet) noexcept
{
    auto m_entity = manager_.getEntity(static_cast<size_t>(packet.id));

    if (m_entity == nullptr) {
        auto entity = manager_.newEntity(packet.id);

        auto transform = TransformComponent(packet.x, packet.y);

        auto drawable = DrawableComponent(packet.offsetX, packet.offsetY, packet.width, packet.height, packet.idSprite);
        drawable.setScale(packet.scaleX, packet.scaleY);
        drawable.getSprite().setSpritePath("assets/img/r-typesheet" + std::to_string(packet.idSprite) + ".gif");
        drawable.getSprite().setX(packet.x);
        drawable.getSprite().setY(packet.y);

        entity->addComponent(transform);
        entity->addComponent(drawable);
        entity->addComponent(DestroyableComponent(packet.destroyed));
    } else {
        auto transform = m_entity->getComponent<TransformComponent>();
        auto drawable  = m_entity->getComponent<DrawableComponent>();
        auto destroy   = m_entity->getComponent<DestroyableComponent>();

        if (transform == nullptr || drawable == nullptr || destroy == nullptr) { return; }

        transform->setX(packet.x);
        transform->setY(packet.y);
        drawable->setScale(packet.scaleX, packet.scaleY);
        drawable->setOffsetX(packet.offsetX);
        drawable->setOffsetY(packet.offsetY);
        drawable->setWidth(packet.width);
        drawable->setHeight(packet.height);

        if (packet.idSprite != drawable->getTextureId()) {
            drawable->getSprite().setSpritePath("assets/img/r-typesheet" + std::to_string(packet.idSprite) + ".gif");
            drawable->setTextureId(packet.idSprite);
        }

        if (packet.destroyed) destroy->destroy();
    }
}

/**
 * It creates a new entity, adds a sound component to it, and returns the entity's ID
 *
 * @param path The path to the sound file.
 *
 * @return The id of the entity.
 */
int Game::createSound(const std::string_view& path) noexcept
{
    auto sound = manager_.newEntity();

    sound->addComponent(SoundComponent(soundManager_.getBufferFromPath(path)));

    return sound->getId();
}

/**
 * It returns a reference to our entities manager
 */
EntityManager& Game::getManager() noexcept
{
    return manager_;
}