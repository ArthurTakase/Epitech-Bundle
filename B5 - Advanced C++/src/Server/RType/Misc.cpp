#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/SoundComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TimerComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Server/RType.hpp>
#include <Tools/Curve.hpp>
#include <iostream>

/**
 * It creates a background entity with a transform, drawable, mouvement,
 * destroyable and behavior component
 *
 * @param x the x position of the background
 *
 * @return The id of the entity created.
 */
int RType::createBackground(int x) noexcept
{
    auto background = entityManager_.newEntity();

    background->addComponent(TransformComponent(x, 0));
    background->addComponent(DrawableComponent(0, 0, 255, 255, 0));
    background->addComponent(MouvementComponent(-1, 0, 2.0));
    background->addComponent(DestroyableComponent());

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= -255) { transform->setX(255); }
    }});

    background->addComponent(behaviorComponent);

    return background->getId();
}

/**
 * It creates a power up entity
 *
 * @param x The x position of the powerup
 * @param y The y position of the powerup
 * @param type 0 = heal, 1 = upgrade
 *
 * @return The id of the entity created.
 */
int RType::createPowerUp(int x, int y, int type) noexcept
{
    auto             powerUp = entityManager_.newEntity();
    std::vector<int> sprites = {1, 9};

    if (type != 0 && type != 1) { return -1; }

    powerUp->addComponent(TransformComponent(x, y));
    powerUp->addComponent(DrawableComponent(0, 0, 16, 16, sprites[type]));
    powerUp->addComponent(MouvementComponent(-1, 0, 1.0));
    powerUp->addComponent(DestroyableComponent());
    powerUp->addComponent(AnimationComponent(128, 0.1));

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[this, y](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();

        if (trans->getX() <= 0) { dest->destroy(); }
    }});
    powerUp->addComponent(behaviorComponent);

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[this, type](Entity* entity, Entity* me) {
        if (!entity->hasComponents<StatComponent, InputComponent>()) return;

        auto powerUp = me->getComponent<DrawableComponent>();
        auto player  = entity->getComponent<StatComponent>();
        auto dest    = me->getComponent<DestroyableComponent>();
        auto spr     = entity->getComponent<DrawableComponent>();

        if (type == 0) { // HEAL THE PLAYER
            if (player->getStat(RTypeStats::Life) < 100) {
                playSound(RTypeSounds::HEAL_SOUND);
                player->setStat(RTypeStats::Life, player->getStat(RTypeStats::Life) + 20);
            }
        } else if (type == 1) { // UPGRADE THE PLAYER
            playSound(RTypeSounds::POWERUP_SOUND);
            player->setStat(RTypeStats::Level, player->getStat(RTypeStats::Level) + 1);
            int level = static_cast<int>(player->getStat(RTypeStats::Level));
            if (level % 5 == 0 && level <= 10.0) { spr->setTextureId(spr->getTextureId() + 10); }
        }
        dest->destroy();
    }});
    powerUp->addComponent(hitbox);

    return powerUp->getId();
}

/**
 * It creates a random power up entity
 *
 * @param x The x position of the powerup
 * @param y The y position of the powerup
 *
 * @return The id of the entity created.
 */
int RType::createRandomPowerUp(int x, int y) noexcept
{
    int type = rand() % 2;
    return createPowerUp(x, y, type);
}

/**
 * It creates a new entity, adds a SoundComponent to it, and returns the entity's ID
 *
 * @param path The path to the sound file.
 *
 * @return The id of the entity.
 */
int RType::createSound() noexcept
{
    auto sound = entityManager_.newEntity();

    sound->addComponent(SoundComponent());

    return sound->getId();
}
