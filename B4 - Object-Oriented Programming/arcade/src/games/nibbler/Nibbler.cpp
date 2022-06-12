/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief Retourne un objet Nibbler.
 * Extern "C" pour l'ouvrir facilement depuis un dlsym
 *
 */
extern "C" std::shared_ptr<IGame> createGame()
{
    return std::make_shared<Nibbler>();
}

/**
 * @brief Construct a new Nibbler:: Nibbler object
 *²
 */
Nibbler::Nibbler() : AGame("lib/arcade_nibbler.so", Arcade::Color::BLACK, "assets/sound/music.ogg")
{
    // Fruit
    fruit.color      = Arcade::Color::RED;
    fruit.spritePath = "assets/img/snake/fruit.png";

    reset();
}

/**
 * @brief Destroy the Nibbler:: Nibbler object
 *
 */
Nibbler::~Nibbler() noexcept
{
    snake.clear();
}

/**
 * @brief Récupère l'input de la Gameloop pour lancer les différentes actions du jeu
 *
 * @param input
 */
void Nibbler::handleInput(const Arcade::Key &input) noexcept
{
    switch (input) {
    case Arcade::Key::LEFT: updateDir(-1, 0); break;
    case Arcade::Key::RIGHT: updateDir(1, 0); break;
    case Arcade::Key::UP: updateDir(0, -1); break;
    case Arcade::Key::DOWN: updateDir(0, 1); break;
    case Arcade::Key::POWER: newFruit(); break;
    default: return;
    }
}

/**
 * @brief Renvoi un vecteur de Sprites contenant tous les éléments à afficher dans le jeu
 *ase(snake.begin());
        snake.em
 * @return std::vector<Sprite>
 */
std::vector<Sprite> Nibbler::getDisplay() noexcept
{
    std::vector<Sprite> sprites;

    getMapSprite(sprites);
    getSnakeSprite(sprites);

    return sprites;
}

void Nibbler::getMapSprite(std::vector<Sprite> &sprites) noexcept
{
    if (!map.empty()) map[0][0] = '#';
    for (int y = 0; y < (int)map.size(); y++)
        for (int x = 0; x < (int)map[y].size(); x++) {
            switch (map[y][x]) {
            case '#': sprites.emplace_back(Sprite("assets/img/snake/wall.png", Arcade::Color::BLUE, x, y)); break;
            case 'X': sprites.emplace_back(Sprite("assets/img/snake/wall_d.png", Arcade::Color::WHITE, x, y)); break;
            case 'F': sprites.emplace_back(Sprite("assets/img/snake/fruit.png", Arcade::Color::RED, x, y)); break;
            case ' ': sprites.emplace_back(Sprite("assets/img/snake/floor.png", Arcade::Color::BLACK, x, y)); break;
            default: break;
            }
        }
}

void Nibbler::getSnakeSprite(std::vector<Sprite> &sprites) noexcept
{
    for (size_t i = 0; i != snake.size(); i++) {
        if (i == snake.size() - 1) {
            snake[i].color = Arcade::Color::BROWN;
            if (xdir == -1 && ydir == 0) snake[i].spritePath = "assets/img/snake/head_l.png";
            if (xdir == 1 && ydir == 0) snake[i].spritePath = "assets/img/snake/head_r.png";
            if (xdir == 0 && ydir == -1) snake[i].spritePath = "assets/img/snake/head_u.png";
            if (xdir == 0 && ydir == 1) snake[i].spritePath = "assets/img/snake/head_d.png";
        }
        else {
            snake[i].spritePath = "assets/img/snake/snake.png";
            snake[i].color      = Arcade::Color::GREEN;
        }
        sprites.emplace_back(snake[i]);
    }
}

/**
 * @brief Mets à jour les informations du jeu
 *
 */
void Nibbler::update() noexcept
{
    auto head = snake.back();

    if (colNextTurn(head.x, head.y, xdir, ydir)) {
        xdir = 0;
        ydir = 0;
    }

    if (inMouvement()) {
        head.x += xdir;
        head.y += ydir;
        snake.erase(snake.begin());
        snake.emplace_back(head);
    }

    tryEat(head.x, head.y);

    this->state = endGame();
}

bool Nibbler::colNextTurn(const int &x, const int &y, const int &nxdir, const int &nydir) const noexcept
{
    int newx = x + nxdir;
    int newy = y + nydir;

    if (map.empty()) return false;
    if (newy >= 32 || newy < 0) return true;
    if (newx >= 40 || newx < 0) return true;
    return (map[newy][newx] == 'X');
}

bool Nibbler::inMouvement() const noexcept
{
    return (xdir != 0 || ydir != 0);
}

/**
 * @brief Check la collision entre la tête et le fruit et lance les actions necessaires si collision
 *
 * @param x Coordonnée X à vérifier
 * @param y Coordonnée Y à vérifier
 */
void Nibbler::tryEat(const int &x, const int &y) noexcept
{
    if (!map.empty() && map[y][x] == 'F') {
        score++;
        newFruit();
        addPartOfSnake();
    }
}

