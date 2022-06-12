/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SolarFox
*/

#include "SolarFox.hpp"
#include <fstream>

/**
 * @brief Retourne un objet SolarFox.
 * Extern "C" pour l'ouvrir facilement depuis un dlsym
 *
 */
extern "C" std::shared_ptr<IGame> createGame()
{
    return std::make_shared<SolarFox>();
}

/**
 * @brief Construct a new Solar Fox:: Solar Fox object
 *
 */
SolarFox::SolarFox() : AGame("lib/arcade_solarfox.so", Arcade::Color::BLACK, "assets/sound/music.ogg")
{
    reset();

    player.color = Arcade::Color::GREEN;
    ennemy.emplace_back(std::make_unique<Solarfox::Ennemy>(0, 0, 39, 0, "assets/img/solarfox/enemyup.png"));
    ennemy.emplace_back(std::make_unique<Solarfox::Ennemy>(39, 31, 0, 31, "assets/img/solarfox/enemydown.png"));
    ennemy.emplace_back(std::make_unique<Solarfox::Ennemy>(39, 0, 39, 31, "assets/img/solarfox/enemyright.png"));
    ennemy.emplace_back(std::make_unique<Solarfox::Ennemy>(0, 31, 0, 0, "assets/img/solarfox/enemyleft.png"));
}

SolarFox::~SolarFox() noexcept {}

/**
 * @brief Récupère l'input de la Gameloop pour lancer les différentes actions du jeu
 *
 * @param input
 */
void SolarFox::handleInput(const Arcade::Key &input) noexcept
{
    switch (input) {
    case Arcade::Key::LEFT: updateDir(-1, 0); break;
    case Arcade::Key::RIGHT: updateDir(1, 0); break;
    case Arcade::Key::UP: updateDir(0, -1); break;
    case Arcade::Key::DOWN: updateDir(0, 1); break;
    default: break; ;
    }

    if (input == Arcade::Key::POWER) (playerSpeed == 1) ? playerSpeed = 2 : playerSpeed = 1;
    if (input == Arcade::Key::POWER2)
        if (xdir != ydir)
            pioupiou.emplace_back(Solarfox::PiouPiou(player.x + xdir, player.y + ydir, xdir, ydir, 2, false, false));
}

/**
 * @brief Renvoi un vecteur de Sprites contenant tous les éléments à afficher dans le jeu
 *
 * @return std::vector<Sprite>
 */
std::vector<Sprite> SolarFox::getDisplay() noexcept
{
    std::vector<Sprite> sprites;

    // Map
    if (!map.empty()) map[0][0] = ' ';
    for (int y = 0; y < (int)map.size(); y++)
        for (int x = 0; x < (int)map[y].size(); x++) {
            switch (map[y][x]) {
            case '|': sprites.emplace_back(Sprite("assets/img/solarfox/border_v.png", Arcade::Color::WHITE, x, y)); break;
            case '-': sprites.emplace_back(Sprite("assets/img/solarfox/border_h.png", Arcade::Color::WHITE, x, y)); break;
            case ' ': sprites.emplace_back(Sprite("assets/img/solarfox/floor.png", Arcade::Color::BLACK, x, y)); break;
            case '.': sprites.emplace_back(Sprite("assets/img/solarfox/powerup.png", Arcade::Color::BLUE, x, y)); break;
            case '!': sprites.emplace_back(Sprite("assets/img/solarfox/bad_powerup.png", Arcade::Color::CYAN, x, y)); break;
            default: break;
            }
        }

    // Ennemis
    for (auto &it : ennemy) sprites.emplace_back(it->getSprite());

    // Tirs ennemis
    for (auto &it : ennemy)
        for (auto &piou : it->getPioupiou()) sprites.emplace_back(piou.getSprite());

    // Tirs alliés
    for (auto &it : pioupiou) sprites.emplace_back(it.getSprite());

    // Joueur
    if (xdir == -1 && ydir == 0) player.spritePath = "assets/img/solarfox/ship_l.png";
    if (xdir == 1 && ydir == 0) player.spritePath = "assets/img/solarfox/ship_r.png";
    if (xdir == 0 && ydir == -1) player.spritePath = "assets/img/solarfox/ship_u.png";
    if (xdir == 0 && ydir == 1) player.spritePath = "assets/img/solarfox/ship_d.png";
    sprites.emplace_back(player);

    return sprites;
}

/**
 * @brief Mets à jour les informations du jeu
 *
 */
