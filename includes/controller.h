//
// Created by wikoj on 13.11.2018.
//

#ifndef FILE_CLIENT_CONTROLLER_H
#define FILE_CLIENT_CONTROLLER_H

#include <string>
#include <thread>
#include <SFML/System.hpp>

#include "utilities.h"

class cmdController{

private:
    bool isRunning;
    void putAllert();
    void putLog();
    void putMessage();
    void parseCommand(std::string);
    void getCommand();

public:
    cmdController(std::string);

};

class guiController{

};


#endif //FILE_CLIENT_CONTROLLER_H
