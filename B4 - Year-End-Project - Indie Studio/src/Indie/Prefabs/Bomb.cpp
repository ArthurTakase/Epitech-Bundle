/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Bomb
*/

#include "Bomb.hpp"

#include "DeltaTime.hpp"
#include "Error.hpp"
#include "InstanceOf.hpp"
#include "Wall.hpp"

/**
 * It creates a bomb at the given position, with the given size, and the given player
 *
 * @param pos the position of the bomb
 * @param p The player who dropped the bomb
 * @param newModel The model of the bomb
 * @param bombSize the size of the bomb, which is the number of blocks it will destroy
 * @param data The GameData object, which contains all the data needed for the game.
 */
Bomb::Bomb(Vector3D pos, Player& p, Model3D& newModel, int bombSize, GameData& data)
    : Entity()
    , lifeTime(3.0f)
    , lifeTimer(lifeTime)
    , player(p)
    , size(bombSize)
    , hasHitbox(false)
    , data(data)
    , is_exploding_(false)
    , animeDir(1)
    , dropSound_(DROP_BOMB)
    , explodeSound(EXPLODE)
{
    addComponent(Transform3D());
    addComponent(Render(newModel));
    auto transform = getComponent<Transform3D>();
    auto renderer  = getComponent<Render>();

    if (!transform.has_value() || !renderer.has_value())
        throw(Error("Error, could not instanciate the bomb element.\n"));

    transform->get().setScale(0.07f);
    transform->get().setPosition(
        { round(pos.x), 0.0f - transform->get().getScale(), round(pos.z) });
    renderer->get().setRenderType(RenderType::R_3DMODEL);

    addComponent(BoxCollider(transform->get().getPosition(), { 0.8f, 1.2f, 0.8f }, false));

    explodeSound.setVolume(1.0f);
    dropSound_.play();
}

/**
 * It updates the bomb's timer, checks if it's time to explode, checks if it's time to become solid,
 * and animates the bomb
 *
 * @return A pointer to the bomb object.
 */
void Bomb::Update()
{
    int  i         = 0;
    auto hitbox    = getComponent<BoxCollider>();
    auto transform = getComponent<Transform3D>();
    if (!hitbox.has_value() || !transform.has_value())
        throw(Error("Error in updating a bomb element.\n"));

    lifeTimer.updateTimer();
    if (lifeTimer.isTimerDone()) {
        explode();
        return;
    }
    if (fires.size() == 0 && !hitbox->get().getIsSolid()) {
        if (data.getNbPlayers() <= 0) return;

        for (auto& other : data.getPlayers()) {
            if (!(other->getComponent<BoxCollider>().has_value())) continue;
            auto other_collider = other->getComponent<BoxCollider>();
            if (!hitbox->get().isColliding(other_collider->get())) i++;
        }
        if (i == static_cast<int>(data.getNbPlayers())) hitbox->get().setIsSolid(true);
    }

    transform->get().setScale(
        transform->get().getScale() + (0.1f * DeltaTime::getDeltaTime() * animeDir));
    if (transform->get().getScale() > 0.09f || transform->get().getScale() < 0.07f) animeDir *= -1;
}

/**
 * It creates the fire and destroys the bomb
 *
 * @return A reference to the fire vector.
 */
void Bomb::explode() noexcept
{
    auto hitbox = getComponent<BoxCollider>();

    explodeSound.play();

    if (is_exploding_) return;
    is_exploding_ = true;
    hitbox->get().setIsSolid(false);
    if (player.getNbBombMax() > player.getNbBomb()) player.setNbBomb(player.getNbBomb() + 1);
    fires.emplace_back(std::make_unique<Fire>(getComponent<Transform3D>()->get().getPosition(),
        *(data.getModels()[static_cast<int>(bomberman::ModelType::M_FIRE)])));
    createFire({ 1.0f, 0.0f, 0.0f });
    createFire({ -1.0f, 0.0f, 0.0f });
    createFire({ 0.0f, 0.0f, 1.0f });
    createFire({ 0.0f, 0.0f, -1.0f });

    for (auto& fire : fires) { data.addFire(std::move(fire)); }
    destroy();
}

/**
 * It creates a fire at the position of the bomb, and then checks if the fire is colliding with any
 * other entity. If it is, it calls the `ExplodeElements` function of the fire, which will destroy
 * the entity if it's destructible
 *
 * @param mul The direction of the fire.
 */
void Bomb::createFire(Vector3D mul) noexcept
{
    Vector3D position = getComponent<Transform3D>()->get().getPosition();
    Vector3D newPos;
    bool     exit = false;

    for (int i = 1; i < size && !exit; i++) {
        newPos.x = position.x + (float(i) * mul.x);
        newPos.y = position.y + (float(i) * mul.y);
        newPos.z = position.z + (float(i) * mul.z);
        fires.emplace_back(std::make_unique<Fire>(
            newPos, *(data.getModels()[static_cast<int>(bomberman::ModelType::M_FIRE)])));
        auto& fire = fires.back();
        for (auto& other : data.getEntities()) {
            auto collider      = fire->getComponent<BoxCollider>();
            auto other_collide = other->getComponent<BoxCollider>();
            if (collider->get().isColliding(other_collide->get()))
                if ((exit = fire->ExplodeElements(other))) break;
        }
    }
}

/**
 * If the bomb collides with a wall, explode
 *
 * @param other The entity that collided with this entity.
 */
void Bomb::OnCollisionEnter(std::unique_ptr<Entity>& other) noexcept
{
    if (Type:: instanceof <Wall>(other.get())) explode();
}

/**
 * Get the life time of the bomb.
 *
 * @return The lifeTime variable is being returned.
 */
int Bomb::getLifeTime() const noexcept
{
    return lifeTime;
}

/**
 * Sets the life time of the bomb.
 *
 * @param newLifeTime The new life time of the bomb.
 */
void Bomb::setLifeTime(const int& newLifeTime) noexcept
{
    lifeTime = newLifeTime;
}

/**
 * Returns the id of the player who owns this bomb.
 *
 * @return The id of the player who owns the bomb.
 */
int Bomb::getOwnerId() const noexcept
{
    return player.getId();
}
