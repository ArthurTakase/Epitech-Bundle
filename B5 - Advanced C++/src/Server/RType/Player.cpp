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
#include <Tools/Keyboard.hpp>

/**
 * It creates a player entity and adds all the components it needs
 *
 * @param x the x position of the player
 * @param y y position
 * @param nb the player number
 *
 * @return The id of the player entity
 */
int RType::createPlayer(int x, int y, int nb) noexcept
{
    auto player = entityManager_.newEntity();

    player->addComponent(DrawableComponent(0, 0, 16, 16, 10 + nb));
    player->addComponent(AnimationComponent(128, 0.1));
    player->addComponent(TransformComponent(x, y));
    player->addComponent(StatComponent({100, 10, 10.0, 1.0, 1.0}));
    player->addComponent(MouvementComponent(0, 0, 5.0));
    player->addComponent(InputComponent());
    player->addComponent(DestroyableComponent());
    player->addComponent(TimerComponent(0.1));

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto  input = entity->getComponent<InputComponent>();
        auto  mouv  = entity->getComponent<MouvementComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();
        int   lastInput;
        auto  x = trans->getX();
        auto  y = trans->getY();

        while ((lastInput = input->getInput()) != -1) {
            if (!started && lastInput == Input::Return) {
                started = true;
                createAsteroid(260);
                createAsteroid(280);
                createAsteroid(300);
                createSpawner();
            }
            if (lastInput == Input::Q) { mouv->setDir(-1, 0); }
            if (lastInput == Input::D) { mouv->setDir(1, 0); }
            if (lastInput == Input::Z) { mouv->setDir(0, -1); }
            if (lastInput == Input::S) { mouv->setDir(0, 1); }
            if (lastInput == Input::Shift) { mouv->setDir(0, 0); }
            if (timer.isOver()) {
                if (lastInput == Input::Up) { playerShoot(x, y, 0, -1, stat); }
                if (lastInput == Input::Left) { playerShoot(x, y, -1, 0, stat); }
                if (lastInput == Input::Down) { playerShoot(x, y, 0, 1, stat); }
                if (lastInput == Input::Right) { playerShoot(x, y, 1, 0, stat); }
            }
            if (lastInput == Input::L) { entityManager_.log(); }
        }

        auto next_x = x + mouv->getDirX() * mouv->getSpeed();
        auto next_y = y + mouv->getDirY() * mouv->getSpeed();
        if (next_x >= 239 || next_x <= 0) mouv->setDirX(0);
        if (next_y >= 239 || next_y <= 0) mouv->setDirY(0);
        if (stat->getStat(RTypeStats::Life) <= 0) {
            playerShoot(x, y, 0, -1, stat);
            playerShoot(x, y, -1, 0, stat);
            playerShoot(x, y, 0, 1, stat);
            playerShoot(x, y, 1, 0, stat);

            playSound(RTypeSounds::EXPLOSION_SOUND);

            dest->destroy();
        }
    }});

    player->addComponent(hitbox);
    player->addComponent(behavior);

    return player->getId();
}

/**
 * It creates a bullet entity with the given parameters
 *
 * @param x The x position of the bullet
 * @param y y position of the player
 * @param dirX The direction of the bullet on the X axis.
 * @param dirY The direction of the bullet on the Y axis.
 * @param stat The player's stats
 */
void RType::playerShoot(int x, int y, int dirX, int dirY, StatComponent* stat) noexcept
{
    auto bulletDamage = stat->getStat(RTypeStats::Damage);
    auto bulletSpeed  = stat->getStat(RTypeStats::Speed);
    auto bulletSize   = stat->getStat(RTypeStats::Size);
    auto playerLevel  = stat->getStat(RTypeStats::Level);

    playSound(RTypeSounds::PIOU_SOUND);

    if (playerLevel < 5) {
        createPlayerBullet(x, y, bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
    } else if (playerLevel < 10) {
        createPlayerBullet(x - (4 * dirY), y - (4 * dirX), bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
        createPlayerBullet(x + (4 * dirY), y + (4 * dirX), bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
    } else {
        createPlayerBullet(x, y, bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
        createPlayerBullet(x - (8 * dirY), y - (8 * dirX), bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
        createPlayerBullet(x + (8 * dirY), y + (8 * dirX), bulletDamage, bulletSpeed, dirX, dirY, bulletSize);
    }
}

/**
 * It creates a bullet entity with a transform, a mouvement, a drawable, an
 * animation, a destroyable, a stat, a hitbox and a behavior component
 *
 * @param x The x position of the bullet
 * @param y the y position of the bullet
 * @param damage the damage the bullet will deal to the enemy
 * @param speed the speed of the bullet
 * @param dirX The direction of the bullet on the X axis.
 * @param dirY direction of the bullet on the Y axis
 * @param size the size of the bullet
 *
 * @return The id of the bullet
 */
int RType::createPlayerBullet(int x, int y, float damage, float speed, int dirX, int dirY, float size) noexcept
{
    auto bullet = entityManager_.newEntity();

    bullet->addComponent(TransformComponent(x, y));
    bullet->addComponent(MouvementComponent(dirX, dirY, speed));
    bullet->addComponent(DrawableComponent(0, 0, 16, 16, 3, size, size));
    bullet->addComponent(AnimationComponent(32, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent({1, damage}));

    auto hitbox         = HitboxComponent(16, 16);
    auto hitboxFunction = std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent>()
            && !entity->hasComponents<InputComponent>()) {
            auto stat   = entity->getComponent<StatComponent>();
            auto statMe = me->getComponent<StatComponent>();
            auto destMe = me->getComponent<DestroyableComponent>();
            auto life   = stat->getStat(RTypeStats::Life);
            auto dmg    = statMe->getStat(RTypeStats::Damage);
            auto draw   = entity->getComponent<DrawableComponent>();

            if (draw->getTextureId() == 3) { return; }

            stat->setStat(RTypeStats::Life, life - dmg);
            destMe->destroy();
        }
    }};
    hitbox.setOnCollision(hitboxFunction);

    auto behavior = BehaviorComponent();
    auto function = std::function<void(Entity * entity)>{[](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();

        auto x = trans->getX();
        auto y = trans->getY();
        if (x >= 255 || x <= -16 || y >= 255 || y <= -16) { dest->destroy(); }
    }};
    behavior.setOnUpdate(function);

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);

    return bullet->getId();
}
