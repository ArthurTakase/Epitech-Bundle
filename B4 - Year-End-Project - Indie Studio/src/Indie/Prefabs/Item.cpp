/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Item
*/

#include "Item.hpp"

#include <memory>

#include "Bomberman.hpp"
#include "BoxCollider.hpp"
#include "Error.hpp"
#include "InstanceOf.hpp"
#include "Player.hpp"
#include "Render.hpp"
#include "Transform3D.hpp"
#include "Vector.hpp"

/**
 * It creates an item, sets its position, its model, its hitbox, and plays a sound
 *
 * @param pos The position of the item.
 * @param data The GameData object that contains all the game data.
 */
Item::Item(Vector3D pos, GameData& data)
    : Entity()
    , data(data)
    , itemType(static_cast<bomberman::ItemType>(static_cast<int>(rand() % 4)))
    , getItemSound(GET_ITEM)
    , newItemSound(NEW_ITEM)
{
    addComponent(Transform3D());
    addComponent(Render(findItemModel()));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the item element.\n"));

    transform->get().setPosition(pos);
    transform->get().setScale(1.0f);
    transform->get().setRotationAxis({ 1.0f, 0.0f, 0.0f });
    transform->get().setRotationAngle(90.0f);
    renderer->get().setRenderType(RenderType::R_3DMODEL_ROTATE);

    addComponent(BoxCollider(transform->get().getPosition(), { 1.0f, 1.0f, 0.5f }, true));
    auto hitbox = getComponent<BoxCollider>();

    if (!hitbox.has_value()) throw(Error("Error, could not instanciate the item element.\n"));
    hitbox->get().setIsSolid(false);
    transform->get().addZ((transform->get().getScale() / 2) * -1);
    transform->get().addY((transform->get().getScale() / 2));

    hitbox->get().addZ(transform->get().getScale() / 10);
    hitbox->get().addY(transform->get().getScale() / 10);
    hitbox->get().update(hitbox->get().getPosition());

    newItemSound.play();
}

/**
 * It creates an item, sets its position, scale, rotation, and render type, and adds a box collider
 * to it
 *
 * @param data The game data, which contains the map and the players.
 * @param type The type of item to be created.
 */
Item::Item(GameData& data, bomberman::ItemType type)
    : Entity()
    , data(data)
    , itemType(type)
    , getItemSound(GET_ITEM)
    , newItemSound(NEW_ITEM)

{
    addComponent(Transform3D());
    addComponent(Render(findItemModel()));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the item element.\n"));

    transform->get().setPosition(findFreePosition());
    transform->get().setScale(1.0f);
    transform->get().setRotationAxis({ 1.0f, 0.0f, 0.0f });
    transform->get().setRotationAngle(90.0f);
    renderer->get().setRenderType(RenderType::R_3DMODEL_ROTATE);

    Vector3D scale = { 1.0f, 1.0f, 0.5f };
    addComponent(BoxCollider(transform->get().getPosition(), scale, true));
    auto hitbox = getComponent<BoxCollider>();

    if (!hitbox.has_value()) throw(Error("Error, could not instanciate the item element.\n"));
    hitbox->get().setIsSolid(false);
    transform->get().addZ((transform->get().getScale() / 2) * -1);
    transform->get().addY((transform->get().getScale() / 2));

    hitbox->get().addZ(transform->get().getScale() / 10);
    hitbox->get().addY(transform->get().getScale() / 10);
    hitbox->get().update(hitbox->get().getPosition());
    newItemSound.play();
}

/**
 * It creates an item, sets its position, scale, rotation, and render type, and adds a box collider
 * to it
 *
 * @param data The game data, which contains the map and the players.
 * @param type The type of item to be created.
 * @param pos The position of the item.
 */
Item::Item(GameData& data, bomberman::ItemType type, Vector3D pos)
    : Entity()
    , data(data)
    , itemType(type)
    , getItemSound(GET_ITEM)
    , newItemSound(NEW_ITEM)

