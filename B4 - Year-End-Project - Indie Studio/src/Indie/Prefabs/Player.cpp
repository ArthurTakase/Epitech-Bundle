/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Player
*/

#include "Player.hpp"

#include <iostream>
#include <optional>
#include <vector>

#include "AI.hpp"
#include "Bomb.hpp"
#include "Controller.hpp"
#include "Crate.hpp"
#include "DeltaTime.hpp"
#include "Error.hpp"
#include "Fire.hpp"
#include "Game.hpp"
#include "InstanceOf.hpp"
#include "Item.hpp"
#include "Transform3D.hpp"
#include "Vector.hpp"
#include "Wall.hpp"
#include "raylib.h"

/**
 * It creates a player
 *
 * @param newId The id of the player.
 * @param data The game data, which contains all the models, textures, sounds, etc.
 */
Player::Player(int newId, GameData& data)
    : Entity()
    , id(newId)
    , data(data)
    , wallpass(false)
    , wallpassTimer(5.0f)
    , wallpassEnd(false)
    , isBot(false)
    , killSound_(KILL)
{
    addComponent(Transform3D());
    addComponent(Render(
        *data.getModels()[static_cast<typename std::underlying_type<bomberman::ModelType>::type>(
                              bomberman::ModelType::M_PLAYER_1)
                          + id]));
    addComponent(AI());
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the player element.\n"));
    transform->get().setPosition({ 0.0f, 0.25f, 2.0f });
    transform->get().setRotationAxis({ 0.0f, 1.0f, 0.0f });
    transform->get().setScale(0.65f);
    renderer->get().setRenderType(RenderType::R_ANIMATE);
    renderer->get().getAnimation().addAnimation("assets/models/player.iqm");
    setKeyboard();
    setPosition();
    setPlayerType(PlayerType::NORMAL);
    addComponent(BoxCollider(transform->get().getPosition(), { 0.5f, 0.5f, 0.5f }, true));
}

/**
 * "If the current type is not the first type,
 * decrement the type, otherwise set the type to the last type."
 *
 * @return The new type of the player.
 */
int Player::findPrevType() const noexcept
{
    auto new_type = static_cast<typename std::underlying_type<PlayerType>::type>(type);
    if (new_type > 0) {
        new_type--;
    } else
        new_type =
            static_cast<typename std::underlying_type<PlayerType>::type>(PlayerType::__size__) - 1;
    return (new_type);
}

/**
 * It returns the next player type in the enum
 *
 * @return The next type of player.
 */
int Player::findNextType() const noexcept
{
    auto new_type = static_cast<typename std::underlying_type<PlayerType>::type>(type);
    if (new_type
        < (static_cast<typename std::underlying_type<PlayerType>::type>(PlayerType::__size__)
            - 1)) {
        new_type++;
    } else
        new_type = 0;
    return (new_type);
}

/**
 * If the player is a bot, then handle the bot's movement, otherwise handle the player's movement
 *
 * @return The player's hitbox.
 */
void Player::Update()
{
    auto hitbox    = getComponent<BoxCollider>();
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!hitbox.has_value() || !transform.has_value() || !renderer.has_value())
        throw(Error("Error in updating the player element.\n"));

    if (!renderer->get().isShow()) return;

    hitbox->get().update(transform->get().getPosition());

    if (wallpass) {
        wallpassTimer.updateTimer();
        if (wallpassTimer.isTimerDone()) {
            wallpass    = false;
            wallpassEnd = true;
            wallpassTimer.resetTimer();
        }
    }
    if (wallpass || wallpassEnd) {
        renderer->get().setColor(colors[colorIndex]);
        colorIndex = (colorIndex + 1) % colors.size();
    }
    if (isBot) {
        handleAutoMovement();
    } else {
        handlePlayerMovement();
    }
}

/**
 * It returns a vector of Vector3D's that represent the positions of all the crates and walls in the
 * game
 *
 * @return A vector of Vector3D
 */
std::vector<Vector3D> Player::getSurroundingBox()
{
    std::vector<Vector3D> result;

    for (auto& other : data.getEntities()) {
        if ((Type:: instanceof <Crate>(other.get()) || Type:: instanceof <Wall>(other.get()))
            && other.get()->getEnabledValue()) {
            result.push_back(other.get()->getComponent<Transform3D>()->get().getPosition());
        }
    }
    return (result);
}