void SolarFox::update() noexcept
{
    player.x += (xdir * playerSpeed) % 3;
    player.y += (ydir * playerSpeed) % 3;

    for (auto &it : ennemy) {
        if (it->atStart() || it->atEnd()) { it->reverseSpeed(); }
        it->move();
        it->shoot();
    }

    for (auto &it : pioupiou) {
        if (map.empty()) continue;

        int x = it.getSprite().x;
        int y = it.getSprite().y;

        if (x > (int)map[2].size() || y > (int)map.size() - 1 || y < 0 || x < 0) continue;
        if (map[y][x] == '.') {
            map[y][x] = ' ';
            obj--;
            score++;
            it.setLifetime(-1);
        }
        it.move();
    }

    for (auto &enn : ennemy)
        for (auto &piou : pioupiou) {
            auto sprite = piou.getSprite();
            int  index  = enn->checkColPiouPiou(sprite);
            try {
                if (index != -1) enn->getPioupiou().erase(std::next(enn->getPioupiou().begin(), index));
            }
            catch (std::exception &e) {
                std::cerr << "Erreur suppression d'un tir ennemi." << std::endl;
            }
        }

    int limit = pioupiou.size();
    for (int i = 0; i != limit; i++) {
        if (pioupiou[i].getLifetime() <= 0) {
            pioupiou.erase(std::next(pioupiou.begin(), i));
            i--;
            limit--;
        }
    }

    playerSpeed = 1;

    this->state = endGame();
}

/**
 * @brief Check les conditions de fin d'une partie
 *
 * @return Arcade::GameState
 */
Arcade::GameState SolarFox::endGame() noexcept
{
    int newx = player.x + (xdir * playerSpeed);
    int newy = player.y + (ydir * playerSpeed);

    for (auto &it : ennemy)
        if (it->checkColPiouPiou(player) != -1) return Arcade::GameState::LOOSE;
    if (xdir == 0 && ydir == 0) return Arcade::GameState::PROGRESS;
    if (obj == 0) return Arcade::GameState::WIN;
    if (newy > 31 || newy < 0 || newx > 39 || newx < 0) return Arcade::GameState::LOOSE;
    if (map[player.y][player.x] == '!') return Arcade::GameState::LOOSE;
    return Arcade::GameState::PROGRESS;
}

/**
 * @brief Remise à 0 des options du jeu
 *
 */
void SolarFox::reset() noexcept
{
    size_t      nbMap      = 3;
    std::string allMaps[3] = { "solarfox_1", "solarfox_2", "solarfox_3" };
    int         indexMap   = std::rand() / ((RAND_MAX + 1u) / nbMap);

    score       = 0;
    playerSpeed = 1;
    xdir        = 0;
    ydir        = 0;
    obj         = 0;
    state       = Arcade::GameState::PROGRESS;

    player.spritePath = "assets/img/solarfox/ship_d.png";
    player.x          = 10;
    player.y          = 10;

    loadMap("assets/maps/" + allMaps[indexMap] + ".map");

    for (auto &it : ennemy) it->reset();
    pioupiou.clear();
}

/**
 * @brief Ouvre le fichier donné en param et charge un vector<vector<char>>
 * avec tous les éléments du fichier dans l'attribut map
 *
 * @param filePath fichier à charger
 */
void SolarFox::loadMap(std::string filePath) noexcept
{
    std::ifstream myFile(filePath);
    std::string   fileContent = "";

    map.clear();

    if (myFile.is_open()) fileContent = getFileContent(myFile);
    if (fileContent.size() < 1312) {
        myFile.close();
        return;
    }
    fillMap(fileContent);
    myFile.close();
}

std::string SolarFox::getFileContent(std::ifstream &myFile) noexcept
{
    char        mychar;
    std::string fileContent = "";

    while (myFile) {
        mychar = myFile.get();
        fileContent += mychar;
        if (mychar == '.') obj += 1;
    }
    return fileContent;
}

void SolarFox::fillMap(const std::string &fileContent) noexcept
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
 * @brief Change la direction du vaisseau
 *
 * @param xdir Direction horizontale (-1, 0, 1)
 * @param ydir Direction verticale (-1, 0, 1)
 */
void SolarFox::updateDir(const int &nxdir, const int &nydir) noexcept
{
    if (goingReverse(nxdir, nydir)) return;

    xdir = nxdir;
    ydir = nydir;
}

bool SolarFox::goingReverse(const int &nxdir, const int &nydir) noexcept
{
    return nxdir == -xdir && nydir == -ydir;
}

void SolarFox::setScore(const int &nscore) noexcept
{
    score = nscore;
}
