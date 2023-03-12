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

/**
 * It creates an asteroid entity with a random position, speed and scale
 *
 * @param x the x position of the asteroid
 *
 * @return The id of the entity
 */
int RType::createAsteroid(int x) noexcept
{
    auto asteroid = entityManager_.newEntity();

    int   y     = (rand() % 239);
    float speed = static_cast<float>(rand() % 25) / 10 + 2;
    float scale = static_cast<float>(rand() % 20) / 10 + 1;

    asteroid->addComponent(TransformComponent(x, y));
    asteroid->addComponent(AnimationComponent(128, 0.1));
    asteroid->addComponent(MouvementComponent(-1, 0, speed));
    asteroid->addComponent(DestroyableComponent());
    asteroid->addComponent(StatComponent({25 * scale, 4 * scale}));

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[this](Entity* entity) {
        auto trans = entity->getComponent<TransformComponent>();
        auto stat  = entity->getComponent<StatComponent>();
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto draw  = entity->getComponent<DrawableComponent>();

        if (stat->getStat(RTypeStats::Life) <= 0) {
            if (rand() % 8 == 0) { createPowerUp(trans->getX(), trans->getY(), rand() % 2); }
            playSound(RTypeSounds::EXPLOSION_SOUND);
        }

        if (trans->getX() <= -16 || stat->getStat(RTypeStats::Life) <= 0) {
            float behaviorScale = static_cast<float>(rand() % 20) / 10 + 1;
            float behaviorSpeed = static_cast<float>(rand() % 25) / 10 + 2;

            mouv->setSpeed(behaviorSpeed);
            trans->setX(255);
            trans->setY((rand() % 239));
            stat->setStat(RTypeStats::Life, 25 * behaviorScale);
            draw->setScale(behaviorScale, behaviorScale);
        }
    }});

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setScale(scale, scale);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[this](Entity* entity, Entity* me) {
        if (entity->hasComponents<DestroyableComponent, HitboxComponent, StatComponent, InputComponent>()) {
            auto otherStat = entity->getComponent<StatComponent>();
            auto meStat    = me->getComponent<StatComponent>();
            auto meTrans   = me->getComponent<TransformComponent>();
            auto meMouv    = me->getComponent<MouvementComponent>();
            auto meDraw    = me->getComponent<DrawableComponent>();

            auto life   = otherStat->getStat(RTypeStats::Life);
            auto damage = meStat->getStat(RTypeStats::Damage);
            otherStat->setStat(RTypeStats::Life, life - damage);

            float hitboxScale = static_cast<float>(rand() % 20) / 10 + 1;
            float hitboxSpeed = static_cast<float>(rand() % 25) / 10 + 5;

            playSound(RTypeSounds::HURT_SOUND);

            meMouv->setSpeed(hitboxSpeed);
            meTrans->setX(255);
            meTrans->setY((rand() % 239));
            meStat->setStat(RTypeStats::Life, 25 * hitboxScale);
            meDraw->setScale(hitboxScale, hitboxScale);
        }
    }});

    auto draw = DrawableComponent(0, 0, 16, 16, 4);
    draw.setScale(scale, scale);

    asteroid->addComponent(behavior);
    asteroid->addComponent(draw);
    asteroid->addComponent(hitbox);

    return asteroid->getId();
}
