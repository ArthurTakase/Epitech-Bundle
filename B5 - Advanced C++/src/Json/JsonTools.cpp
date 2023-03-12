#include <Json/JsonTools.hpp>
#include <fstream>
#include <iostream>

/**
 * It reads a json file and returns the json object
 *
 * @param filePath The path to the file you want to read.
 *
 * @return A json object
 */
json JsonTools::getPatternsFromFile()
{
    std::map<int, std::vector<std::vector<int>>> patterns;

    std::ifstream f(PATTERN_ENEMY_GROUP_FILE_PATH);
    json          data = json::parse(f);
    return data;
}
