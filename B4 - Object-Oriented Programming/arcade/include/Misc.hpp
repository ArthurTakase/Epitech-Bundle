/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Mics
*/

#ifndef MICS_HPP_
#define MICS_HPP_

namespace Arcade {

typedef enum { MENU, GAME, END } CoreState;

typedef enum { WIN, LOOSE, PROGRESS } GameState;

typedef enum {
    DOWN,
    UP,
    LEFT,
    RIGHT,
    PREVIOUS_LIB,
    NEXT_LIB,
    PREVIOUS_GAME,
    NEXT_GAME,
    POWER,
    POWER2,
    SWITCH_STATE,
    QUIT_EVENT,
    ADVANCED,
    RESTART,
    NONE
} Key;

typedef enum { RED, GREEN, BLUE, BLACK, WHITE, BROWN, MAGENTA, CYAN } Color;

typedef enum { TXT_RED, TXT_GREEN, TXT_BLUE, TXT_BLACK, TXT_WHITE } TextColor;

} // namespace Arcade

#endif /* !MICS_HPP_ */
