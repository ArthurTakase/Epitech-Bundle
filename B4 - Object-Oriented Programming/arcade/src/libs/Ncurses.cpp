/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

/**
 * @brief Retourne un objet Ncurses.
 * Extern "C" pour l'ouvrir facilement depuis un dlsym
 *
 */
extern "C" std::shared_ptr<ILibrary> createLib()
{
    return std::make_shared<Ncurses>();
}

/**
 * @brief Construct a new Ncurses:: Ncurses object
 *
 */
Ncurses::Ncurses() : name("lib/arcade_ncurses.so"), window(nullptr), currentMusic("") {}

/**
 * @brief Destroy the Ncurses:: Ncurses object
 *
 */
Ncurses::~Ncurses() noexcept
{
    deleteWindow();
}

/**
 * @brief Création d'une fenetre de jeu
 *
 * @return bool Echec/réussite de la création
 */
bool Ncurses::createWindow() noexcept
{
    window = initscr();
    noecho();

    start_color();
    // init_pair(id, text, background)
    // Sprites
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(8, COLOR_CYAN, COLOR_CYAN);
    // Text
    init_pair(9, COLOR_RED, COLOR_BLACK);
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(12, COLOR_BLACK, COLOR_BLACK);
    init_pair(13, COLOR_WHITE, COLOR_BLACK);
    // Underline
    init_pair(14, COLOR_BLACK, COLOR_RED);
    init_pair(15, COLOR_BLACK, COLOR_GREEN);
    init_pair(16, COLOR_BLACK, COLOR_BLUE);
    init_pair(17, COLOR_BLACK, COLOR_BLACK);
    init_pair(18, COLOR_BLACK, COLOR_WHITE);

    return true;
}

/**
 * @brief Destruction d'une fenetre de jeu
 *
 */
void Ncurses::deleteWindow() noexcept
{
    if (!window) return;
    endwin();
    window = nullptr;
}

/**
 * @brief Récupère la touche appuyée sous forme d'Arcade::Key
 *
 * @return Arcade::Key
 */
Arcade::Key Ncurses::getInput() noexcept
{
    timeout(50);
    int key = getch();

    switch (key) {
    case 66: return Arcade::Key::DOWN;
    case 65: return Arcade::Key::UP;
    case 68: return Arcade::Key::LEFT;
    case 67: return Arcade::Key::RIGHT;
    case 'q': return Arcade::Key::QUIT_EVENT;
    case 'c': return Arcade::Key::PREVIOUS_LIB;
    case 'v': return Arcade::Key::NEXT_LIB;
    case 'b': return Arcade::Key::PREVIOUS_GAME;
    case 'n': return Arcade::Key::NEXT_GAME;
    case 32: return Arcade::Key::POWER;
    case 'f': return Arcade::Key::POWER2;
    case '\n': return Arcade::Key::SWITCH_STATE;
    case 'x': return Arcade::Key::ADVANCED;
    case 'r': return Arcade::Key::RESTART;
    default: return Arcade::Key::NONE;
    }
}

/**
 * @brief Supprime tous les élément à l'écran avant d'afficher la couleur donnée en paramêtre
 *
 * @param color Couleur de fond (non utilisée par Ncurses)
 */
void Ncurses::clearLib(const Arcade::Color &color) noexcept
{
    (void)color;
    if (window) clear();
}

/**
 * @brief Actualise l'affichage de la lib
 *
 */
void Ncurses::refreshLib() noexcept
{
    if (window) refresh();
}

/**
 * @brief Affiche le Text donné en parametre
 *
 * @param txt {str, color, x, y, underline}
 */
void Ncurses::putText(const Text &txt) noexcept
{
    if (txt.underline) attron(COLOR_PAIR(txt.color + 14));
    else
        attron(COLOR_PAIR(txt.color + 9));

    mvprintw(txt.y, txt.x, txt.str.c_str());

    if (txt.underline) attron(COLOR_PAIR(txt.color + 14));
    else
        attron(COLOR_PAIR(txt.color + 9));
}

/**
 * @brief Affiche le Sprite donné en parametre
 *
 * @param sprite {filePath, color, x, y}
 */
void Ncurses::putSprite(const Sprite &sprite)
{
    attron(COLOR_PAIR(sprite.color + 1));
    mvprintw(sprite.y, sprite.x, "%d", sprite.color + 1);
    attroff(COLOR_PAIR(sprite.color + 1));
}

/**
 * @brief Getter pour name
 *
 * @return std::string
 */
std::string Ncurses::getName() const noexcept
{
    return name;
}

void Ncurses::playSound(const std::string &sound) noexcept
{
    (void)sound;
}

void Ncurses::cleanSound() noexcept {}