/**
 * @brief Check les conditions de fin d'une partie
 *
 * @return Arcade::GameState
 */
Arcade::GameState Nibbler::endGame() noexcept
{
    if (win()) return Arcade::GameState::WIN;
    if (loose()) return Arcade::GameState::LOOSE;

    return Arcade::GameState::PROGRESS;
}

bool Nibbler::win() noexcept
{
    return (nbSpace == len);
}

bool Nibbler::loose() noexcept
{
    int x    = snake.back().x;
    int y    = snake.back().y;
    int newx = x + xdir;
    int newy = y + ydir;

    if (newy > 31 || newy < 0 || newx > 39 || newx < 0) return true;
    if (!map.empty() && map[y][x] == '#') return true;

    for (int i = 0; i < (int)snake.size() - 1; i++)
        if (snake[i].x == x && snake[i].y == y) return true;
    return false;
}

/**
 * @brief Remise à 0 des options du jeu
 *
 */
void Nibbler::reset() noexcept
{
    std::string allMaps[3] = { "nibbler_1", "nibbler_2", "nibbler_3" };
    int         indexMap   = std::rand() / ((RAND_MAX + 1u) / 3);
    len                    = 4;
    state                  = Arcade::GameState::PROGRESS;
    xdir                   = 0;
    ydir                   = 0;
    score                  = 0;
    fruit.x                = 0;
    fruit.y                = 0;
    nbSpace                = 0;
    snake.clear();

    loadMap("assets/maps/" + allMaps[indexMap] + ".map");
    newFruit();

    snake.emplace_back(Sprite("assets/img/snake/snake.png", Arcade::Color::GREEN, 19, 15));
    snake.emplace_back(Sprite("assets/img/snake/snake.png", Arcade::Color::GREEN, 20, 15));
    snake.emplace_back(Sprite("assets/img/snake/snake.png", Arcade::Color::GREEN, 21, 15));
    snake.emplace_back(Sprite("assets/img/snake/head_r.png", Arcade::Color::GREEN, 22, 15));
}

/**
 * @brief Change la direction du serpent
 * (ne s'active pas si le serpent essaye d'aller dans un mur)
 *
 * @param xdir Direction horizontale (-1, 0, 1)
 * @param ydir Direction verticale (-1, 0, 1)
 */
void Nibbler::updateDir(const int &nxdir, const int &nydir) noexcept
{
    auto head = snake.back();

    if (goingReverse(nxdir, nydir)) return;
    if (colNextTurn(head.x, head.y, nxdir, nydir)) return;

    xdir = nxdir;
    ydir = nydir;
}

bool Nibbler::goingReverse(const int &nxdir, const int &nydir) noexcept
{
    return (nxdir == -xdir && nydir == -ydir);
}

/**
 * @brief Fait grandir le serpent d'une case par appel
 *
 */
void Nibbler::addPartOfSnake()
{
    int x = snake[0].x - xdir;
    int y = snake[0].y - ydir;

    len += 1;
    snake.insert(snake.begin(), Sprite("assets/img/snake/snake.png", Arcade::Color::GREEN, x, y));
}

/**
 * @brief Ouvre le fichier donné en param et charge un vector<vector<char>>
 * avec tous les éléments du fichier dans l'attribut map
 *
 * @param filePath fichier à charger
 */
void Nibbler::loadMap(std::string filePath)
{
    std::string   fileContent = "";
    std::ifstream myFile(filePath);

    map.clear();

    if (myFile.is_open()) fileContent = getFileContent(myFile);

    if (fileContent.size() < 1312) {
        myFile.close();
        return;
    }

    fillMap(fileContent);
    myFile.close();
}

std::string Nibbler::getFileContent(std::ifstream &myFile) noexcept
{
    char        mychar;
    std::string fileContent = "";

    while (myFile) {
        mychar = myFile.get();
        fileContent += mychar;
        if (mychar == ' ') nbSpace += 1;
    }
    return fileContent;
}

void Nibbler::fillMap(const std::string &fileContent) noexcept
{
    size_t i = 0;

    for (int y = 0; y != 32; y++) {
        std::vector<char> line;
        for (int x = 0; x != 40; x++) {
            line.emplace_back(fileContent[i]);
            i++;
        }
        map.emplace_back(line);
        i++;
    }
}

/**
 * @brief Déplace le fruit ailleurs dans la carte
 * (ne peut pas se mettre dans un # ou un X)
 *
 */
void Nibbler::newFruit()
{
    map[fruit.y][fruit.x] = ' ';

    fruit.x = 2 + std::rand() / ((RAND_MAX + 1u) / 36);
    fruit.y = 2 + std::rand() / ((RAND_MAX + 1u) / 26);
    while (map[fruit.y][fruit.x] == 'X' || map[fruit.y][fruit.x] == '#') {
        fruit.x = 2 + std::rand() / ((RAND_MAX + 1u) / 36);
        fruit.y = 2 + std::rand() / ((RAND_MAX + 1u) / 26);
    }

    map[fruit.y][fruit.x] = 'F';
}

void Nibbler::setScore(const int &nscore) noexcept
{
    score = nscore;
}
