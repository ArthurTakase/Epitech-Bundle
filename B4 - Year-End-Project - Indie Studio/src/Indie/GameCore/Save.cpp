/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Parser
*/

#include "Save.hpp"

#include <filesystem>
#include <fstream>

#include "Bomb.hpp"
#include "Bomberman.hpp"
#include "Crate.hpp"
#include "Error.hpp"
#include "InstanceOf.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Transform3D.hpp"
#include "Wall.hpp"

Save::Save(GameData& data)
    : data_(data)
{
}

/**
 * It returns a string containing the current date and time in the format "MM-DD.HH:MM"
 *
 * @return A string containing the current date and time.
 */
std::string Save::getCurrentDateTime() const noexcept
{
    char       currentTimeString[80];
    time_t     currentTime = time(0);
    struct tm* tstruct     = localtime(&currentTime);

    strftime(currentTimeString, sizeof(currentTimeString), "%d.%m--%H:%M:%S", tstruct);
    return currentTimeString;
}

/**
 * It creates a file with the current date and time as its name, then writes the number of players,
 * the players' data_, the crates' data_ and the walls' data_
 *
 * @retuns nothing
 */
void Save::save()
{
    std::string   filename = getCurrentDateTime();
    std::string   path     = "Save/" + filename;
    std::ofstream file(path);

    if (!file) return;

    if (!file.is_open()) {
        std::filesystem::create_directory("Save");
        return (save());
    }
    file << "save " << filename << std::endl;
    file << data_.getNbPlayers() << std::endl;
    writeDataPlayer(file);
    file << "Crates" << std::endl;
    writeDataCrate(file);
    file << "Walls" << std::endl;
    writeDataWall(file);
    file << "Items" << std::endl;
    writeDataItem(file);
}

/**
 * It counts the number of bombs that belong to a player
 *
 * @param entities a vector of all the entities in the game
 * @param player The player that we want to know the number of bombs for.
 *
 * @return The number of bombs that the player has placed.
 */
int Save::getNbBomb(const Player& player) const noexcept
{
    int nb = 0;

    for (auto& bomb : data_.getEntities()) {
        int   playerId = player.getId();
        auto& bombN    = *dynamic_cast<Bomb*>(bomb.get());
        if (!Type:: instanceof <Bomb>(bomb.get())) continue;
        int BombOwnerId = bombN.getOwnerId();
        if (BombOwnerId != playerId) continue;
        nb++;
    }
    return (nb);
}

/**
 * It writes the player's data_ to the file
 *
 * @param file the file to write to
 */
void Save::writeDataPlayer(std::ofstream& file)
{
    for (auto& player : data_.getPlayers()) {
        auto transform = player->getComponent<Transform3D>();

        if (!transform.has_value() || !Type:: instanceof <Player>(player.get())) continue;
        auto& tmp    = *dynamic_cast<const Player*>(player.get());
        auto  render = player->getComponent<Render>();
        int   nbBomb = getNbBomb(tmp);
        file << "Player" << std::endl;
        /// Write Player Id/////////////////////////////////////////////////////
        file << tmp.getId() << std::endl;
        /// Write Player Position///////////////////////////////////////////////
        file << transform->get().getPositionX() << ";" << transform->get().getPositionY() << ";"
             << transform->get().getPositionZ() << std::endl;
        /// Write Player Info///////////////////////////////////////////////////
        file << static_cast<int>(tmp.getType()) << std::endl;
        /// Write Player Stat///////////////////////////////////////////////////
        file << tmp.getSpeed() << ";" << tmp.getNbBomb() << ";" << tmp.getBombSize() << std::endl;
        /// Write Player WallPass Boolean///////////////////////////////////////
        file << (tmp.getWallPass() ? 1 : 0) << std::endl;

        /// Write Player isShow Boolean/////////////////////////////////////////
        if (!render.has_value()) file << 0 << std::endl;
        else
            file << (render->get().isShow() ? 1 : 0) << std::endl;
        /// Write Player Bot Boolean////////////////////////////////////////////
        file << ((tmp.isPlayer()) ? 0 : 1) << std::endl;
        /// Write Player Nb Bomb////////////////////////////////////////////////
        file << nbBomb << std::endl;
        if (nbBomb == 0) continue;
        file << "Bombs" << std::endl;
        for (auto& bomb : data_.getEntities()) {
            auto& bombN = *dynamic_cast<Bomb*>(bomb.get());
            if (!Type:: instanceof <Bomb>(bomb.get())) continue;
            int bombOwnerId = bombN.getOwnerId();
            if (bombOwnerId != tmp.getId()) continue;
            writeDataBombPlayer(file, *bomb.get());
        }
    }
}

