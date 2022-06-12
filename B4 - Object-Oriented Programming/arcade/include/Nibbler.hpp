/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "AGame.hpp"

class Nibbler : public AGame {
private:
    // Gameplay
    std::vector<Sprite>            snake;
    Sprite                         fruit;
    int                            xdir;
    int                            ydir;
    int                            len;
    std::vector<std::vector<char>> map;
    int                            nbSpace;

public:
    // Constructors
    Nibbler();
    ~Nibbler() noexcept;
    // IGame Methods
    void                handleInput(const Arcade::Key &input) noexcept final;
    std::vector<Sprite> getDisplay() noexcept final;
    void                update() noexcept final;
    void                reset() noexcept final;
    void                setScore(const int &nscore) noexcept final;

private: // Gameplay Methods
    Arcade::GameState endGame() noexcept;
    void              updateDir(const int &xdir, const int &ydir) noexcept;
    void              addPartOfSnake();
    void              loadMap(std::string filePath);
    void              tryEat(const int &x, const int &y) noexcept;
    void              newFruit();
    bool              goingReverse(const int &xdir, const int &ydir) noexcept;
    void              getMapSprite(std::vector<Sprite> &sprites) noexcept;
    void              getSnakeSprite(std::vector<Sprite> &sprites) noexcept;
    bool              inMouvement() const noexcept;
    bool              win() noexcept;
    bool              loose() noexcept;
    bool              colNextTurn(const int &x, const int &y, const int &nxdir, const int &nydir) const noexcept;
    void              fillMap(const std::string &fileContent) noexcept;
    std::string       getFileContent(std::ifstream &myFile) noexcept;
};

extern "C" std::shared_ptr<IGame> createGame();

#endif /* !NIBBLER_HPP_ */
