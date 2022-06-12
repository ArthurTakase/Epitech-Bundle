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
    ~Toy(){};
    ToyType getType() const { return type; }
    std::string getName() const { return name; }
    void setName(std::string newName) { name = newName; }
    bool setAscii(std::string file) { return picture.getPictureFromFile(file); }
    std::string getAscii() const { return picture.data; }
    Toy &operator=(Toy const &);
    bool speak(std::string);
    Toy &operator<<(std::string);

protected:
    ToyType type = BASIC_TOY;
    std::string name = "toy";
    Picture picture;
    std::string speakBegin = "";
};

std::ostream &operator<<(std::ostream &stream, Toy &toy);

#endif /* !TOY_HPP_ */