/**
 * It writes the position of the bomb to the file
 *
 * @param file The file to write to.
 * @param bomb The bomb entity to write to the file.
 *
 * @return a reference to the file.
 */
void Save::writeDataBombPlayer(std::ofstream& file, Entity& bomb) const
{
    auto transform = bomb.getComponent<Transform3D>();

    if (!transform.has_value()) return;
    /// Write Bomb Position///////////////////////////////////////////////
    file << transform->get().getPositionX() << ";" << transform->get().getPositionY() << ";"
         << transform->get().getPositionZ() << std::endl;
}

/**
 * It writes the position of all crates to the file
 *
 * @param file The file to write to.
 */
void Save::writeDataCrate(std::ofstream& file)
{
    for (auto& crate : data_.getEntities()) {
        auto transform = crate->getComponent<Transform3D>();
        if (!transform.has_value() || !Type:: instanceof <Crate>(crate.get())) continue;
        file << transform->get().getPositionX() << ";" << transform->get().getPositionY() << ";"
             << transform->get().getPositionZ() << std::endl;
    }
}

/**
 * it writes the position of all the walls in the game to a file
 *
 * @param file the file to write to.
 */
void Save::writeDataWall(std::ofstream& file)
{
    for (auto& wall : data_.getEntities()) {
        auto transform = wall->getComponent<Transform3D>();
        if (!transform.has_value() || !Type:: instanceof <Wall>(wall.get())) continue;
        file << transform->get().getPositionX() << ";" << transform->get().getPositionY() << ";"
             << transform->get().getPositionZ() << std::endl;
    }
}

/**
 * it writes the position of all the items in the game to a file
 *
 * @param file the file to write to.
 */
void Save::writeDataItem(std::ofstream& file)
{
    for (auto& item : data_.getEntities()) {
        auto transform = item->getComponent<Transform3D>();
        if (!transform.has_value() || !Type:: instanceof <Item>(item.get())) continue;
        auto& item_ = *dynamic_cast<Item*>(item.get());
        file << static_cast<int>(item_.getType()) << std::endl;
        file << transform->get().getPositionX() << ";" << transform->get().getPositionY() << ";"
             << transform->get().getPositionZ() << std::endl;
    }
}

/**
 * It splits a string into a vector of strings, using a delimiter
 *
 * @param str the string to split
 * @param delimiter the string to split the string by
 * @param result a pointer to a vector of strings. This is where the result will be stored.
 */