/**
 * It returns a vector of Vector3D, which contains the positions of all the bombs in the game
 *
 * @return A vector of Vector3D
 */
std::vector<Vector3D> Player::getBombsPositions()
{
    std::vector<Vector3D> result;

    for (auto& other : data.getEntities()) {
        if (Type:: instanceof <Bomb>(other.get()) && other.get()->getEnabledValue()) {
            result.push_back(other.get()->getComponent<Transform3D>()->get().getPosition());
        }
    }
    return (result);
}

/**
 * It returns a vector of Vector3D objects, which are the positions of all the fires in the game
 *
 * @return A vector of Vector3D
 */
std::vector<Vector3D> Player::getFirePositions()
{
    std::vector<Vector3D> result;

    for (auto& other : data.getEntities()) {
        if (Type:: instanceof <Fire>(other.get()) && other.get()->getEnabledValue()) {
            result.push_back(other.get()->getComponent<Transform3D>()->get().getPosition());
        }
    }
    return (result);
}

std::vector<Vector3D> Player::getPowerupPositions()
{
    std::vector<Vector3D> result;

    for (auto& other : data.getEntities()) {
        if (Type:: instanceof <Item>(other.get()) && other.get()->getEnabledValue()) {
            result.push_back(other.get()->getComponent<Transform3D>()->get().getPosition());
        }
    }
    return (result);
}

std::vector<Vector3D> Player::getPlayersPositions()
{
    std::vector<Vector3D> result;

    for (auto& other : data.getEntities()) {
        if (Type::
                instanceof <Player>(other.get()) && other.get()->getEnabledValue()
                               && other.get() != this) {
            result.push_back(other.get()->getComponent<Transform3D>()->get().getPosition());
        }
    }
    return (result);
}

/**
 * It handles the AI movements
 */
void Player::handleAutoMovement()
{
    auto    transform          = getComponent<Transform3D>();
    auto    renderer           = getComponent<Render>();
    auto    ai                 = getComponent<AI>();
    bool    animate            = false;
    AIEvent event              = AIEvent::NONE;
    int     collision_distance = 4;

    if (!ai.has_value() || !transform.has_value() || !renderer.has_value())
        throw(Error("Error in handling the AI movements.\n"));

    Vector2D position = { transform->get().getPositionX(), transform->get().getPositionZ() };
    std::vector<Vector3D> boxes    = getSurroundingBox();
    std::vector<Vector3D> bombs    = getBombsPositions();
    std::vector<Vector3D> fires    = getFirePositions();
    std::vector<Vector3D> players  = getPlayersPositions();
    std::vector<Vector3D> powerups = getPowerupPositions();
    event = ai->get().getEvent(position, boxes, bombs, fires, players, powerups, nbBomb);
    if (event != AIEvent::NONE) {
        animate = true;
        if (event == AIEvent::MOVE_UP && !isCollidingNextTurn(0, -collision_distance)) {
            transform->get().setRotationAngle(270.0f);
            transform->get().moveZ(-speed);
        }
        if (event == AIEvent::MOVE_DOWN && !isCollidingNextTurn(0, collision_distance)) {
            transform->get().setRotationAngle(90.0f);
            transform->get().moveZ(speed);
        }
        if (event == AIEvent::MOVE_LEFT && !isCollidingNextTurn(-collision_distance, 0)) {
            transform->get().setRotationAngle(0.0f);
            transform->get().moveX(-speed);
        }
        if (event == AIEvent::MOVE_RIGHT && !isCollidingNextTurn(collision_distance, 0)) {
            transform->get().setRotationAngle(180.0f);
            transform->get().moveX(speed);
        }
        if (event == AIEvent::PLACE_BOMB) placeBomb();
        if (event == AIEvent::MOVE_UP && isCollidingNextTurn(0, -collision_distance)
            || event == AIEvent::MOVE_DOWN && isCollidingNextTurn(0, collision_distance)
            || event == AIEvent::MOVE_LEFT && isCollidingNextTurn(-collision_distance, 0)
            || event == AIEvent::MOVE_RIGHT && isCollidingNextTurn(collision_distance, 0)) {
            ai->get().handleColliding();
        }
    }

    if (!animate) {
        renderer->get().getAnimation().setSkipFrame(1);
        renderer->get().getAnimation().setAnimationId(1);
    } else {
        renderer->get().getAnimation().setSkipFrame(2);
        renderer->get().getAnimation().setAnimationId(0);
    }
}

