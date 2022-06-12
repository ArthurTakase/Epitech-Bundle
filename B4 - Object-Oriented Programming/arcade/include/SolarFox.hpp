/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include "AGame.hpp"
#include "SolarFoxEnnemy.hpp"
#include "SolarFoxPiouPiou.hpp"

class SolarFox : public AGame {
private:
    // Gameplay
    std::vector<std::vector<char>>                 map;
    std::vector<std::unique_ptr<Solarfox::Ennemy>> ennemy;
    std::vector<Solarfox::PiouPiou>                pioupiou;
    Sprite                                         player;
    int                                            playerSpeed;
    int                                            xdir;
    int                                            ydir;
    int                                            obj;

public:
    SolarFox();
    ~SolarFox() noexcept;
    void                handleInput(const Arcade::Key &input) noexcept final;
    std::vector<Sprite> getDisplay() noexcept final;
    void                update() noexcept final;
    void                reset() noexcept final;
    void                setScore(const int &nscore) noexcept final;

private:
    Arcade::GameState endGame() noexcept;
    void              loadMap(std::string filePath) noexcept;
    void              updateDir(const int &nxdir, const int &nydir) noexcept;
    void              fillMap(const std::string &fileContent) noexcept;
    std::string       getFileContent(std::ifstream &myFile) noexcept;
    bool              goingReverse(const int &nxdir, const int &nydir) noexcept;
};

extern "C" std::shared_ptr<IGame> createGame();

#endif /* !SolarFox_HPP_ */
