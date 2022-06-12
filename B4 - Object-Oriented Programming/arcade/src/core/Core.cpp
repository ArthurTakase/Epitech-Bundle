/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Core
*/

#include "Core.hpp"

/**
 * @brief Construit l'objet Core::Core
 *
 * @param folder Emplacement des fichiers .so
 * @param wantedLib Librarie souhaitée par défaut
 */
Core::Core(std::string folder, std::string wantedLib)
    : currentLibIndex(-1), currentGameIndex(0), state(Arcade::CoreState::MENU), backgroundColor(Arcade::Color::BLACK),
      toggleAdvanced(false), lastGameState(Arcade::GameState::PROGRESS), isExit(false)
{
    loadAll(folder);

    pseudo[0] = 'A';
    pseudo[1] = 'A';
    pseudo[2] = 'A';
    pseudo[3] = 'A';
    pseudo[4] = '\0';

    if (all_game.size() == 0) {
        isExit = true;
        std::cerr << "⛔ " << REDB << "Erreur:" << NC << " Aucun jeu disponible." << std::endl;
        return;
    }
    if (all_lib.size() == 0) {
        isExit = true;
        std::cerr << "⛔ " << REDB << "Erreur:" << NC << " Aucune librairie disponible." << std::endl;
        return;
    }

    currentGame = all_game[currentGameIndex];

    for (auto &lib : all_lib) {
        currentLibIndex++;
        if (lib->getName() == "lib/arcade_sfml.so") lib->playSound(currentGame->getMusic());
        if (wantedLib == lib->getName()) {
            currentLib = lib;
            break;
        }
    }
    if (!currentLib) {
        isExit = true;
        std::cerr << "⛔ " << REDB << "Erreur:" << NC << " La librairie demandée (";
        std::cerr << wantedLib;
        std::cerr << ") n'existe pas." << std::endl;
    }
}

/**
 * @brief Détruit l'objet Core::Core et toutes les shared lib qu'il contient
 *
 */
Core::~Core() noexcept
{

    currentGame.reset();
    for (auto &game : all_game) game.reset();

    currentLib.reset();
    for (auto &lib : all_lib) lib.reset();

    for (auto &shared : allLd) {
        if (dlclose(shared)) {
            std::cerr << dlerror() << std::endl;
            exit(84);
        }
    }
}

/**
 * @brief Charge une lib en .so et l'ajoute au vecteur contenant toutes les libs
 *
 * @param libFile Lien du fichier .so à charger
 */
void Core::loadLib(const std::string &libFile, const std::string &function) noexcept
{
    auto shared_lib = dlopen(libFile.data(), RTLD_LAZY);

    if (shared_lib == nullptr) {
        std::cerr << dlerror() << std::endl;
        exit(84);
    }

    auto lib = getFunction(shared_lib, function);

    if (function == "createLib") all_lib.push_back(((std::shared_ptr<ILibrary>(*)())lib)());
    if (function == "createGame") all_game.push_back(((std::shared_ptr<IGame>(*)())lib)());

    allLd.push_back(shared_lib);
}

/**
 * @brief Récupère la fonction demandée dans le .so correspondant
 *
 * @param lib Valeur de retour du dlopen correspondant
 * @param function Nom de la fonction à retrouver (doit être en extern C)
 * @return void* Adresse de la fonction
 */
void *Core::getFunction(void *lib, const std::string &function) const noexcept
{
    return dlsym(lib, function.c_str());
}

/**
 * @brief Charge en mémoire tous les .so qu'il trouve dans `folderName` (jeux/lib)
 *
 * @param folderName Lien du dossier à analyser
 */
void Core::loadAll(const std::string &folderName) noexcept
{
    DIR           *dir;
    struct dirent *ent;
    std::string    libs[]  = { "arcade_sfml.so",     "arcade_sdl2.so",
                           "arcade_ncurses.so",  "arcade_opengl.so",
                           "arcade_libcaca.so",  "arcade_ndk++.so",
                           "arcade_aalib.so",    "arcade_allegro5.so",
                           "arcade_xlib.so",     "arcade_gtk+.so",
                           "arcade_irrlicht.so", "arcade_vulkan.so",
                           "arcade_qt5.so",      "NULL" };
    std::string    games[] = { "arcade_nibbler.so",   "arcade_pacman.so",   "arcade_qix.so",
                            "arcade_centipede.so", "arcade_solarfox.so", "NULL" };

    if ((dir = opendir(folderName.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            std::string  str(ent->d_name);
            std::string *search_lib  = std::find(std::begin(libs), std::end(libs), str);
            std::string *search_game = std::find(std::begin(games), std::end(games), str);
            if (search_lib != std::end(libs)) loadLib("lib/" + str, "createLib");
            if (search_game != std::end(games)) loadLib("lib/" + str, "createGame");
        }
        closedir(dir);
    }
    else {
        perror("");
    }
    loadHighScore();
}