/**
 * It handles the player's movement and animation
 */
void Player::handlePlayerMovement()
{
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();
    bool animate   = false;

    if (!transform.has_value() || !renderer.has_value())
        throw Error("Error while handling the player inputs.\n");

    if (controller.isGamepadConnected(id)) {
        // Mouvements au joystick
        float axisX = controller.getGamepadAxis(id, Axis::G_AXIS_LEFT_X);
        float axisY = controller.getGamepadAxis(id, Axis::G_AXIS_LEFT_Y);

        if (axisX != 0 || axisY != 0) animate = true;
        if (axisY < -0.5f && !isCollidingNextTurn(0, -1)) {
            transform->get().setRotationAngle(270.0f);
            transform->get().moveZ(-speed);
        }
        if (axisY > 0.5f && !isCollidingNextTurn(0, 1)) {
            transform->get().setRotationAngle(90.0f);
            transform->get().moveZ(speed);
        }
        if (axisX < -0.5f && !isCollidingNextTurn(-1, 0)) {
            transform->get().setRotationAngle(0.0f);
            transform->get().moveX(-speed);
        }
        if (axisX > 0.5f && !isCollidingNextTurn(1, 0)) {
            transform->get().setRotationAngle(180.0f);
            transform->get().moveX(speed);
        }
        if (controller.isGamepadButtonPressed(id, G_Button::G_B)) placeBomb();
    } else {
        // Mouvements au clavier
        if (controller.isKeyDown(moveUp) || controller.isKeyDown(moveDown)
            || controller.isKeyDown(moveLeft) || controller.isKeyDown(moveRight))
            animate = true;
        if (controller.isKeyDown(moveUp) && !isCollidingNextTurn(0, -1)) {
            transform->get().setRotationAngle(270.0f);
            transform->get().moveZ(-speed);
        }
        if (controller.isKeyDown(moveDown) && !isCollidingNextTurn(0, 1)) {
            transform->get().setRotationAngle(90.0f);
            transform->get().moveZ(speed);
        }
        if (controller.isKeyDown(moveLeft) && !isCollidingNextTurn(-1, 0)) {
            transform->get().setRotationAngle(0.0f);
            transform->get().moveX(-speed);
        }
        if (controller.isKeyDown(moveRight) && !isCollidingNextTurn(1, 0)) {
            transform->get().setRotationAngle(180.0f);
            transform->get().moveX(speed);
        }
        if (controller.isKeyPressed(dropBomb)) placeBomb();
    }

    if (!animate) {
        renderer->get().getAnimation().setSkipFrame(1);
        renderer->get().getAnimation().setAnimationId(1);
    } else {
        renderer->get().getAnimation().setSkipFrame(2);
        renderer->get().getAnimation().setAnimationId(0);
    }
}

/**
 * This function returns the type of the player.
 *
 * @return The type of the player.
 */
PlayerType Player::getType() const noexcept
{
    return (type);
}

/**
 * This function returns the value of the private member variable isBot.
 *
 * @return isBot
 */
bool Player::getBotState() const noexcept
{
    return isBot;
}

/**
 * If the player collides with a wall or fire, play a sound, dispatch an item, and hide the player
 *
 * @param other The entity that collided with this entity.
 */
void Player::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept
{
    auto render = getComponent<Render>();
    if (!render.has_value()) return;
    if (!render->get().isShow()) return;
    if (Type:: instanceof <Wall>(other.get()) && wallpass || Type::
            instanceof <Wall>(other.get()) && wallpassEnd) {
        printf("in first\n");
        return;
    }
    if (Type:: instanceof <Wall>(other.get()) || Type:: instanceof <Fire>(other.get())) {
        printf("in second\n");
        killSound_.play();
        dispatchItem();
        auto render = getComponent<Render>();
        if (render.has_value()) { render->get().show(false); }
    }
}

/**
 * It sets the player's position based on the player's id
 */
void Player::setPosition()
{
    auto transform = getComponent<Transform3D>();
    if (!transform.has_value()) throw(Error("Error in setting player position.\n"));

    transform->get().setRotationAngle(direction[id]);
    switch (id) {
        case 0:
            transform->get().setX(-6.0f);
            transform->get().setZ(-4.0f);
            break;
        case 1:
            transform->get().setX(6.0f);
            transform->get().setZ(6.0f);

            break;
        case 2:
            transform->get().setX(6.0f);
            transform->get().setZ(-4.0f);
            break;
        case 3:
            transform->get().setX(-6.0f);
            transform->get().setZ(6.0f);
            break;
        default: break;
    }
}

