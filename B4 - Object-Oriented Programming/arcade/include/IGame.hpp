/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "Elements.hpp"
#include "Misc.hpp"
#include <iostream>
#include <memory>
#include <vector>

class IGame {
public:
    virtual ~IGame() = default;
    /**
     * @brief Récupère l'input de la Gameloop pour lancer les différentes actions du jeu
     *
     * @param input
     */
    virtual void handleInput(const Arcade::Key &input) noexcept = 0;
    /**
     * @brief Renvoi un vecteur de Sprites contenant tous les éléments à afficher dans le jeu
     *
     * @return std::vector<Sprite>
     */
    virtual std::vector<Sprite> getDisplay() noexcept = 0;
    /**
     * @brief Mets à jour les informations du jeu
     *
     */
    virtual void update() noexcept = 0;
    /**
     * @brief Remise à 0 des options du jeu
     *
     */
    virtual void reset() noexcept = 0;
    /**
     * @brief Getter pour name
     *
     * @return std::string
     */
    virtual std::string getName() const noexcept = 0;
    /**
     * @brief Getter pour state
     *
     * @return Arcade::GameState
     */
    virtual Arcade::GameState getState() const noexcept = 0;
    /**
     * @brief Getter pour backgroundColor
     *
     * @return Arcade::Color
     */
    virtual Arcade::Color getBackgroundColor() const noexcept = 0;
    /**
     * @brief Getter pour score
     *
     * @return int
     */
    virtual int getScore() const noexcept = 0;
    /**
     * @brief Setter pour score
     *
     * @return void
     */
    virtual void setScore(const int &nscore) noexcept = 0;
    /**
     * @brief Getter pour Music
     *
     * @return std::string
     */
    virtual std::string getMusic() const noexcept = 0;
};

#endif /* !IGAME_HPP_ */
