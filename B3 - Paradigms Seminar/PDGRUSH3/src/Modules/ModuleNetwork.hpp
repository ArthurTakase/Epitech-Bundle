/*
** EPITECH PROJECT, 2022
** ModuleUser.hpp
** File description:
** ModuleUser
*/

#include "../IMonitorModule.hpp"

#ifndef MODULENETWORK_HPP_
#define MODULENETWORK_HPP_

class ModuleNetwork : public IMonitorModule
{
    private:
        std::string _ip;

    public:
        ModuleNetwork(int x, int y, int height, int width) : IMonitorModule(x, y, height, width)
        {
            _ip = "ipv4: " + readCmd("ip route").substr(12, 13);
            _name = "NETWORK";
        }

        std::string readCmd(std::string command)
        {
            FILE *stream = popen(command.c_str(), "r");
            if (!stream) return "No Connection";
            char buffer[2];
            std::string result = "";
            
            while (!feof(stream))
                if (fgets(buffer, 2, stream)) { result += buffer; }
            return result;
        }

        void display()
        {
            printTitle((" "+ _name + " (n)  ").c_str());
            if (!_isDisplay) {return;}
            printStr("");
            printStr(_ip.c_str());
            printStr("");
            printBottom();
        }

        std::string getContent() { return _ip + "\n"; }

        ~ModuleNetwork() {}
};
#endif /* !MODULENETWORK_HPP_ */
