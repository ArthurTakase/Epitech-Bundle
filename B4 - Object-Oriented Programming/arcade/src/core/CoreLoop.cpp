/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** CoreLoop
*/

#include "Core.hpp"

/**
 * @brief Change la librairie actuelle du programme
 *
 * @param input
 * @return true La lib a pu être chargée // false La lib n'a pas été chargée
 */
bool Core::switchLib(const Arcade::Key &input) noexcept
{
    int temp       = currentLibIndex;
    int last_index = (int)all_lib.size() - 1;

    if (input == Arcade::PREVIOUS_LIB) currentLibIndex--;
    if (input == Arcade::NEXT_LIB) currentLibIndex++;

    if (currentLibIndex != temp) {
        if (currentLibIndex > last_index) currentLibIndex = 0;
        if (currentLibIndex < 0) currentLibIndex = last_index;
        currentLib->deleteWindow();
        currentLib = all_lib[currentLibIndex];
        currentLib->createWindow();
        return true;
    }
    return false;
}

/**
 * @brief Change le jeu actuel du programme
 *
 * @param input
 * @return true Le jeu a pu être changé // false Le jeu n'a pas changé
 */
bool Core::switchGame(const Arcade::Key &input) noexcept
{
    int temp       = currentGameIndex;
    int last_index = (int)all_game.size() - 1;

    if (input == Arcade::PREVIOUS_GAME) currentGameIndex--;
    if (input == Arcade::NEXT_GAME) currentGameIndex++;

    if (currentGameIndex != temp) {
        int score = currentGame->getScore();
        if (currentGameIndex > last_index) currentGameIndex = 0;
        if (currentGameIndex < 0) currentGameIndex = last_index;
        currentGame = all_game[currentGameIndex];
        currentGame->setScore(score);
        return true;
    }
    return false;
}

void Core::handleInput(const Arcade::Key &input) noexcept
{
    if (input == Arcade::Key::QUIT_EVENT) isExit = true;
    if (input == Arcade::Key::ADVANCED) toggleAdvanced = !toggleAdvanced;
    if (input == Arcade::Key::RESTART && state == Arcade::CoreState::END) {
        currentGame->reset();
        state = Arcade::CoreState::GAME;
    }

    if (input == Arcade::Key::SWITCH_STATE) {
        currentGame->reset();
        switch (state) {
        case Arcade::CoreState::END: state = Arcade::CoreState::MENU; break;
        case Arcade::CoreState::GAME: state = Arcade::CoreState::MENU; break;
        case Arcade::CoreState::MENU: state = Arcade::CoreState::GAME; break;
        default: break;
        }
    }
}

/**
 * @brief Boucle principale de l'Arcade.
 * Est chargée de récupérer l'input et de lancer le jeu/menu.
 * La Modification des .so est lancée à partir d'ici.
 *
 */
void Core::loop() noexcept
{
    Arcade::Key input;

    currentLib->createWindow();
    menuLoop(Arcade::Key::NONE);
    while (!isExit) {
        currentLib->playSound(currentGame->getMusic());
        input = currentLib->getInput();

        currentLib->clearLib(backgroundColor);

        switchGame(input);
        switchLib(input);
        handleInput(input);

        switch (state) {
        case Arcade::CoreState::MENU: menuLoop(input); break;
        case Arcade::CoreState::GAME: gameLoop(input); break;
        case Arcade::CoreState::END: endLoop(input); break;
        default: break;
        }
        currentLib->refreshLib();
    }
    currentLib->deleteWindow();
}

/**
 * @brief 'Boucle' consacrée à la partie JV.
 * Récupère score, affichage et état de la partie.
 * Est chargée de mettre à jour les données du jeu.
 *
 * @param input
 */
void Core::gameLoop(const Arcade::Key &input) noexcept
{
    size_t      score         = (size_t)currentGame->getScore();
    std::string scoreText     = std::to_string(score);
    std::string highScoreText = std::to_string(highScore.score) + " (" + highScore.name + ")";
    std::string name          = currentGame->getName();

    backgroundColor = currentGame->getBackgroundColor();
    lastGameState   = currentGame->getState();

    if (highScore.score < score) changeHighScore(score);
    if (lastGameState == Arcade::GameState::WIN || lastGameState == Arcade::GameState::LOOSE) state = Arcade::CoreState::END;

    // INPUT
    currentGame->handleInput(input);

    // GAME SPRITES DISPLAY
    auto elems = currentGame->getDisplay();
    for (auto &sprite : elems) {
        sprite.y += 4;
        sprite.x += 15;
        currentLib->putSprite(sprite);
    }

    // ADVANCED MODE DISPLAY
    if (toggleAdvanced) currentLib->putSprite(Sprite("assets/img/hud/grid.png", Arcade::BLACK, 0, 0));
    currentLib->putSprite(Sprite("assets/img/hud/arcade1.png", Arcade::BLACK, 0, 0));

    // SCORE
    currentLib->putText(Text("Score", Arcade::TextColor::TXT_WHITE, 2, 5, true));
    currentLib->putText(Text(scoreText, Arcade::TextColor::TXT_WHITE, 2, 6, false));
    // HIGHSCORE
    currentLib->putText(Text("HighScore:", Arcade::TextColor::TXT_WHITE, 2, 8, true));
    currentLib->putText(Text(highScoreText, Arcade::TextColor::TXT_WHITE, 2, 9, false));
    // NOM
    currentLib->putText(Text(name, Arcade::TextColor::TXT_WHITE, 23, 1, false));

    currentGame->update();
}

