/*
** EPITECH PROJECT, 2022
** Parser
** File description:
** Parser
*/

#include "../include/Parser.hpp"

Parser::Parser() {}

Parser::~Parser() {}

void Parser::getDataFromFile(std::string file_name)
{
    std::ifstream file(file_name);
    std::string   line;

    if (!file.is_open()) { throw ErrorRead(("Could not open " + file_name)); }
    while (getline(file, line, '\n')) _data.push_back(line);
    _data.remove_if([](std::string line) { return !line.find("#"); });
}

bool Parser::unitializedPart(int line_chipsets, int line_links) const noexcept
{
    bool not_find    = line_links == -1 || line_chipsets == -1;
    bool not_ordered = line_links < line_chipsets;

    return (not_find || not_ordered);
}

int Parser::getLineBeginWith(std::string str) const noexcept
{
    std::list<std::string> data = _data;

    for (size_t i = 0; i < _data.size(); i++) {
        if (!data.front().find(str)) { return i; };
        data.pop_front();
    }
    return -1;
}

void splitStr(std::string str, std::string delimiter, std::vector<std::string> *result)
{
    size_t pos = 0;

    if (delimiter.empty()) { throw Parser::ErrorRead("invalid line: " + str + " " + delimiter); }

    (*result).clear();
    while ((pos = str.find(delimiter)) != std::string::npos) {
        (*result).push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
    (*result).push_back(str);
}

void Parser::parseInto(std::map<std::string, std::unique_ptr<nts::IComponent>> &myMap) const
{
    int                      line_chipsets = getLineBeginWith(".chipsets");
    int                      line_links    = getLineBeginWith(".links");
    int                      index         = 0;
    std::vector<std::string> split;
    std::vector<std::string> split1;
    std::vector<std::string> split2;

    if (unitializedPart(line_chipsets, line_links)) { throw ErrorUnitialiazedPart(); }

    for (auto const &i : _data) {
        splitStr(i, " ", &split);
        if (split.size() >= 2 && (index > line_chipsets && index < line_links - 1)) {
            try {
                myMap.emplace(split[1], std::move(createComponent(split[0])));
            }
            catch (ErrorComponent &e) {
                throw e;
            }
        }
        if (split.size() >= 2 && index > line_links) {
            splitStr(split[0], ":", &split1);
            splitStr(split[1], ":", &split2);
            if (!myMap[split1[0]]) { throw ErrorComponent(split1[0]); }
            if (!myMap[split2[0]]) { throw ErrorComponent(split2[0]); }
            myMap[split1[0]]->setLink(stoi(split1[1]), *myMap[split2[0]], stoi(split2[1]));
        }
        index++;
    }
}