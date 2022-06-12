/*
** EPITECH PROJECT, 2022
** Parser
** File description:
** Parser
*/

#include "ManagerComponent.hpp"
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <vector>

#ifndef PARSER_HPP_
#define PARSER_HPP_

class Parser {
private:
    std::list<std::string> _data;

public:
    Parser();
    ~Parser();

    void parseInto(std::map<std::string, std::unique_ptr<nts::IComponent>> &) const;
    void getDataFromFile(std::string);

    class ErrorRead : public std::exception {
    private:
        std::string _msg;

    public:
        ErrorRead(std::string err_msg) noexcept : _msg(err_msg){};
        ~ErrorRead() {}

        const char *what() const noexcept override { return _msg.data(); }
    };

    class ErrorUnitialiazedPart : public std::exception {
    private:
        std::string _msg = "One part is not/wrongly initialised";

    public:
        ErrorUnitialiazedPart() noexcept {}
        ~ErrorUnitialiazedPart() {}

        const char *what() const noexcept override { return _msg.data(); }
    };

private:
    int  getLineBeginWith(std::string str) const noexcept;
    bool unitializedPart(int line_chipsets, int line_links) const noexcept;
    // void splitStr(std::string str, std::string delimiter, std::vector<std::string> *result) const;
};

#endif /* !PARSER_HPP_ */