void Save::splitStr(std::string str, std::string delimiter, std::vector<std::string>& result)
{
    size_t pos = 0;

    if (delimiter.empty()) { throw Error("invalid line: " + str + " " + delimiter); }

    result.clear();
    while ((pos = str.find(delimiter)) != std::string::npos) {
        result.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
}

/**
 * It opens a file, reads the file line by line, and then passes the infos to another function
 */
void Save::load(const std::string_view& filename)
{
    std::ifstream            file(filename.data());
    std::string              line;
    std::vector<std::string> infos;

    if (!file.is_open()) throw Error("Cannot open file");
    while (std::getline(file, line, '\n')) { infos.emplace_back(line); }
    loadGameData(infos);
}

/**
 * It loads the infos from the file into the game
 *
 * @param infos The vector of strings that contains the infos to load
 */
void Save::loadGameData(std::vector<std::string>& infos)
{
    data_.setNbPlayers(std::stoi(infos[1]));
    for (int i = 0; i < data_.getNbPlayers(); i++) {
        if (infos[index_].find("Player") != 0)
            throw Error("Save not valid: " + infos[index_] + " in loadGameData Player");
        loadGamePlayerData(infos);
    }

    if (infos[index_].find("Crates") != 0)
        throw Error("Save not valid: " + infos[index_] + " in loadGameData Crates");
    index_++;
    while (infos[index_].find("Walls") != 0) {
        try {
            loadGameCrateData(infos);
        } catch (std::exception err) {
            throw Error("Save not valid: " + infos[index_] + " in loadGameCrate " + err.what());
        }
        index_++;
    }

    if (infos[index_].find("Walls") != 0)
        throw Error("Save not valid: " + infos[index_] + " in loadGameData Walls");
    index_++;
    while (infos[index_].find("Items") != 0) {
        try {
            loadGameWallData(infos);
        } catch (std::exception err) {
            throw Error("Save not valid: " + infos[index_] + " in loadGameWall " + err.what());
        }
        index_++;
    }

    if (infos[index_].find("Items") != 0)
        throw Error("Save not valid: " + infos[index_] + " in loadGameData Items");
    while (infos[index_] != infos.back()) {
        index_++;
        try {
            loadGameItemData(infos);
        } catch (std::exception err) {
            throw Error("Save not valid: " + infos[index_] + " in loadGameItem " + err.what());
        }
    }
}

/**
 * It loads the player data from the save file
 *
 * @param infos The vector of strings that contains the data of the save file.
 */
void Save::loadGamePlayerData(std::vector<std::string>& infos)
{
    int                      id;
    int                      type;
    int                      nbBombPlaced;
    Vector3D                 pos;
    std::vector<std::string> split;

    index_ += 1;
    id = std::stoi(infos[index_]);
    this->data_.addPlayer(id);
    auto& player = *dynamic_cast<Player*>(this->data_.getPlayers().back().get());

    index_ += 1;
    splitStr(infos[index_], ";", split);
    if (split.size() != 3) throw Error("Save not valid: " + infos[index_] + " loadGamePlayer");
    pos.x = std::stof(split[0]);
    pos.y = std::stof(split[1]);
    pos.z = std::stof(split[2]);
    player.setPosition(pos);

    index_ += 1;
    type = std::stoi(infos[index_]);
    player.setPlayerType(static_cast<PlayerType>(type));

    index_ += 1;
    splitStr(infos[index_], ";", split);
    if (split.size() != 3) throw Error("Save not valid: " + infos[index_] + " loadGamePlayer");
    player.setSpeed(std::stof(split[0]));
    player.setNbBomb(std::stoi(split[1]));
    player.setBombSize(std::stoi(split[2]));

    index_ += 1;
    player.setWallPass(std::stoi(infos[index_]) == 1 ? true : false);

    index_ += 1;
    player.getComponent<Render>()->get().show(std::stoi(infos[index_]) == 1 ? true : false);

    index_ += 1;
    player.setIsBot(std::stoi(infos[index_]) == 1 ? true : false);

    index_ += 1;
    nbBombPlaced = std::stoi(infos[index_]);

    index_ += 1;
    if (nbBombPlaced > 0 && !infos[index_].find("Bombs")) {
        for (int i = 0; i < nbBombPlaced; i++) {
            try {
                loadGameBombData(infos);
            } catch (std::exception err) {
                throw Error("Save not valid: " + infos[index_] + " loadGameBomb " + err.what());
            }
        }
        index_ += 1;
    }
}

/**
 * It loads a bomb from a file
 *
 * @param data_ The vector of strings containing the data_ to load.
 * @param index_ The index_ of the line in the file that we're currently reading.
 */
void Save::loadGameBombData(const std::vector<std::string>& infos)
{
    Player&                  player = *dynamic_cast<Player*>(data_.getPlayers().back().get());
    Vector3D                 pos;
    std::vector<std::string> split;

    index_ += 1;
    splitStr(infos[index_], ";", split);
    pos.x = std::stof(split[0]);
    pos.y = std::stof(split[1]);
    pos.z = std::stof(split[2]);
    data_.addBomb(pos, player, player.getBombSize());
}

/**
 * It takes a vector of strings, and an index_, and it adds a crate to the game world at the
 * position specified by the string at the index_
 *
 * @param data_ The vector of strings that contains the data_ to be loaded.
 * @param index_ The index_ of the line in the file that is being read.
 */
void Save::loadGameCrateData(const std::vector<std::string>& infos)
{
    std::vector<std::string> split;
    Vector3D                 pos;

    splitStr(infos[index_], ";", split);
    pos.x = std::stof(split[0]);
    pos.y = std::stof(split[1]);
    pos.z = std::stof(split[2]);
    data_.addCrate(pos);
}

/**
 * It takes a vector of strings, and an index_, and it adds a wall to the game world
 *
 * @param data_ The vector of strings that contains the data_ to be loaded.
 * @param index_ The index_ of the line in the file that is being read.
 */
void Save::loadGameWallData(const std::vector<std::string>& infos)
{
    std::vector<std::string> split;
    Vector3D                 pos;

    splitStr(infos[index_], ";", split);
    pos.x = std::stof(split[0]);
    pos.y = std::stof(split[1]);
    pos.z = std::stof(split[2]);
    data_.addWall(pos);
}

/**
 * It takes a vector of strings, and an index_, and it adds a item to the game world
 *
 * @param data_ The vector of strings that contains the data_ to be loaded.
 * @param index_ The index_ of the line in the file that is being read.
 */
void Save::loadGameItemData(const std::vector<std::string>& infos)
{
    std::vector<std::string> split;
    Vector3D                 pos;
    bomberman::ItemType      type = static_cast<bomberman::ItemType>(std::stoi(infos[index_]));

    index_ += 1;
    splitStr(infos[index_], ";", split);
    pos.x = std::stof(split[0]);
    pos.y = std::stof(split[1]);
    pos.z = std::stof(split[2]);
    data_.addItem(pos, type);
}
