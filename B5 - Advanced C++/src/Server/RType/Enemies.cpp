#include <ECS/Components/AnimationComponent.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/StatComponent.hpp>
#include <ECS/Components/TimerComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Server/RType.hpp>
#include <Tools/Curve.hpp>

/**
 * It creates an enemy entity with a drawable component, an animation component, a
 * transform component, a destroyable component, a stat component, a mouvement
 * component, a timer component, a hitbox component, a behavior component and
 * returns the id of the entity
 *
 * @param x x position of the enemy
 * @param y the y position of the enemy
 *
 * @return The id of the entity created
 */
int RType::createBasicEnemy(int x, int y) noexcept
{
    auto enemy = entityManager_.newEntity();
    nbEnemyAlive += 1;

    enemy->addComponent(DrawableComponent(0, 0, 16, 16, BASIC_ENEMY_ID_SPRITE));
    enemy->addComponent(AnimationComponent(128, 0.1));
    enemy->addComponent(TransformComponent(x, y));
    enemy->addComponent(StatComponent({30, 2, 6, 1}));
    enemy->addComponent(MouvementComponent(-1, 0, 2.0));
    enemy->addComponent(TimerComponent(0.8));

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(
        std::function<void(Entity * entity, Entity * me)>{[](Entity* entity, Entity* me) { return; }});
    enemy->addComponent(hitbox);

    auto dest = DestroyableComponent();
    dest.setOnDestroy(std::function<void(Entity * entity)>{[this](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        if (rand() % 6 == 0) { createPowerUp(trans->getX(), trans->getY(), rand() % 2); }
        nbEnemyAlive -= 1;
        playerLevel += 1;
        playSound(RTypeSounds::EXPLOSION_SOUND);
    }});
    enemy->addComponent(dest);

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[this](Entity* entity) {
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();

        auto x = trans->getX();
        if (timer.isOver()) {
            auto bDamage = stat->getStat(RTypeStats::Damage);
            auto bSpeed  = stat->getStat(RTypeStats::Speed);
            auto bSize   = stat->getStat(RTypeStats::Size);
            createEnemyBullet(x, trans->getY(), bDamage, bSpeed, bSize, rand() % 2 == 0);
        }
        if (stat->getStat(RTypeStats::Life) <= 0) { dest->destroy(); }
        if (x <= -16) { trans->setX(255); }
    }});
    enemy->addComponent(behavior);

    return enemy->getId();
}

/**
 * It creates an enemy that moves in a curve and shoots bullets
 *
 * @param x x position of the enemy
 * @param y the y position of the enemy
 *
 * @return The id of the entity created
 */
int RType::createCurvedEnemy(int x, int y) noexcept
{
    auto enemy = entityManager_.newEntity();
    nbEnemyAlive += 1;

    enemy->addComponent(DrawableComponent(0, 0, 16, 16, CURVE_ENEMY_ID_SPRITE));
    enemy->addComponent(AnimationComponent(128, 0.1));
    enemy->addComponent(TransformComponent(x, y));
    enemy->addComponent(StatComponent({50, 4, 6, 1}));
    enemy->addComponent(MouvementComponent(-1, 0, 2.0));
    enemy->addComponent(TimerComponent(0.8));
    enemy->addComponent(HitboxComponent(16, 16));

    auto dest = DestroyableComponent();
    dest.setOnDestroy(std::function<void(Entity * entity)>{[this](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        if (rand() % 4 == 0) { createPowerUp(trans->getX(), trans->getY(), rand() % 2); }
        nbEnemyAlive -= 1;
        playerLevel += 1;
        playSound(RTypeSounds::EXPLOSION_SOUND);
    }});
    enemy->addComponent(dest);

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[this, y](Entity* entity) {
        auto  dest  = entity->getComponent<DestroyableComponent>();
        auto  stat  = entity->getComponent<StatComponent>();
        auto  trans = entity->getComponent<TransformComponent>();
        auto& timer = entity->getComponent<TimerComponent>()->getTimer();

        auto x = trans->getX();
        trans->setY(y - (Tools::curve(20, 0.05, x)));

        if (timer.isOver()) {
            auto bDamage = stat->getStat(RTypeStats::Damage);
            auto bSpeed  = stat->getStat(RTypeStats::Speed);
            auto bSize   = stat->getStat(RTypeStats::Size);
            createEnemyBullet(x, trans->getY(), bDamage, bSpeed, bSize, rand() % 2 == 0);
        }
        if (stat->getStat(RTypeStats::Life) <= 0) { dest->destroy(); }
        if (x <= -16) { trans->setX(255); }
    }});

    enemy->addComponent(behavior);

    return enemy->getId();
}

/**
 * It creates an entity with a transform, a mouvement, a drawable, an animation, a
 * destroyable, a stat, a hitbox, a behavior and returns the entity's id
 *
 * @param x the x position of the bullet
 * @param y the y position of the bullet
 * @param damage the damage the bullet will deal to the player
 * @param speed the speed of the bullet
 * @param size the size of the bullet
 * @param type false = not destroyable, true = destroyable
 *
 * @return The id of the entity
 */
int RType::createEnemyBullet(int x, int y, float damage, float speed, float size, bool type) noexcept
{
    auto  bullet = entityManager_.newEntity();
    float life   = type ? 1.0 : 200.0;

    playSound(RTypeSounds::MENU_SOUND);

    bullet->addComponent(TransformComponent(x - 8, y + 4));
    bullet->addComponent(MouvementComponent(-1, 0, speed));
    bullet->addComponent(DrawableComponent(0, 0, 8, 8, type ? 6 : 5, size, size));
    bullet->addComponent(AnimationComponent(16, 0.1));
    bullet->addComponent(DestroyableComponent());
    bullet->addComponent(StatComponent({life, damage}));

    auto hitbox = HitboxComponent(8, 8);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent, InputComponent>()) {
            auto stat   = entity->getComponent<StatComponent>();
            auto statMe = me->getComponent<StatComponent>();
            auto destMe = me->getComponent<DestroyableComponent>();

            playSound(RTypeSounds::HURT_SOUND);

            auto life = stat->getStat(RTypeStats::Life);
            auto dmg  = statMe->getStat(RTypeStats::Damage);
            stat->setStat(RTypeStats::Life, life - dmg);
            destMe->destroy();
        }
    }});

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto dest  = entity->getComponent<DestroyableComponent>();
        auto stat  = entity->getComponent<StatComponent>();

        if (trans->getX() <= 0 || stat->getStat(RTypeStats::Life) <= 0) { dest->destroy(); }
    }});

    bullet->addComponent(hitbox);
    bullet->addComponent(behavior);

    return bullet->getId();
}