/**
 * It sets the player's position to the given position
 *
 * @param pos The position to set the player to.
 */
void Player::setPosition(Vector3D pos)
{
    auto transform = getComponent<Transform3D>();
    if (!transform.has_value()) throw(Error("Error in setting player position.\n"));

    transform->get().setRotationAngle(direction[id]);
    transform->get().setX(pos.x);
    transform->get().setY(pos.y);
    transform->get().setZ(pos.z);
}

/**
 * It sets the keyboard keys for each player
 */
void Player::setKeyboard() noexcept
{
    switch (id) {
        case 0:
            moveUp    = Key::K_W;
            moveDown  = Key::K_S;
            moveLeft  = Key::K_A;
            moveRight = Key::K_D;
            dropBomb  = Key::K_Q;
            break;
        case 1:
            moveUp    = Key::K_KP_8;
            moveDown  = Key::K_KP_5;
            moveLeft  = Key::K_KP_4;
            moveRight = Key::K_KP_6;
            dropBomb  = Key::K_KP_7;
            break;
        case 2:
            moveUp    = Key::K_T;
            moveDown  = Key::K_G;
            moveLeft  = Key::K_F;
            moveRight = Key::K_H;
            dropBomb  = Key::K_R;
            break;
        case 3:
            moveUp    = Key::K_I;
            moveDown  = Key::K_K;
            moveLeft  = Key::K_J;
            moveRight = Key::K_L;
            dropBomb  = Key::K_U;
            break;
        default: break;
    }
}

/**
 * It checks if the player is colliding with any other entity next turn
 *
 * @param xdir The direction of the player on the x axis.
 * @param zdir The direction the player is moving in the z axis.
 *
 * @return A boolean value.
 */
bool Player::isCollidingNextTurn(int xdir, int zdir)
{
    auto hitbox    = getComponent<BoxCollider>();
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();
    if (!transform.has_value() || !renderer.has_value() || !hitbox.has_value())
        throw(Error("Error in updating the collision of the player.\n"));

    Vector3D position = transform->get().getPosition();
    Vector3D nextTurn = { position.x + (speed * xdir * DeltaTime::getDeltaTime()),
        position.y,
        position.z + (speed * zdir * DeltaTime::getDeltaTime()) };

    if (!getEnabledValue()) return false;
    for (auto& other : data.getEntities()) {
        if (hitbox == std::nullopt || other->getComponent<BoxCollider>() == std::nullopt) continue;
        auto other_hitbox = other->getComponent<BoxCollider>();
        if (other_hitbox.has_value()) {
            if (!hitbox->get().getIsSolid() || !other_hitbox->get().getIsSolid()) continue;
            if (other_hitbox->get().isColliding(hitbox->get(), nextTurn)) {
                if (Type:: instanceof <Bomb>(other.get())) return true;
                if (Type:: instanceof <Wall>(other.get())) return true;
                if (Type:: instanceof <Crate>(other.get())) {
                    if (wallpass) return false;
                    if (!wallpass && wallpassEnd) return false;
                    return true;
                }
            }
        }
    }
    if (wallpassEnd) {
        wallpassEnd = false;
        renderer->get().setColor(Colors::C_WHITE);
    }
    return false;
}

/**
 * It checks if the player can place a bomb, and if so, it places one
 *
 * @return A reference to the data member.
 */
void Player::placeBomb()
{
    auto transform = getComponent<Transform3D>();
    if (!transform.has_value()) throw(Error("Error in updating the placement of bombs.\n"));
    for (auto& i : data.getEntities()) {
        auto bomb = i->getComponent<Transform3D>();
        if (bomb.has_value()
            && bomb->get().getPosition().x == round(transform->get().getPosition().x)
            && bomb->get().getPosition().z == round(transform->get().getPosition().z))
            return;
    }
    if (nbBomb <= 0) return;
    nbBomb--;
    data.addBomb(transform->get().getPosition(), *this, bombSize);
}

/**
 * It sets the wallpass variable to the value of the pass parameter, and resets the wallpassTimer
 *
 * @param pass The new value for the wallpass variable.
 */
void Player::setWallPass(const bool& pass) noexcept
{
    this->wallpassTimer.resetTimer();
    wallpass = pass;
}

