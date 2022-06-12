/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD11-arthur.decaen
** File description:
** Toy
*/

#include "Picture.hpp"

#ifndef TOY_HPP_
#define TOY_HPP_

class Toy
{
public:
    class Error
    {
    public:
        enum ErrorType
        {
            UNKNOWN,
            PICTURE,
            SPEAK
        };

    private:
        std::string _message;
        std::string _component = "Unknown";

    public:
        ErrorType type;
        ~Error() {}
        Error(std::string msg, std::string cmp, ErrorType err) : _message(msg), _component(cmp), type(err) {}
        char const *what() const noexcept { return _message.c_str(); }
        char const *where() const { return _component.c_str(); }
    };

    enum ToyType
    {
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };

    Toy(){};
    Toy(ToyType, std::string, std::string);
    Toy(Toy const &);
    ~Toy() { delete error; };
    ToyType getType() const { return type; }
    std::string getName() const { return name; }
    void setName(std::string newName) { name = newName; }
    bool setAscii(std::string file);
    std::string getAscii() const { return picture.data; }
    Toy &operator=(Toy const &);
    bool speak(std::string);
    Toy &operator<<(std::string);
    bool speak_es(std::string);
    Error getLastError() const { return *error; }

protected:
    ToyType type = BASIC_TOY;
    std::string name = "toy";
    Picture picture;
    std::string speakBegin = "";
    Error *error = new Error("", "", Error::UNKNOWN);
};

std::ostream &operator<<(std::ostream &stream, Toy &toy);

#endif /* !TOY_HPP_ */
