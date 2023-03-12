/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Menu.cpp
*/

#include <Client/Menu.hpp>
#include <ECS/Components/BehaviorComponent.hpp>
#include <ECS/Components/DestroyableComponent.hpp>
#include <ECS/Components/DrawableComponent.hpp>
#include <ECS/Components/MouvementComponent.hpp>
#include <ECS/Components/MusicComponent.hpp>
#include <ECS/Components/TextComponent.hpp>
#include <ECS/Components/TransformComponent.hpp>
#include <Error/Error.hpp>
#include <Lib/Sound.hpp>
#include <NetworkLib/HostHandler.hpp>
#include <Tools/Keyboard.hpp>

/**
 * It creates a Menu object, which will then later be used to handle our menu of the game.
 */
Menu::Menu()
    : drawableSystem_(&manager_)
    , destroyableSystem_(&manager_)
    , behaviorSystem_(&manager_)
    , mouvementSystem_(&manager_)
    , musicSystem_(&manager_)
    , soundSystem_(&manager_)
{
    soundSystem_.setSoundManager(&soundManager_);

    for (auto& path : soundPaths_) { soundManager_.addSoundBuffer(path); }
    menuSound = createSound(MENU_PATH);
    hurtSound = createSound(HURT_PATH);
}

/**
 * It creates the title menu, then runs the systems until the user enters all the necessary infos to connect to the
 * server and play the game
 *
 * @param window the window in which the menu will be displayed
 *
 * @return The address of the server
 */
Address Menu::run(Window& window)
{
    createBackground(0);
    createBackground(MAX_VALUE);
    createTitleMenu(window);
    createMusic(BG_MUSIC_PATH);

    drawableSystem_.setWindow(&window);
    Address serverInfos;

    while (isOpen_) {
        destroyableSystem_.run();
        drawableSystem_.run();
        behaviorSystem_.run();
        mouvementSystem_.run();
        musicSystem_.run();
        soundSystem_.run();
    }

    manager_.getEntities().clear();
    serverInfos.port = std::atoi(port_.c_str());
    if (serverInfos.port <= 0) throw Error("Port must be a positive number");
    serverInfos.ip = HostHandler::getIp(ip_.c_str());
    if (serverInfos.ip <= 0) throw Error("No server found with this IP address");

    return serverInfos;
}

/**
 * It returns the value of the private member variable isOpen_. When called, it allows to our program to know if the
 * menu is still open or not.
 *
 * @return A boolean value.
 */
bool Menu::getIsOpen() const noexcept
{
    return isOpen_;
}

/**
 * It creates a new entity with a music component
 *
 * @param path The path to the music file.
 */
void Menu::createMusic(const std::string_view& path) noexcept
{
    auto music = manager_.newEntity();

    music->addComponent(MusicComponent(path.data()));
}

/**
 * It creates a new text entity with a drawable, transform, destroyable, and text
 * component
 *
 * @param posX The x position of the text
 * @param posY The y position of the text
 * @param size The size of the text.
 * @param message The text to be displayed
 *
 * @return The id of the entity.
 */
int Menu::createText(int posX, int posY, int size, const std::string_view& message) noexcept
{
    auto text = manager_.newEntity();

    text->addComponent(DrawableComponent());
    text->addComponent(TransformComponent(posX, posY));
    text->addComponent(DestroyableComponent());

    auto textComponent = TextComponent(message.data(), FONT_PATH.data(), size, posX, posY);
    text->addComponent(textComponent);

    return text->getId();
}

/**
 * It creates a background entity
 *
 * @param posX the x position of the background
 *
 * @return The id of the entity.
 */
int Menu::createBackground(int posX) noexcept
{
    auto background = manager_.newEntity();

    background->addComponent(TransformComponent(posX, 0));
    background->addComponent(MouvementComponent(-1, 0, 1.0));
    background->addComponent(DestroyableComponent());

    auto behaviorComponent = BehaviorComponent();
    behaviorComponent.setOnUpdate(std::function<void(Entity * entity)>{[](Entity* entity) {
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getX() <= MIN_VALUE) { transform->setX(MAX_VALUE); }
    }});

    auto  drawable = DrawableComponent(0, 0, MAX_VALUE, MAX_VALUE, 0);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath(BACKGROUND_PATH.data());

    background->addComponent(drawable);
    background->addComponent(behaviorComponent);

    return background->getId();
}

/**
 * It creates a menu with a title and a button to press to go to the next menu
 *
 * @param window The window to draw on
 *
 * @return The id of the entity.
 */
