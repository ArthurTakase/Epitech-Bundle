/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Parser
*/

#pragma once

#include <string>
#include <vector>

#include "Entity.hpp"
#include "Player.hpp"

class GameData;

class Save
{
  public:
    Save(GameData& data);
    Save(const Save& other) noexcept = delete;
    Save(Save&& other) noexcept      = delete;
    ~Save() noexcept                 = default;

    Save& operator=(const Save& rhs) noexcept = delete;
    Save& operator=(Save&& rhs) noexcept = delete;

    void load(const std::string_view& filename);
    void save();

  private:
    // methods
    void        loadGameData(std::vector<std::string>& infos);
    void        loadGamePlayerData(std::vector<std::string>& infos);
    void        loadGameBombData(const std::vector<std::string>& infos);
    void        loadGameCrateData(const std::vector<std::string>& infos);
    void        loadGameWallData(const std::vector<std::string>& infos);
    void        loadGameItemData(const std::vector<std::string>& infos);
    void        writeDataGame(std::ofstream& file);
    void        writeDataPlayer(std::ofstream& file);
    void        writeDataCrate(std::ofstream& file);
    void        writeDataWall(std::ofstream& file);
    void        writeDataItem(std::ofstream& file);
    void        writeDataBombPlayer(std::ofstream& file, Entity& bomb) const;
    std::string getCurrentDateTime() const noexcept;
    int         getNbBomb(const Player& player) const noexcept;
    void        splitStr(std::string str, std::string delimiter, std::vector<std::string>& result);

    // attributes
    GameData& data_;
    int       index_ = 2;
};