/**
 * @brief Gère les différents inputs dans le menu.
 * Son but principal est de gérer l'ecriture du pseudo de l'utilisateur.
 *
 * @param input
 * @return size_t Index de la lettre actuellement selectionnée
 */
size_t Core::handleInputMenu(const Arcade::Key &input) noexcept
{
    static size_t index = 0;
    const int     limit = 3;

    switch (input) {
    case Arcade::Key::UP: pseudo[index] += 1; break;
    case Arcade::Key::DOWN: pseudo[index] -= 1; break;
    case Arcade::Key::LEFT:
        if (index != 0) index -= 1;
        break;
    case Arcade::Key::RIGHT:
        if (index != limit) index += 1;
        break;
    default: break;
    }

    if (pseudo[index] > 90) pseudo[index] = 65;
    if (pseudo[index] < 65) pseudo[index] = 90;

    return index;
}

/**
 * @brief 'Boucle' consacrée à la partie Menu.
 * Affiche une liste des différentes options de lib/jeu.
 *
 * @param input
 */
void Core::menuLoop(const Arcade::Key &input) noexcept
{
    (void)input;
    size_t      lib_size      = all_lib.size();
    size_t      pseudoInput   = handleInputMenu(input);
    std::string highScoreText = std::to_string(highScore.score) + " (" + highScore.name + ")";

    backgroundColor = Arcade::Color::BLACK;

    if (all_game.empty() || all_lib.empty()) return;

    if (toggleAdvanced) currentLib->putSprite(Sprite("assets/img/hud/grid.png", Arcade::BLACK, 0, 0));
    currentLib->putSprite(Sprite("assets/img/hud/arcade1.png", Arcade::BLACK, 0, 0));

    // Draw lib names
    currentLib->putText({ "Libs :", Arcade::TXT_WHITE, 16, 5, false });
    for (size_t i = 0; i != all_lib.size(); i++)
        currentLib->putText({ "> " + all_lib[i]->getName(), Arcade::TXT_WHITE, 16, i + 6,
                              (currentLib->getName() == all_lib[i]->getName()) ? true : false });

    // Draw game names
    currentLib->putText({ "Games :", Arcade::TXT_WHITE, 16, lib_size + 8, false });
    for (size_t j = 0; j != all_game.size(); j++)
        currentLib->putText({ "> " + all_game[j]->getName(), Arcade::TXT_WHITE, 16, j + lib_size + 9,
                              (currentGame->getName() == all_game[j]->getName()) ? true : false });

    // Pseudo
    currentLib->putText({ "PSEUDO", Arcade::TXT_WHITE, 16, 24, false });
    for (size_t k = 0; k != 4; k++)
        currentLib->putText(
            { std::string(1, pseudo[k]), (pseudoInput == k) ? Arcade::TXT_RED : Arcade::TXT_WHITE, 16 + k, 25, false });

    // Controles
    currentLib->putText({ "CONTROLS", Arcade::TXT_WHITE, 16, 29, false });
    currentLib->putText({ "C/V      -> Change lib", Arcade::TXT_WHITE, 16, 30, false });
    currentLib->putText({ "B/N      -> Change game", Arcade::TXT_WHITE, 16, 31, false });
    currentLib->putText({ "Escape/Q -> Quit Arcade", Arcade::TXT_WHITE, 16, 32, false });
    currentLib->putText({ "ENTER    -> Switch Game/Menu", Arcade::TXT_WHITE, 16, 33, false });

    // HIGHSCORE
    currentLib->putText(Text("HighScore:", Arcade::TextColor::TXT_WHITE, 2, 8, true));
    currentLib->putText(Text(highScoreText, Arcade::TextColor::TXT_WHITE, 2, 9, false));
}

/**
 * @brief 'Boucle' consacrée à l'écran de fin.
 * Affiche le meilleur score et les options d'après partie.
 *
 * @param input non utilisé.
 */
void Core::endLoop(const Arcade::Key &input) noexcept
{
    (void)input;

    std::string endText = (lastGameState == Arcade::GameState::LOOSE) ? "- Game Over ! -" : "- You Win ! -";
    std::string currentPseudo(pseudo);
    std::string score = std::to_string(currentGame->getScore());

    currentLib->putSprite(Sprite("assets/img/hud/endscreen.png", Arcade::BLACK, 0, 0));

    currentLib->putText({ "- HIGH SCORE -", Arcade::TXT_WHITE, 28, 8, false });
    currentLib->putText({ highScore.name + ": " + std::to_string(highScore.score), Arcade::TXT_WHITE, 27, 10, false });
    currentLib->putText({ "- YOUR SCORE -", Arcade::TXT_WHITE, 28, 12, false });
    currentLib->putText({ currentPseudo + ": " + score, Arcade::TXT_WHITE, 27, 13, false });

    if (currentGame->getScore() == (int)highScore.score)
        currentLib->putText({ "NEW HIGH SCORE !", Arcade::TXT_BLUE, 28, 15, true });

    currentLib->putText({ endText, Arcade::TXT_WHITE, 28, 17, false });
    currentLib->putText({ "- Press [R] to restart the game -", Arcade::TXT_WHITE, 23, 20, false });
    currentLib->putText({ "- Press [Q] or [ESC] to quit the game -", Arcade::TXT_WHITE, 21, 21, false });
    currentLib->putText({ "- Press [Enter] to return to the menu -", Arcade::TXT_WHITE, 21, 22, false });
}
