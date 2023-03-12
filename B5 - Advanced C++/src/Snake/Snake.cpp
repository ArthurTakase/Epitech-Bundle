/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** SnakeGame.cpp
*/

#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/HitboxComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TimerComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Snake.hpp>
#include <Tools/Keyboard.hpp>

/**
 * It creates a new snake game object class and initializes the game systems
 */
SnakeGame::SnakeGame()
    : entityManager_()
    , drawableSystem_(&entityManager_)
    , behaviorSystem_(&entityManager_)
    , hitboxSystem_(&entityManager_)
    , mouvementSystem_(&entityManager_)
    , destroyableSystem_(&entityManager_)
{
    lib_.getWindow().open(256, 256, "Snake");
    drawableSystem_.setWindow(&lib_.getWindow());
}

/**
 * It creates a fruit entity, which is a destroyable entity with a hitbox and a
 * drawable component
 *
 * @return The id of the fruit entity
 */
int SnakeGame::fruit() noexcept
{
    auto fruit = entityManager_.newEntity();

    fruit->addComponent(TransformComponent(rand() % 239, rand() % 239));
    fruit->addComponent(DestroyableComponent());

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (!entity->hasComponent<MouvementComponent>()) return;

        auto transform = entity->getComponent<TransformComponent>();

        int wX = rand() % 239;
        int wY = rand() % 239;
        while (wX - 8 > transform->getX() && wX + 8 < transform->getX() && wY - 8 > transform->getY()
               && wY + 8 < transform->getY()) {
            wX = rand() % 239;
            wY = rand() % 239;
        }
        wall(wX, wY);

        auto mePos = me->getComponent<TransformComponent>();
        mePos->setX(rand() % 239);
        mePos->setY(rand() % 239);

        score_ += 1;
        auto score = entityManager_.getEntity(scoreId_)->getComponent<TextComponent>();
        score->getText().setTextString(std::to_string(score_));
    }});
    fruit->addComponent(hitbox);

    auto drawable = DrawableComponent(0, 0, 16, 16, -1, 1, 1);
    drawable.getSprite().setSpritePath("assets/snake/fruit.gif");
    fruit->addComponent(drawable);

    return fruit->getId();
}

/**
 * It creates a wall entity, which is a 16x16 sprite that will be destroyed after
 * 60 frames
 *
 * @param x the x position of the wall
 * @param y the y position of the wall
 *
 * @return The id of the entity.
 */
int SnakeGame::wall(int x, int y) noexcept
{
    auto wall = entityManager_.newEntity();

    wall->addComponent(TransformComponent(x, y));
    wall->addComponent(TimerComponent(60));
    wall->addComponent(DestroyableComponent());

    auto hitbox = HitboxComponent(16, 16);
    hitbox.setOnCollision(std::function<void(Entity * entity, Entity * me)>{[&](Entity* entity, Entity* me) {
        if (entity->hasComponent<MouvementComponent>()) { stop(); }
    }});
    wall->addComponent(hitbox);

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto  t     = entity->getComponent<TimerComponent>();
        auto& timer = t->getTimer();

        if (timer.isOver()) {
            auto dest = entity->getComponent<DestroyableComponent>();
            dest->destroy();
        }
    }});
    wall->addComponent(behavior);

    auto drawable = DrawableComponent(0, 0, 16, 16, -1, 1, 1);
    drawable.getSprite().setSpritePath("assets/snake/wall.gif");
    wall->addComponent(drawable);

    return wall->getId();
}

/**
 * It creates a new entity, adds a bunch of components to it, and returns the
 * entity's id
 *
 * @return The id of the entity that was created.
 */
int SnakeGame::player() noexcept
{
    auto part = entityManager_.newEntity();

    part->addComponent(TransformComponent(rand() % 247, rand() % 247));
    part->addComponent(HitboxComponent(8, 8));
    part->addComponent(MouvementComponent(0, 0, 4.0));
    part->addComponent(DestroyableComponent());

    auto drawable = DrawableComponent(0, 0, 8, 8, -1, 2, 2);
    drawable.getSprite().setSpritePath("assets/snake/snake.gif");
    part->addComponent(drawable);

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&](Entity* entity) {
        auto mouv  = entity->getComponent<MouvementComponent>();
        auto trans = entity->getComponent<TransformComponent>();
        int  input = lib_.getWindow().getKeyPressed();
        if (input == Input::Exit) { running_ = false; }

        if (input == Input::Up) { mouv->setDir(0, -1); }
        if (input == Input::Down) { mouv->setDir(0, 1); }
        if (input == Input::Left) { mouv->setDir(-1, 0); }
        if (input == Input::Right) { mouv->setDir(1, 0); }

        if (trans->getX() < 0 || trans->getX() > 256 || trans->getY() < 0 || trans->getY() > 256) stop();
    }});
    part->addComponent(behavior);

    return part->getId();
}

/**
 * It creates a new entity, adds a few components to it, and returns the entity's
 * ID
 *
 * @param size The size of the text
 * @param posX The x position of the text
 * @param posY The y position of the text
 *
 * @return The id of the entity that was created.
 */
int SnakeGame::score(int size, int posX, int posY) noexcept
{
    auto text = entityManager_.newEntity();

    text->addComponent(DrawableComponent());
    text->addComponent(TransformComponent(posX, posY));
    text->addComponent(DestroyableComponent());

    auto textComponent = TextComponent("0", "assets/fonts/gameboy.ttf", size, posX, posY);
    text->addComponent(textComponent);

    return text->getId();
}

/**
 * It runs the game
 */
int SnakeGame::run() noexcept
{
    player();
    fruit();
    scoreId_ = score(10, 2, 2);

    auto& window = lib_.getWindow();

    while (window.isOpen() && running_) {
        destroyableSystem_.run();
        drawableSystem_.run();
        behaviorSystem_.run();
        hitboxSystem_.run();
        mouvementSystem_.run();
    }
    return 0;
}

/**
 * It stops the game
 */
void SnakeGame::stop() noexcept
{
    running_ = false;
}

/**
 * "The main function creates a SnakeGame object and calls its run function."
 *
 * The run function is the heart of the game. It's where the game loop is located.
 * The game loop is a while loop that runs until the game is over
 *
 * @return The return value of the run() function.
 */
int main()
{
    SnakeGame game;

    return game.run();
}