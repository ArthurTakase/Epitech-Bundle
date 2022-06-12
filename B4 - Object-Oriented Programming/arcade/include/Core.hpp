/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "IGame.hpp"
#include "ILibrary.hpp"
#include <algorithm>
#include <cstdlib>
#include <dirent.h>
#include <dlfcn.h>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#define NC   "\e[0m"
#define RED  "\e[0;31m"
#define GRN  "\e[0;32m"
#define CYN  "\e[0;36m"
#define REDB "\e[41m"

typedef struct highScore_s {
    std::string name;
    size_t      score;
} highScore_t;

class Core {
private:
    std::vector<void *>                    allLd;
    std::vector<std::shared_ptr<ILibrary>> all_lib;
    std::vector<std::shared_ptr<IGame>>    all_game;
    std::shared_ptr<ILibrary>              currentLib;
    int                                    currentLibIndex;
    std::shared_ptr<IGame>                 currentGame;
    int                                    currentGameIndex;
    Arcade::CoreState                      state;
    Arcade::Color                          backgroundColor;
    char                                   pseudo[5];
    highScore_t                            highScore;
    bool                                   toggleAdvanced;
    Arcade::GameState                      lastGameState;

public:
    bool isExit;

public:
    Core();
    Core(std::string folder, std::string wantedLib);
    Core(const Core &other) = default;
    Core(Core &&other)      = default;
    ~Core() noexcept;
    void  loop() noexcept;
    Core &operator=(const Core &other) noexcept = default;
    Core &operator=(Core &&other) noexcept = default;

private:
    void  *getFunction(void *lib, const std::string &function) const noexcept;
    void   loadAll(const std::string &folderName) noexcept;
    void   loadLib(const std::string &libFile, const std::string &function) noexcept;
    void   loadHighScore(const std::string &file = "arcade.score") noexcept;
    void   changeHighScore(const int) noexcept;
    void   splitStr(std::string str, std::string delimiter, std::vector<std::string> *result) const;
    bool   switchLib(const Arcade::Key &input) noexcept;
    bool   switchGame(const Arcade::Key &input) noexcept;
    void   gameLoop(const Arcade::Key &input) noexcept;
    void   menuLoop(const Arcade::Key &input) noexcept;
    void   endLoop(const Arcade::Key &input) noexcept;
    size_t handleInputMenu(const Arcade::Key &input) noexcept;
    void   writeHighScore(const std::string &fileName, highScore_t score) const noexcept;
    void   writeHighScore(const std::string &fileName = "arcade.score") const noexcept;
    bool   fileEmpty(std::ifstream &file) const noexcept;
    void   writeDefaultHighScore(const std::string &fileName) noexcept;
    void   handleInput(const Arcade::Key &input) noexcept;
};

#endif
