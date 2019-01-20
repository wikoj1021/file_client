//
// Created by wikoj on 13.11.2018.
//

#ifndef FILE_CLIENT_CONTROLLER_H
#define FILE_CLIENT_CONTROLLER_H

#include <string>
#include <SFML/System.hpp>
#include <unordered_map>

#include "utilities.h"

class cmdController{

private:
    std::unordered_map<std::string, std::string> arguments;
    bool isRunning;
    void putAllert();
    void putLog();
    void putMessage();
    void parseCommand(std::string);
    void getCommand();


public:
    cmdController(std::string connectionMode, std::unordered_map<std::string, std::string> arguments);

};

class guiController{

};


#endif //FILE_CLIENT_CONTROLLER_H
