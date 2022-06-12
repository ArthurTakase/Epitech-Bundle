/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Ncurses
*/

#include "SFML.hpp"

/**
 * @brief Retourne un objet SFML.
 * Extern "C" pour l'ouvrir facilement depuis un dlsym
 *
 */
extern "C" std::shared_ptr<ILibrary> createLib()
{
    return std::make_shared<SFML>();
}

/**
 * @brief Construct a new SFML::SFML object
 *
 */
SFML::SFML() : name("lib/arcade_sfml.so"), currentMusic("")
{
    music = std::make_unique<sf::Music>();
}

/**
 * @brief Destroy the SFML::SFML object
 *
 */
SFML::~SFML()
{
    cleanSound();
    // this->window.setActive(false);
    deleteWindow();
}

/**
 * @brief Création d'une fenetre de jeu
 *
 * @return bool Echec/réussite de la création
 */
bool SFML::createWindow() noexcept
{
    auto mode = sf::VideoMode(1470, 840);
    window.create(mode, "Arcade [SFML]");
    // window.setFramerateLimit(15);

    font.loadFromFile("assets/fonts/visitor.ttf");
    return true;
}

/**
 * @brief Destruction d'une fenetre de jeu
 *
 */
void SFML::deleteWindow() noexcept
{
    window.close();
}

/**
 * @brief Récupère la touche appuyée sous forme d'Arcade::Key
 *
 * @return Arcade::Key
 */
Arcade::Key SFML::getInput() noexcept
{
    sf::Event event;

    if (!window.pollEvent(event)) return Arcade::NONE;
    if (event.type == sf::Event::Closed) return Arcade::QUIT_EVENT;
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Down: return Arcade::Key::DOWN;
        case sf::Keyboard::Up: return Arcade::Key::UP;
        case sf::Keyboard::Left: return Arcade::Key::LEFT;
        case sf::Keyboard::Right: return Arcade::Key::RIGHT;
        case sf::Keyboard::Escape: return Arcade::Key::QUIT_EVENT;
        case sf::Keyboard::C: return Arcade::Key::PREVIOUS_LIB;
        case sf::Keyboard::V: return Arcade::Key::NEXT_LIB;
        case sf::Keyboard::Space: return Arcade::Key::POWER;
        case sf::Keyboard::F: return Arcade::Key::POWER2;
        case sf::Keyboard::B: return Arcade::Key::PREVIOUS_GAME;
        case sf::Keyboard::N: return Arcade::Key::NEXT_GAME;
        case sf::Keyboard::Return: return Arcade::Key::SWITCH_STATE;
        case sf::Keyboard::X: return Arcade::Key::ADVANCED;
        case sf::Keyboard::R: return Arcade::Key::RESTART;
        default: return Arcade::Key::NONE;
        }
    }
    return Arcade::Key::NONE;
}

/**
 * @brief Supprime tous les élément à l'écran avant d'afficher la couleur donnée en paramêtre
 *
 * @param color Couleur de fond (non utilisée par Ncurses)
 */
void SFML::clearLib(const Arcade::Color &color) noexcept
{
    sf::Color colors[] = { sf::Color::Red,
                           sf::Color::Green,
                           sf::Color::Blue,
                           sf::Color::Black,
                           sf::Color::White,
                           sf::Color(163, 129, 67, 255),
                           sf::Color(255, 0, 255, 25),
                           sf::Color(0, 255, 255, 255) };

    window.clear(colors[color]);
}

/**
 * @brief Actualise l'affichage de la lib
 *
 */
void SFML::refreshLib() noexcept
{
    window.display();
}

/**
 * @brief Affiche le Text donné en parametre
 *
 * @param txt {str, color, x, y, underline}
 */
void SFML::putText(const Text &txt) noexcept
{
    sf::Color colors[] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Black, sf::Color::White };

    sf::Text text(txt.str, font);

    text.setCharacterSize(32);
    text.setPosition(txt.x * 21, (txt.y * 21) - 15);

    text.setFillColor(colors[txt.color]);

    if (txt.underline) {
        sf::RectangleShape underline(sf::Vector2f((txt.str.length() / 3 + txt.str.length() / 3) * 21, 1));
        underline.setPosition(txt.x * 21, (txt.y + 1) * 21 - 2);
        underline.setFillColor(colors[txt.color]);
        window.draw(underline);
    }

    window.draw(text);
}

/**
 * @brief Affiche le Sprite donné en parametre
 *
 * @param sprite {filePath, color, x, y}
 */
void SFML::putSprite(const Sprite &sprite)
{
    sf::Texture texture;
    sf::Sprite  tempSprite;

    texture.loadFromFile(sprite.spritePath);
    tempSprite.setTexture(texture);
    tempSprite.setPosition(sprite.x * 21, sprite.y * 21);

    window.draw(tempSprite);
}

/**
 * @brief Getter pour name
 *
 * @return std::string
 */
std::string SFML::getName() const noexcept
{
    return name;
}

void SFML::playSound(const std::string &sound) noexcept
{
    if (sound.empty()) return;
    if (sound == currentMusic) return;
    currentMusic = sound;

    music->openFromFile(currentMusic);
    music->setLoop(true);
    music->setVolume(100);
    music->play();
}

void SFML::cleanSound() noexcept
{
    music->stop();
}