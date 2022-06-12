/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** ILib
*/

#ifndef ILIBRARY_HPP_
#define ILIBRARY_HPP_

#include "Elements.hpp"
#include "Misc.hpp"
#include <iostream>
#include <memory>
#include <stdio.h>
#include <unistd.h>
#include <vector>

class ILibrary {
public:
    virtual ~ILibrary() noexcept = default;
    /**
     * @brief Création d'une fenetre de jeu
     *
     * @return bool Echec/réussite de la création
     */
    virtual bool createWindow() noexcept = 0;
    /**
     * @brief Destruction d'une fenetre de jeu
     *
     */
    virtual void deleteWindow() noexcept = 0;
    /**
     * @brief Récupère la touche appuyée sous forme d'Arcade::Key
     *
     * @return Arcade::Key
     */
    virtual Arcade::Key getInput() noexcept = 0;
    /**
     * @brief Supprime tous les élément à l'écran avant d'afficher la couleur donnée en paramêtre
     *
     * @param color Couleur de fond (non utilisée par Ncurses)
     */
    virtual void clearLib(const Arcade::Color &color) noexcept = 0;
    /**
     * @brief Actualise l'affichage de la lib
     *
     */
    virtual void refreshLib() noexcept = 0;
    /**
     * @brief Affiche le Text donné en parametre
     *
     * @param txt {str, color, x, y, underline}
     */
    virtual void putText(const Text &txt) noexcept = 0;
    /**
     * @brief Affiche le Sprite donné en parametre
     *
     * @param sprite {filePath, color, x, y}
     */
    virtual void putSprite(const Sprite &sprite) = 0;
    /**
     * @brief Joue le son donné en parametre
     *
     * @param sound
     */
    virtual void playSound(const std::string &sound) noexcept = 0;
    /**
     * @brief clear les sons lancés.
     *
     */
    virtual void cleanSound() noexcept = 0;
    /**
     * @brief Getter pour name
     *
     * @return std::string
     */
    virtual std::string getName() const noexcept = 0;
};

#endif
