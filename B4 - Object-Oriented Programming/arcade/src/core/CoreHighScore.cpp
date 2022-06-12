/*
** EPITECH PROJECT, 2022
** CoreUser.cpp
** File description:
** CoreUser
*/

#include "Core.hpp"

/**
 * @brief Découpe un std::string
 *
 * @param str Phrase à couper
 * @param delimiter limite de découpe
 * @param result pointeur vers le string de stockage du resultat
 */
void Core::splitStr(std::string str, std::string delimiter, std::vector<std::string> *result) const
{
    size_t pos = 0;

    if (delimiter.empty()) { return; }

    (*result).clear();
    while ((pos = str.find(delimiter)) != std::string::npos) {
        (*result).push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    (*result).push_back(str);
}

/**
 * @brief Charge le meilleur score et le nom du joueur en mémoire à partir du fichier arcade.score.
 * Si le fichier n'existe pas, il est créé automatiquement.
 *
 * @param fileName
 */
void Core::loadHighScore(const std::string &fileName) noexcept
{
    std::ifstream            file(fileName);
    std::string              line;
    std::vector<std::string> userInfo;

    if (file.is_open()) {
        if (fileEmpty(file)) {
            file.close();
            writeDefaultHighScore(fileName);
        }
        getline(file, line, '\n');
        splitStr(line, ":", &userInfo);
        highScore.name  = userInfo[0];
        highScore.score = stoi(userInfo[1]);
    }
    else {
        file.close();
        writeDefaultHighScore(fileName);
    }
    file.close();
}

/**
 * @brief Check si le fichier est vide
 *
 * @param file Reference du stream à analyser
 * @return true ou false
 */
bool Core::fileEmpty(std::ifstream &file) const noexcept
{
    return file.peek() == std::ifstream::traits_type::eof();
}

/**
 * @brief Remplie le fichier avec "AAAA:0"
 *
 * @param fileName Fichier à remplir
 */
void Core::writeDefaultHighScore(const std::string &fileName) noexcept
{
    writeHighScore(fileName, highScore_t{ "AAAA", 0 });
    loadHighScore();
}

/**
 * @brief Change le highscore du Core puis ecrit le score dans le fichier par défaut
 *
 * @param score
 */
void Core::changeHighScore(const int score) noexcept
{
    highScore.score = score;
    highScore.name  = pseudo;

    writeHighScore();
}

/**
 * @brief Ecrit le score dans un fichier
 *
 * @param fileName fichier à modifier
 * @param score score à écrire
 */
void Core::writeHighScore(const std::string &fileName, highScore_t score) const noexcept
{
    std::ofstream file(fileName);

    if (file.is_open()) { file << score.name << ":" << score.score << std::endl; }
    file.close();
}

/**
 * @brief Ecrit le score de Core dans un fichier
 *
 * @param fileName fichier à modifier
 */
void Core::writeHighScore(const std::string &fileName) const noexcept
{
    std::ofstream file(fileName);

    if (file.is_open()) { file << pseudo << ":" << highScore.score << std::endl; }
    file.close();
}