/**
 * This function returns the value of the wallpass variable.
 *
 * @return A boolean value.
 */
bool Player::getWallPass() const noexcept
{
    return wallpass;
}

/**
 * This function returns the value of the private member variable wallpassEnd.
 *
 * @return The wallpassEnd variable is being returned.
 */
bool Player::getWallPassEnd() const noexcept
{
    return wallpassEnd;
}

/**
 * It adds an item to the player's inventory
 *
 * @param itemType The type of item to add to the player.
 */
void Player::addItem(bomberman::ItemType itemType) noexcept
{
    items.emplace_back(itemType);
}

/**
 * It toggles the isBot variable
 */
void Player::toggleBot() noexcept
{
    isBot = !isBot;
}

void Player::setIsBot(const bool& val) noexcept
{
    isBot = val;
}

bool Player::isPlayer() const noexcept
{
    return !isBot;
}

/**
 * If the player has any items, add them to the player's data and clear the items vector
 *
 * @return A reference to the player's data.
 */
void Player::dispatchItem() noexcept
{
    if (items.empty()) return;
    for (auto& item : items) {
        if (item == bomberman::ItemType::I_WALL) { continue; }
        data.addItem(item);
    }
    items.clear();
}

/**
 * It sets the player's type, and sets the player's stats according to the type
 *
 * @param type The type of the player.
 */
void Player::setPlayerType(PlayerType type) noexcept
{
    this->type = type;
    switch (type) {
        case PlayerType::NORMAL:
            nbBomb      = 1;
            speed       = 2.0f;
            bombSize    = 3;
            nbBombMax   = 6;
            speedMax    = 3.5f;
            bombSizeMax = 6;
            break;
        case PlayerType::ATTACK:
            nbBomb      = 1;
            speed       = 1.5f;
            bombSize    = 4;
            nbBombMax   = 10;
            speedMax    = 2.2f;
            bombSizeMax = 10;
            break;
        case PlayerType::TACTICAL:
            nbBomb      = 2;
            speed       = 2.0f;
            bombSize    = 2;
            nbBombMax   = 5;
            speedMax    = 3.0f;
            bombSizeMax = 7;
            break;
        case PlayerType::RUNNER:
            nbBomb      = 1;
            speed       = 2.5f;
            bombSize    = 2;
            nbBombMax   = 3;
            speedMax    = 5.0f;
            bombSizeMax = 5;
            break;
        default: break;
    }
}

/**
 * GetNbBombMax returns the number of bombs the player can place.
 *
 * @return The number of bombs the player can place.
 */
int Player::getNbBombMax() const noexcept
{
    return nbBombMax;
}

/**
 * This function returns the maximum speed of the player.
 *
 * @return The maximum speed of the player.
 */
float Player::getSpeedMax() const noexcept
{
    return speedMax;
}

/**
 * This function returns the maximum size of the bombs that the player can place.
 *
 * @return The maximum size of the bomb.
 */
int Player::getBombSizeMax() const noexcept
{
    return bombSizeMax;
}

/**
 * This function returns the speed of the player.
 *
 * @return The speed of the player.
 */
float Player::getSpeed() const noexcept
{
    return speed;
}

/**
 * GetNbBomb returns the number of bombs the player has
 *
 * @return The number of bombs the player has.
 */
int Player::getNbBomb() const noexcept
{
    return nbBomb;
}

/**
 * This function returns the size of the bomb.
 *
 * @return The size of the bomb.
 */
int Player::getBombSize() const noexcept
{
    return bombSize;
}

/**
 * This function sets the speed of the player.
 *
 * @param speed The speed of the player.
 */
void Player::setSpeed(const float& speed) noexcept
{
    this->speed = speed;
}

/**
 * SetNbBomb sets the number of bombs the player can place
 *
 * @param nbBomb The number of bombs the player can place.
 */
void Player::setNbBomb(const int& nbBomb) noexcept
{
    this->nbBomb = nbBomb;
}

/**
 * This function sets the bomb size of the player.
 *
 * @param bombSize The size of the bomb.
 */
void Player::setBombSize(const int& bombSize) noexcept
{
    this->bombSize = bombSize;
}

/**
 * Returns the type of player.
 *
 * @return The type of the player.
 */
PlayerType Player::getPlayerType() const noexcept
{
    return type;
}

/**
 * This function returns the player's id.
 *
 * @return The id of the player.
 */
int Player::getId() const noexcept
{
    return id;
}
