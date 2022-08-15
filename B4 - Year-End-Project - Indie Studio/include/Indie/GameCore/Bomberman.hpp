/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Bomberan
*/

#pragma once
#include <cstddef>

namespace bomberman
{
enum class ModelType : std::size_t {
    M_BOMB,
    M_WALL,
    M_CRATE,
    M_IROLLER,
    M_IBOMB,
    M_IFIRE,
    M_IWALL,
    M_FIRE,
    M_PLAYER_1,
    M_PLAYER_2,
    M_PLAYER_3,
    M_PLAYER_4,
    M_NONE
};

enum class SceneType : std::size_t { MENU, GAME, SELECT, SPLASH, LOAD };

enum class ItemType { I_SPEEDUP, I_BOMBUP, I_FIREUP, I_WALL };

}