{
    addComponent(Transform3D());
    addComponent(Render(findItemModel()));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the item element.\n"));

    transform->get().setPosition(pos);
    transform->get().setScale(1.0f);
    transform->get().setRotationAxis({ 1.0f, 0.0f, 0.0f });
    transform->get().setRotationAngle(90.0f);
    renderer->get().setRenderType(RenderType::R_3DMODEL_ROTATE);

    Vector3D scale = { 1.0f, 1.0f, 0.5f };
    addComponent(BoxCollider(transform->get().getPosition(), scale, true));
    auto hitbox = getComponent<BoxCollider>();

    if (!hitbox.has_value()) throw(Error("Error, could not instanciate the item element.\n"));
    hitbox->get().setIsSolid(false);
    transform->get().addZ((transform->get().getScale() / 2) * -1);
    transform->get().addY((transform->get().getScale() / 2));

    hitbox->get().addZ(transform->get().getScale() / 10);
    hitbox->get().addY(transform->get().getScale() / 10);
    hitbox->get().update(hitbox->get().getPosition());
    newItemSound.play();
}

/**
 * It returns a reference to the model of the item
 *
 * @return A reference to a Model3D object.
 */
Model3D& Item::findItemModel() const noexcept
{
    const auto& model = data.getModels();

    switch (itemType) {
        case bomberman::ItemType::I_SPEEDUP:
            return (*model.at(static_cast<int>(bomberman::ModelType::M_IROLLER)));
        case bomberman::ItemType::I_BOMBUP:
            return (*model.at(static_cast<int>(bomberman::ModelType::M_IBOMB)));
        case bomberman::ItemType::I_FIREUP:
            return (*model.at(static_cast<int>(bomberman::ModelType::M_IFIRE)));
        case bomberman::ItemType::I_WALL:
        default: return (*model.at(static_cast<int>(bomberman::ModelType::M_IWALL)));
    }
}

/**
 * This function does nothing.
 */
void Item::Update() {}

/**
 * If the player collides with the item, the item will set the player's stats, add the item to the
 * player's inventory, play the sound effect, and destroy itself
 *
 * @param other The entity that collided with this entity.
 */
void Item::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept
{
    if (Type:: instanceof <Player>(other.get())) {
        setPlayerStat((std::unique_ptr<Player>&)other);
        ((std::unique_ptr<Player>&)other)->addItem(itemType);
        getItemSound.play();
        destroy();
    }
}

/**
 * It sets the player's stats according to the item's type
 *
 * @param p The player who picked up the item.
 */
void Item::setPlayerStat(std::unique_ptr<Player>& p) noexcept
{
    switch (itemType) {
        case bomberman::ItemType::I_SPEEDUP:
            if (p->getSpeed() < p->getSpeedMax()) p->setSpeed(p->getSpeed() + 0.2f);
            break;
        case bomberman::ItemType::I_BOMBUP:
            if (p->getNbBomb() < p->getNbBombMax()) p->setNbBomb(p->getNbBomb() + 1);
            break;
        case bomberman::ItemType::I_FIREUP:
            if (p->getBombSize() < p->getBombSizeMax()) p->setBombSize(p->getBombSize() + 1);
            break;
        case bomberman::ItemType::I_WALL: p->setWallPass(true); break;
        default: break;
    }
}

/**
 * It finds a random position on the map that is not occupied by any other entity
 *
 * @return A Vector3D
 */
Vector3D Item::findFreePosition(void) const noexcept
{
    Vector3D pos;
    int      x;
    int      z;

    do {
        x   = rand() % 12 - 6;
        z   = rand() % 12 - 5;
        pos = { x * 1.0f, 0.25f, z * 1.0f };
    } while (entitiesHere(pos));

    return (pos);
}

/**
 * If there is an entity at the given position, return true
 *
 * @param pos The position of the entity
 *
 * @return A boolean value.
 */
bool Item::entitiesHere(Vector3D& pos) const noexcept
{
    for (auto& entity : data.getEntities()) {
        auto transform    = entity->getComponent<Transform3D>();
        auto other_hitbox = entity->getComponent<BoxCollider>();
        if (!transform.has_value()) continue;
        auto posTemp = transform->get().getPosition();

        const BoxCollider hitbox =
            BoxCollider({ posTemp.x, posTemp.y, posTemp.z }, { 0.5f, 0.5f, 0.5f }, true);
        if (!other_hitbox || !other_hitbox.has_value()) continue;
        if (!hitbox.getIsSolid() || !other_hitbox->get().getIsSolid()) continue;
        if (other_hitbox->get().isColliding(hitbox, pos)) return true;
    }
    return false;
}

void Item::setType(const bomberman::ItemType& type) noexcept
{
    itemType = type;
}

bomberman::ItemType Item::getType() const noexcept
{
    return itemType;
}