int Menu::createTitleMenu(Window& window) noexcept
{
    int t1 = createText(65, 125, 10, "@lefeudecamps");
    int t2 = createText(35, 180, 10, "Press Enter to Play");
    int t3 = createText(45, 200, 10, "Press D for hints");

    auto menu = manager_.newEntity();

    const std::vector<std::string> hints = {
        "Use WASD or ZQSD\nto move",
        "Press Shift to\nstop moving",
        "Use the arrow keys\nto shoot",
        "Collect blue stars\nfor upgrades",
        "Collect green stars\nto heal",
        "Kill all your\nopponents to win",
        "Press Enter once\nconnected and ready",
        "Press Escape to\nleave the game",
        "You can play with\nup to 4 players",
    };

    menu->addComponent(MouvementComponent(0, 1, 1));
    menu->addComponent(TransformComponent(20, 00));
    menu->addComponent(DestroyableComponent());

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, t1, t2, t3, hints](Entity* entity) {
        int                              input     = window.getKeyPressed();
        static std::vector<std::string*> txt       = {&ip_, &port_};
        static int                       hintIndex = -1;

        if (input == Input::Exit) {
            for (auto& t : txt) *t = "";
            isOpen_ = false;
        }
        if (input == Input::Return) {
            createIPMenu(window);
            entity->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t1)->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t2)->getComponent<DestroyableComponent>()->destroy();
            manager_.getEntity(t3)->getComponent<DestroyableComponent>()->destroy();
            playSound(menuSound);
        }
        if (input == Input::D) {
            hintIndex = (hintIndex + 1) % hints.size();
            manager_.getEntity(t3)->getComponent<TextComponent>()->getText().setTextString(hints[hintIndex]);
            playSound(menuSound);
        }

        auto mouvement = entity->getComponent<MouvementComponent>();
        auto transform = entity->getComponent<TransformComponent>();

        if (transform->getY() >= 30) mouvement->setDirY(0);
    }});

    auto  drawable = DrawableComponent(0, 0, 226, 97, 7);
    auto& sprite   = drawable.getSprite();
    sprite.setSpritePath(TITLE_PATH.data());

    menu->addComponent(behavior);
    menu->addComponent(drawable);

    return menu->getId();
}

/**
 * It creates a page that allows the user to input an IP address and a port number
 *
 * @param window The window to get the input from.
 *
 * @return The id of the entity that was created.
 */
int Menu::createIPMenu(Window& window) noexcept
{
    createText(55, 10, 15, "Connect to");
    createText(10, 60, 15, "Server IP:");
    createText(10, 120, 15, "Server Port:");
    int t1 = createText(10, 80, 15, "...");
    int t2 = createText(10, 140, 15, "...");

    auto menu = manager_.newEntity();

    auto behavior = BehaviorComponent();
    behavior.setOnUpdate(std::function<void(Entity * entity)>{[&, t1, t2](Entity* entity) {
        int                              input  = window.getKeyPressed();
        static std::vector<std::string*> txt    = {&ip_, &port_};
        static int                       i      = 0;
        static std::vector<int>          allTxt = {t1, t2};

        if (input == Input::Exit) {
            for (auto& t : txt) *t = "";
            isOpen_ = false;
        }
        if (input >= Input::Zero && input <= Input::Nine) {
            *txt[i] += std::to_string(input - Input::Zero);
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
            playSound(menuSound);
        }
        if (input == Input::Dot) {
            *txt[i] += ".";
            manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
            playSound(menuSound);
        }
        if (input == Input::Return) {
            if (txt[i]->length() > 1) i++;
            if (i >= MAX_INDEX) isOpen_ = false;
            playSound(menuSound);
        }
        if (input == Input::BackSpace) {
            if (txt[i]->length() > 0) {
                txt[i]->erase(txt[i]->length() - 1, 1);
                manager_.getEntity(allTxt[i])->getComponent<TextComponent>()->getText().setTextString(*txt[i]);
                playSound(hurtSound);
            }
        }
    }});

    menu->addComponent(behavior);

    return menu->getId();
}

/**
 * It creates an entity containing a sound component
 *
 * @return The id of the entity that has the SoundComponent
 */
int Menu::createSound(const std::string_view& path) noexcept
{
    auto sound = manager_.newEntity();

    sound->addComponent(SoundComponent(soundManager_.getBufferFromPath(path)));

    return sound->getId();
}

/**
 * It plays a sound
 *
 * @param id The id of the entity that has the SoundComponent
 */
void Menu::playSound(int id) noexcept
{
    auto sound = manager_.getEntity(id);
    sound->getComponent<SoundComponent>()->setPlayed(true);
}
